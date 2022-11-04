#include "stdio.h"
#include "limits.h"

int main(void)
{
    unsigned int a11, a12, a21, a22, b1, b2, x, y;
    scanf("%d %d %d %d %d %d", &a11, &a12, &a21, &a22, &b1, &b2);
    for(x = 0; x < UINT_MAX / 10000; x += 2)
    {
        for(y = 0; y < UINT_MAX / 10000; y++)
        {
            if(((a11 & x) ^ ((a12 & y) == b1)) && ((a21 & x) ^ ((a22 & y) == b2)))
            {
                printf("YES\n");
                return printf("%d %d\n", x, y);
            }
            if(((a11 & (x+1)) ^ ((a12 & y) == b1)) && ((a21 & (x+1)) ^ ((a22 & y) == b2)))
            {
                printf("YES\n");
                return printf("%d %d\n", x, y);
            }
        }
    }
    printf("NO\n");
    return 0;
}
