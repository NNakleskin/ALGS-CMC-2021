#include <stdio.h>

int main(void)
{
    int a, i, z,  sum;
    i = 1;
    z = 1;
    sum = 0;
    scanf("%i", &a);
    while(i <= a)
    {
        while(z <= a)
        {
            sum += (i * z);
            z += 1;
        }
        i += 1;
        z = 1;
    }

    printf("%i\n", sum);
    return 0;

};
