#include<stdio.h>
#include<stdlib.h>
#define estar_grid_at(grid,ix,iy) (&(grid)->cell[(ix)+(iy)*(grid)->dimx])


typedef struct estar_cell_s
{
    double cost;
    double phi;
    double rhs;
    double key;
    size_t pqi;
    int flags;
    struct estar_cell_s *nbor[5];
    struct estar_cell_s *prop[9];
}estar_cell_t;

typedef struct
{
    estar_cell_t * cell;
    size_t dimx,dimy;
}estar_grid_t;


void estar_grid_init(estar_grid_t *grid,size_t dimx,size_t dimy)
{
    printf("In the function estar_grid_init(): \n");
    printf("The value at the *grid = %d\n",grid);
    size_t ix,iy;
    estar_cell_t *cell;
    estar_cell_t **nbor;

    grid->cell = malloc(sizeof(estar_cell_t)*dimx*dimy);
    printf("The value at grid->cell = %u\n",grid->cell);

    if(NULL == grid->cell)
    {
        printf("Error\n");
    }

    grid->dimx = dimx;
    grid->dimy = dimy;
    printf("The value at grid->dimx = %u\nThe value at grid->dimy = %u\n",grid->dimx,grid->dimy);

    printf("Into the for loop.\n");
    for(ix = 0;ix < dimx ; ++ix)
    {
        for(iy = 0;iy < dimy ; ++iy)
        {
            cell = estar_grid_at(grid,ix,iy);
            printf("The value at cell = %d\n",cell);
            printf("Printing the details for (%d,%d) \n",ix,iy);
            cell->cost = 1.0;
            cell->phi = 100.0;
            cell->rhs = 100.0;
            cell->key = 100.0;
            cell->pqi = 0;
            cell->flags = 0;

            nbor = cell->nbor;
            printf("The value in nbor = %d\n",nbor);

            if (ix > 0)
            {	/* west */
                *(nbor++) = cell - 1;
                printf("west.\n");
            }
            if (ix < dimx - 1)
            {	/* east */
                *(nbor++) = cell + 1;
                printf("east.\n");
            }
            if (iy > 0)
            {	/* south */
                *(nbor++) = cell - dimx;
                printf("south.\n");
            }
            if (iy < dimy - 1)
            {	/* north */
                *(nbor++) = cell + dimx;
                printf("north.\n");
            }
            *nbor = 0;

            nbor = cell->prop;
            printf("The value in nbor = %d\n",nbor);
            if (ix > 0)
            {
                if (iy > 0)
                {		/* south-west */
                    *(nbor++) = cell - 1;
                    *(nbor++) = cell - dimx;
                    printf("South-west.\n");
                }
                if (iy < dimy - 1)
                {	/* north-west */
                    *(nbor++) = cell - 1;
                    *(nbor++) = cell + dimx;
                    printf("north-west.\n");
                }
            }
            if (ix < dimx - 1)
            {
                if (iy > 0)
                {/* south-east */
                    *(nbor++) = cell + 1;
                    *(nbor++) = cell - dimx;
                    printf("South-east.\n");
                }
                if (iy < dimy - 1)
                {	/* north-east */
                    *(nbor++) = cell + 1;
                    *(nbor++) = cell + dimx;
                    printf("north-east.\n");
                }
            }
            *nbor = 0;
        }
    }
}


main()
{
    estar_grid_t estar;
    size_t dimx = 4,dimy = 4;
    printf("The address of estar = %u\n",&estar);
    estar_grid_init(&estar,dimx,dimy);
}
