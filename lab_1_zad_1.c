#include <stdio.h>

int main(void) 
{
	double d, p;
	const double PI = 3.14;
	scanf ("%lf" , &d );
	
	if (d > 0)
	{

	p = ( PI * d * d )/ 4 ; 
	
	printf ("%.2lf ", p);
	}
		
	else
	{
		return 1;
	}
	
	
	return 0;
}