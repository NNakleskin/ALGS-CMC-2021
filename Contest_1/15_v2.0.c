#include "stdio.h"
#include "math.h"

int scal(int a[2], int b[2])
{
    return a[0] * b[1] - a[1] * b[0];
}

int main(void){
    int n;
    char sign = '+';
    int x1[2], x2[2];
    scanf("%d", &n);
    scanf("%d%d", x1, x2);
    if(scal(x1, x2) < 0)
    {
        sign = '-';
    }
    for(int i = 1; i < n; i++)
    {
        if(sign == '+')
        {
            if(scal(x1, x2) < 0)
            {
                printf("No");
                return 0;
            }
        }
        if(sign == '-')
        {
            if(scal(x1, x2) > 0)
            {
                printf("No");
                return 0;
            }
        }
        x1[0] = x2[0];
        x1[1] = x2[1];
        scanf("%d", x2);
    }
    printf("Yes");
    return 0;
}
