#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int copy(signed char *destination, signed char *where,  int first, int last) // Копирование куска строки
{
    for(int j = 0; j <= last - first; j++)
    {
        destination[j] = where[last - j - 1];
    }
    return 0;

}

int len(signed char a[]) // Определение длины строки
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
        count++;
    return count;
}

void suff(signed char a[],  signed char b[])
{
    int n = len(a) + len(b) + 1;
    signed char c[2000002];
    copy(c, a, 0, len(a));
    c[len(c)] = '$';
    copy(c + len(a) + 1, b, 0, len(b));
    int res[n];
    res[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = res[i - 1];
        while((c[i] != c[j]) && (j > 0))
        {
            j = res[j - 1];
        }
        if(c[i] == c[j])
        {
            j++;
        }
        res[i] = j;
    }
    printf("%d ", res[n - 1]);
}

int main(void)
{
    signed char a[1000002], b[1000002];
    scanf("%s %s", a, b);
    suff(b, a);
    suff(a, b);
    return 0;
}
