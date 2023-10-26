#include <stdio.h>
#include <stdlib.h>
int main() {

    size_t k = 0;
    int sum1 = 0,sum2 = 0;
    scanf("%zu",&k);
    int **t = (int **) malloc (k * sizeof (int *));
    for (size_t i=0;i < k; i++)
    {
        t[i] = (int *) malloc ( k * sizeof (int *));
        for (size_t j=0; j < k; j++)
        {
            scanf ("%d",&t[i][j]);
        }
    }
    for (size_t i=0; i<k; i++)
    {
        for (size_t j=0; j<k; j++)
        {
            if (i%2==0)
            {
                sum1= sum1+t[i][j];
            }

            if (j%2!=0)
            {
                sum2= sum2+t[i][j];
            }
            //printf("%d\t", t[i][j]);
        }
        printf("\n");
    }
    printf ("%d %d",sum2,sum1);
    for (size_t i = 0; i < k; i++)
    {
        free(t[i]);
    }
    free (t);
    return 0;
}