#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "limits.h"

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main(void)
{
    int m, n;
    scanf("%d%d", &n, &m);
    int arr[m][n];
    int res[m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < m; i++)
    {
        res[i] = arr[i][1];
    }
    for(int j = 0; j < n; j += 2)
    {
        for(int i = 0; i < m; i++)
        {
            if(i == 0)
            {
                res[i] += max(arr[i][j], arr[i + 1][j]);
            }
            else if(i == m - 1)
            {
                res[i] += max(arr[i][j], arr[i - 1][j]);
            }
            else
            {
                res[i] += max(max(arr[i][j], arr[i - 1][j]), arr[i + 1][j]);
            }
        }
    }
    int max = 0;
    for(int i = 0; i < m; i++)
    {
        if(res[i] > max)
        {
            max = res[i];
        }
    }
    printf("%d", max);
    
    return 0;
}
