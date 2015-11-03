#include<stdio.h>
#include<math.h>

static double interpolate(double cost, double primary,double secondary)
{
	double tmp;

	if(cost <= secondary - primary)
	{
		printf("In INTERPOLATE() : If condition\n");
		return primary + cost;
	}
	tmp  = primary + secondary;
	  return (tmp + sqrt(pow(tmp,2.0) - 2.0 * (pow(primary,2.0) + pow(secondary,2.0) - pow(cost,2.0))))/2.0; 
}

int main()
{
	double cost = 1.0,pri = 5.0,sec = 6.8;

	double ans = interpolate(cost,pri,sec);

	printf("%f\n",ans);

}
