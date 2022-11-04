#include "stdio.h"
unsigned f(unsigned x)
{
    long long s = 0;
    unsigned i;
    for (i = 0; s <= x; i++)
    {
        s += 2 * i + 1;
    }
    return x * (i - 1);
}
unsigned f_help(unsigned x)
{
    long long s = 0;
    unsigned i;
    for (i = 0; s <= x; i++)
    {
        s += 2 * i + 1;
    }
    return i;
}

unsigned g(unsigned x)
{
    long long s = x;
    unsigned i;
    for (i = f_help(x); s >= 0; i--)
    {
        s -= 2 * i + 1;
    }
    return x / (i - 1);
    return 0;
}

int main(void)
{
    printf("%d", f(g(10)));
    return 0;
}
