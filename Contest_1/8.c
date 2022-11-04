#include <stdio.h>

int main(void)
{
    unsigned int n, k, max = 0, mask, x;
    scanf("%d %d", &n, &k);
    mask = (1 << k) - 1;
    for(int i = 0; i < (33 - k); i++)
    {
        x = (n >> i) & mask;
        if(max < x)
            max = x;
    }
    printf("%d", max);
    return 0;
}

