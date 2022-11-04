#include "stdio.h"

int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]); // Заполнение массива испорченной последовательностью
    int count = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        a[i] = a[i] + count;
        count++;
    }
    for(int i = 0; i < n; i++) // Вывод конечного массива
        printf("%d ", a[i]);
    return 0;
}
