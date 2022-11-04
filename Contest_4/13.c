#include "stdio.h"

int len(char a[]) // Определение длины строки
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
        count++;
    return count;
}

int min(int a, int b)
{
    if(a > b)
    {
        return b;
    }
    return a;
}

int main(void)
{
    char a[1000001];
    scanf("%s", a);
    int n = len(a), z[n], l = 0, r = 0;;
    for(int i = 0; i < n; i++)
        z[i] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && a[z[i]] == a[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    for(int t = 1; t <= n; t++)
    {
        int indicate = 1;
        for (int i = t; i < n; i += t)
        {
            if (n - i <= t)
            {
                if(z[i] + i != n)
                {
                    indicate = 0;
                }
            }
            else
            {
                if(z[i] < t)
                {
                    indicate = 0;
                }
            }
        }
        if(indicate)
        {
            printf("%d ", t);
        }
    }
    return 0;
}
