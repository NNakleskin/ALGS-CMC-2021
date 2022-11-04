#include "stdio.h"
#include "stdlib.h"


int main(void)
{
    long long n;
    scanf("%lld", &n);
    long long* m = (long long*) malloc((2 * n * n) * sizeof(long long));
    for(long long i = 0; i < (2 * n * n); i++)
        scanf("%lld", (m + i));
    for(long long i = 0; i < 2 * n; i += 2)
    {
        for(long long j = 0; j < 2 * n * n; j += 2 * n)
        {
            printf("%lld %lld ", m[j + i], (-1 * m[j + 1 + i]));
        }
        printf("\n");
    }
    free(m);
    return 0;
}
