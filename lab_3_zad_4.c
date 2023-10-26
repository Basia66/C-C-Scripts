#include <stdio.h>
#include <stdlib.h>
int main() {

    size_t n;                   //n=rozmiar tablicy
    scanf("%zu",&n);
    int **t = (int **) malloc (n * sizeof (int *));

    for (size_t i=0;i < n; i++)
    {
        t[i] = (int *) malloc ( n * sizeof (int));
        for (size_t j=0; j < n; j++)
        {
            scanf ("%d",&t[i][j]);
        }
    }

    for (size_t i=0; i<n; i++)
    {
        for (size_t j=0; j<n; j++)
        {
            if (i == j && t[i][j]!=1)
            {
                for (size_t i = 0; i < n; i++) { free(t[i]); }
                free (t);
                printf("0");
                return 0;
            }

            if (i !=j && t[i][j]!=0)
            {
                for (size_t i = 0; i < n; i++) { free(t[i]); }
                free (t);
                printf("0");
                return 0;
            }
        }
    }

    for (size_t i = 0; i < n; i++)
        { free(t[i]);}
    free (t);
    printf("1");
    return 0;
}
