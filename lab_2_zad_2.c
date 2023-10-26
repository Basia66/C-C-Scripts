#include <stdio.h>

double pot (double a, int b);

int main()
{
    unsigned int i,j,n;
    double il,su;                                   /* su - suma, il - iloczyn */
    n=0;
    scanf("%u",&n );

    if ( n==0 )
    {return 0;}


    if ( n>1 )
    {
        su = 0.0;
        for (i = 0; i <= n; i++)

        {
            il=4.0;                                               /* wartość początkowa dla j=1 */
            for (j=2; j<=i; j++)                                    /* dla j=0 iloczyn jest nieokreślony */
            {
                printf ("\n j= %u",j);
                il = il * (j + (3 / pot (j,2)));
                printf ("\n il= %f",il);
            }

            su = su + sqrt(i-2) +( 2 * pot (i,3)) * pot (i,2) + (pot (3,(2*i)) * il);
            printf ("\n %f", su);
        }

    }
    else
        return 0;


    printf ("%f", su);


    return 0;
}
double pot (double a, int b)
{
    double p = 1.0;
    int m;
    for ( m=1; m <= b; m++) p = p * a;
    return p;
}

