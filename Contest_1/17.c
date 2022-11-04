#include "stdio.h"

int main(void)
{
    int n, result, a;
    scanf("%d %d", &n, &result);
    for(int i = 0; i < (n - 1); i++)
    {
        scanf("%d", &a);
        result ^= a;
    }
    printf("%d", result);
    return 0;
}
