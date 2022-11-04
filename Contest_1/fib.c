#include "stdio.h"

int fib(int n)
{
    if(n != 2)
    {
        return fib(n - 1);
    }
    return fib(n - 1) + fib(n - 2);
}

int main(void)
{
    printf("%d", fib(5));
    return 0;
}
