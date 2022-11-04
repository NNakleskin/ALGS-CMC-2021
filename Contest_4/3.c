#include "stdio.h"

int len(char a[]) // Определение длины строки
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
        count++;
    return count;
}

int main(void)
{
    char a[1000001];
    scanf("%s", a);
    int indicate = 1;
    int n = len(a);
    for(int t = 1; t <= n; t++)
    {
        for(int i = t; i < n; i++)
        {
            if(a[i] != a[i - t])
            {
                indicate--;
                break;
            }
        }
        if(indicate == 1)
        {
            printf("%d ", t);
        }
        indicate = 1;
    }
    return 0;
}
