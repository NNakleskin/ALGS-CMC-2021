#include "stdio.h"

int max(int a, int b) // Нахождение минимума двух чисел
{
    if (a < b)
        return b;
    else
        return a;
}

int main(void)
{
    int n, sum = 0;
    scanf("%d", &n);
    int a[n], b[n];
    for(int i = 0; i < n; i++) // Ввод а последовательности
        scanf("%d", &a[i]); //
    for(int i = 0; i < n; i++) // Ввод б последовательности
        scanf("%d", &b[i]); //
    
    for(int i = 0; i < n; i++) // Нахождение количество видимых ящиков
    {
        sum += max(a[i], b[i]);
    }
    printf("%d", sum); // Вывод суммы
    return 0;
}
