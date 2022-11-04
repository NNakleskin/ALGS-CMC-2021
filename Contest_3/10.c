#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int calc(void)
{
    char str;
    int res = 0;
    scanf("%s",&str);
    if(str == '*')
    {
        res = calc() * calc();
        return res;
    }
    else if(str == '/')
    {
        res = calc() / calc();
        return res;
    }
    else
    {
        res = atoi(&str);
        return res;
    }
    return res;
}

int main(void)
{
    printf("%d", calc());
    return 0;
}
