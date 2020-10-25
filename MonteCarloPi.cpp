#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    FILE *fptr;
    fptr = fopen("Piapprox.csv", "w");
    srand(time(0));
    unsigned long int n;
    n = 0;
    double x1 = 0;
    double x, y;
    fprintf(fptr, "N, Pi using Monte Carlo Approximation, Pi\n");
    while (n < 100000000)
    {
        x = ((float)rand()) / ((float)RAND_MAX);
        y = ((float)rand()) / ((float)RAND_MAX);
        if (x * x + y * y <= 1)
        {
            x1++;
        }
        if (n == 999)
            fprintf(fptr, "%d,%.8lg,%f\n", n, (4 * x1 / (double)n), 3.141592);
        else if (n == 9999)
            fprintf(fptr, "%d,%.8lg,%f\n", n, (4 * x1 / (double)n), 3.141592);
        else if (n == 99999)
            fprintf(fptr, "%d,%.8lg,%f\n", n, (4 * x1 / (double)n), 3.141592);
        else if (n == 999999)
            fprintf(fptr, "%d,%.8lg,%f\n", n, (4 * x1 / (double)n), 3.141592);
        else if (n == 9999999)
            fprintf(fptr, "%d,%.8lg,%f\n", n, (4 * x1 / (double)n), 3.141592);
        else if (n == 99999999)
            fprintf(fptr, "%d,%.8lg,%f\n", n, (4 * (x1 / (double)n)), 3.141592);
        n++;
    }
    fclose(fptr);
}
