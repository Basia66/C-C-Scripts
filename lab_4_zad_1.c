#include <stdio.h>
#include <math.h>

int main()
{
    int n;

    scanf("%d", &n);

    if (n < 0) {
        printf("0");
        return 0;
    }
    else if (n == 0) {
        printf("%.2lf*i", sqrt(2));
        return 0;
    }
    else if (n == 1) {
        printf("%.2lf+%.2lf*i", 38.0, 2+sqrt(2));
        return 0;
    }
    else if ( n > 1)
    {
        double clR = 0.0;                         //clr suma
        double mul = 4.0;                         // mul iloczyn
        double clI = 2+sqrt(2);

        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= i; j++) {
                mul = mul * ((double)j+3.0/((double)j*(double)j));
                //printf ("m=%f",mul);
            }

            printf("%f\n", mul);

            clR = clR + sqrt(i-2)+ (2*pow(i, 5.0))+(pow(3.0, 2.0*i)*mul);
        }

        printf("%.f %.f*i", clR, clI);
    }


}