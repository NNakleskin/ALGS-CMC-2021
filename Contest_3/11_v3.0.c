#include "stdio.h"

int min(int a, int b)
{
    if(a > b)
        return b;
    else
        return a;
    return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    float sum = 0;
    for(int i = 0; i < n; i++)
    {
        float a, b;
        scanf("%f %f", &a, &b);
        sum += a / b;
    }
    printf("%f", sum);
    return 0;
}
