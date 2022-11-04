#include "stdio.h"

/*Ki = i, если i ≤ 3
 Ki = 2 * Ki + 3, если i нечетное и i > 3
 Ki = 3 + Ki / 2, если i четное и i > 3*/

int rec(int a)
{
    if(a <= 3)
        return a;
    if((a > 3) && (a % 2 != 0))
        return 2 * rec(a + 3);
    if((a > 3) && (a % 2 == 0))
        return 3 + rec(a / 2);
    return 0;
}

int main(void)
{
    int k;
    scanf("%d", &k);
    k = rec(k);
    printf("%d\n", k);
    return 0;
}
