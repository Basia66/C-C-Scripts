#include <stdio.h>
#include <stdlib.h>
int main() {

    size_t k = 0, w = 0;
    scanf("%zu %zu",&k, &w);
    int **t = (int **) malloc (k * sizeof (int *));
    for (size_t i=0;i < k; i++)
    {
        t[i] = (int *) malloc ( k * sizeof (int *));
        for (size_t j=0; j < k; j++)
        {
            scanf ("%d",&t[i][j]);
        }
    }

    int **t1 = (int **) malloc (w * sizeof (int *));
    for (size_t m=0;m < w; m++)
    {
        t1[m] = (int *) malloc ( w * sizeof (int *));
        for (size_t n=0; n < k; n++)
        {
            scanf ("%d",&t1[m][n]);
        }
    }

    for (size_t i=0; i<k; i++)
    {
        for (size_t j=0; j<k; j++)
        {
            printf("%d ", t[i][j]+t1[i][j]);
        }

        printf("\n");
    }

    for (size_t i = 0; i < w; i++)
    {
        free(t[i]);
        free (t1[i]);
    }
    free (t);
    free (t1);
    return 0;
}