#include "stdio.h"
#include "math.h"

float len_vec(float a[2], float b[2])
{
    float res;
    res = sqrt((b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]));
    return res;
}
void bis(float a[2], float b[2], float c[2])
{
    float bis_a[2], lambda;
    lambda = len_vec(a, b) / len_vec(a, c);
    bis_a[0] = (b[0] + lambda * c[0]) / (lambda + 1);
    bis_a[1] = (b[1] + lambda * c[1]) / (lambda + 1);
    printf("%.5f %.5f\n", bis_a[0], bis_a[1]);
    return;
}

int main(void)
{
    float a[2], b[2], c[2];
    scanf("%f%f", &a[0], &a[1]);
    scanf("%f%f", &b[0], &b[1]);
    scanf("%f%f", &c[0], &c[1]);
    bis(c, a, b);
    bis(a, b, c);
    bis(b, a, c);
    return 0;
}
