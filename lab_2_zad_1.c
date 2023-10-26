#include <stdio.h>
int main() {
    double minK, maxK, s;

    scanf("%lf %lf %lf", &minK, &maxK, &s);

    printf("km\t miles\n");

    if (maxK - minK < s) {
        printf("%.2lf\t %.2lf\n", minK, (minK * 0.621371192));
        printf("%.2lf\t %.2lf\n", maxK, (maxK * 0.621371192));
        return 0;
    }
    else {
        for (double i = 0; minK + i * s <= maxK; i++) {
            printf("%.2lf\t %.2lf\n", minK + i * s, (minK + i * s) * 0.621371192);
        }
    }
    return 0;
}