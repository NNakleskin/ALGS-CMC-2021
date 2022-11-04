#include "stdio.h"

void rev(void)
{
    int b;
    scanf("%d", &b);
    if(b == 0)
        return;
    if(b != 0)
    {
        rev();
    }
    printf("%d ", b);
    return;
}

int main(void)
{
    rev();
    return 0;
}
{
    
}

