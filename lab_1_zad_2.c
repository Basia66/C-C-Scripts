#include <stdio.h>

int main(void) 
{
	int liczbaA, liczbaB, liczbaC;
	scanf("%d %d %d" , &liczbaA, &liczbaB, &liczbaC);
	
	int M;
	
	if (liczbaA>liczbaB)
	{
		M=liczbaA;
	}
		
	else
	{
		M=liczbaB;
	}
	
	if (liczbaC>M)
	{
		M=liczbaC;
	}
	
	printf ("%d", M);
	
	return 0;
}
