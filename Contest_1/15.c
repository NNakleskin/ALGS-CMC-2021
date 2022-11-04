#include "stdio.h"


int main(void)
{
    int n;
    scanf("%d", &n);
    
    if(n == 3)
    {
        printf("Yes");
        return 0;
    }
    int x1, y1, x2, y2, x3, y3, a1, a2;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    
    a2 = (x1 * y2 - x2 * y1);
    if((x1 * y2 - x2 * y1) - (x2 * y3 - x3 * y2) >= 0)
    {
        a1 = x2 * y3 - x3 * y2;
        x1 = x3;
        y1 = y3;
        for(int i = 0; i < (n - 3); i++)
        {
            scanf("%d %d", &x2, &y2);
            if(a1 - (x1 * y2 - x2 * y1) >= 0)
            {
                a1 = (x1 * y2 - x2 * y1);
                x1 = x2;
                y1 = y2;
                continue;
            }
            else
            {
                printf("No");
                return 0;
            }
        }
        if((a1 - a2) >= 0)
        {
            printf("Yes");
            return 0;
        }
        else
            printf("No\n");
    }
    else if(((x1 * y2 - x2 * y1) - (x2 * y3 - x3 * y2) <= 0))
    {
        a1 = x2 * y3 - x3 * y2;
        x1 = x3;
        y1 = y3;
        for(int i = 0; i < (n - 3); i++)
        {
            scanf("%d %d", &x2, &y2);
            if(a1 - (x1 * y2 - x2 * y1) <= 0)
            {
                a1 = (x1 * y2 - x2 * y1);
                x1 = x2;
                y1 = y2;
                continue;
            }
            else
            {
                printf("No\n");
                return 0;
            }
        }
        if((a1 - a2) <= 0)
        {
            printf("Yes");
            return 0;
        }
        else
            printf("No\n");
    }
    return 0;
}
