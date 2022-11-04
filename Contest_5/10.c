#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"


char max(int* a, int* b)
{
    for(int i = 10000; i >= 0; --i)
    {
        if (a[i] < b[i])
            return 'b';
        else if (a[i] > b[i])
            return 'a';
    }
    return 'a';
}

int num_st(int* res)
{
    int num_start = 20001;
    while((num_start >= 0) && (res[num_start] == 0))
    {
        num_start--;
    }
    return num_start;
}

void outp(int* res)
{
    int was_printed = 0;
    int i = num_st(res);
    while(i >= 0)
    {
        was_printed = 1;
        printf("%d", res[i]);
        i--;
    }
    if(!was_printed)
    {
        printf("0");
    }
}

int len(char a[]) // Определение длины строки
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int copy(int*destination, char*where,  int first, int last) // Копирование куска строки
{
    for(int j = 0; j < last - first; j++)
    {
        destination[j] = where[last - j - 1] - '0';
    }
    return 0;

}

void summ(int* a, int* b)
{
    int* res;
    res = calloc(20002, sizeof(int));
    for(int i = 0; i < 10000; i++)
    {
        int sum_help = a[i] + b[i] + res[i];
        res[i] = sum_help % 10;
        res[i + 1] = sum_help / 10;
    }
    outp(res);
    free(res);
}

void diff(int* a, int* b)
{
    int* res;
    res = calloc(20002, sizeof(int));
    for(int i = 0; i < 10000; i++)
    {
        if (a[i] >= b[i]) {
            res[i] = a[i] - b[i];
            continue;
        }
        res[i] = a[i] - b[i] + 10;
        int j = i + 1;
        while (a[j] == 0) {
            a[j] = 9;
            ++j;
        }
        --a[j];
    }
    outp(res);
}

int zer(int* a)
{
    for(int i = 0; i < 10001; i++)
    {
        if(a[i] != 0)
        {
            return 1;
        }
    }
    return 0;
}

void multi(int* a, int* b)
{
    int* res;
    res = calloc(100002, sizeof(int));
    if((zer(a) == 0) || (zer(b) == 0))
    {
        printf("0");
        return;
    }
    for(int i = 0; i <= 10000; i++)
    {
        int num = 0;
        for(int j = 0; j <= 10000; j++)
        {
            int help_sum = a[j] * b[i];
            res[i + num] += (help_sum % 10);
            res[i + num + 1] += (help_sum / 10);
            num++;
        }
    }
    for(int i = 0; i < 30001; i++)
    {
        int help = res[i];
        res[i] = (help % 10);
        res[i + 1] += (help / 10);
    }
    outp(res);
    free(res);
}

int main(void)
{
    char* x = malloc(200002 * sizeof(char));
    int* a, *b;
    a = calloc(10002, sizeof(int));
    b = calloc(10002, sizeof(int));
    scanf("%s", x);
    int sign_number = 0;
    char sign;
    while((x[sign_number] != '+') && (x[sign_number] != '*') && (x[sign_number] != '-')) // Определение номера знака
        {
        sign_number++;
        }
    sign = x[sign_number];
    copy(a, x, 0, sign_number);
    copy(b, x, (sign_number + 1), len(x));
    if(sign == '+')
    {
        summ(a, b);
    }
    if(sign == '-') // Вычитание
    {
        if(max(a, b) == 'a')
        {
            diff(a, b);
        }
        else
        {
            printf("-");
            diff(b, a);
        }
    }
    if(sign == '*')
    {
        multi(a, b);
    }
    free(x);
    free(a);
    free(b);
    return 0;
}
