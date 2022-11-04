#include "stdlib.h"
#include "stdio.h"

int copy(char *destination, char *where,  int first, int last) // Копирование куска строки
{
    for(int j = 0; j <= last - first; j++)
    {
        destination[j] = where[last - j - 1];
    }
    return 0;

}

int main(void)
{
    int a, sum = 0, i = 0;
    char str[2001], op = '+', aa[10000];
    scanf("%s", str);
    while(str[i] != '\0')
    {
        while(str[i] < '0' && str[i] > '9')
        {
            i++;
        }
        int j = i;
        while(str[j] >= '0' && str[j] <= '9')
        {
            j++;
        }
        copy(aa, str, i, j);
        i = j;
        if(op == '+')
        {
            sum += atoi(aa);
        }
        else if(op == '-')
        {
            sum -= atoi(aa);
        }
        else if(op == '*')
        {
            sum *= atoi(aa);
        }
        else if(op == '/')
        {
            sum /= atoi(aa);
        }
        printf("%d", atoi(aa));
        while(str[i] != '+' || str[i] != '-'|| str[i] != '*'|| str[i] != '/')
        {
            i++;
        }
        op = str[i];
        i++;
    }
    return 0;
}
