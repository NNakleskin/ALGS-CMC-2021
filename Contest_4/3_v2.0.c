#include "stdio.h"
#include "math.h"

int len(char a[]) // Определение длины строки
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
        count++;
    return count;
}
/*
1 ≤ t ≤ |α|
a[i] = a[i - t] для всех t ≤ i < |α|
 */

int main(void)
{
    char a[10001];
    scanf("%s", a);
    int stop_indicate = 0;
    for(int t = 1; t <= len(a); t++)
    {
        for(int i = t; i < len(a); i++)
        {
            if(a[i] != a[i - t])
            {
                stop_indicate++;
                break;
            }
        }
        if(stop_indicate == 0)
        {
            printf("%d ", t);
        }
        stop_indicate = 0;
    }
    return 0;
}
