#include <stdio.h>
double powern (double d, float n) {
    double x = 1.0;
    unsigned j;
    for (j = 1; j <= n; j++)
	x *= d;
    return x;
}

int main (void) {
    double sum = 0.0;
    float i;
    for (i = 1; i <= 1000000; i=i+10)
    {
	sum += powern (i, i / 5);
    }
    printf ("sume = %g\n", sum);
    return 0;
}