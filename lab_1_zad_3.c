#include <stdio.h>
#include <math.h>
 
int main(void) 
{
int d,b,a,c;

scanf ("%d %d %d",&a,&b,&c);

if (a ==0 && b==0)
{return 1;}

else if (a == 0)
{
	double x0 =((-c)/b);
printf("%.2lf",x0);
return 0;
}

 d=(b*b)-4*(a*c);

if  (d > 0)
{
  double x1 =((-b+sqrt(d))/(2*a));
  double x2 =((-b-sqrt(d))/(2*a));

printf ("%.2lf %.2lf",x1,x2);
return 0;
}

else if (d == 0)
	{
		double x0 =((-b)/2*a);

printf("%.2lf",x0);
return 0;
	}

else
{
	double xR= (-(double)b)/(2*(double)a);
	double yR= sqrt(-(double)d)/(2*(double)a);
	 
	 printf("%.2lf-%.2lf*i\n%.2lf+%.2lf*i",xR,yR,xR,yR);
}

	return 0;
}