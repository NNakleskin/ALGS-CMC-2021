#include "stdio.h"
#include "limits.h"

int min(int a, int b) // Нахождение минимума двух чисел
{
    if (a > b)
        return b;
    else
        return a;
}

int sim(int a, int  b) // Проверка на взаимную простоту двух чисел
{
    if((a == 0) || (b == 0))
        return 1;
    for(int i = min(a, b); i > 0; i--)
    {
        if((a % i == 0) && (b % i == 0))
            return i;
    }
    return 0;
}

int main(void)
{
    int n;
    double a, b, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &a, &b);
        sum += a / b;
    }
    int x; // X - это целая часть суммы
    x = sum;
    sum -= x;
    printf("%d ", x);
    int stop_indicate = 0; // Индикатор завершения
    for(double y = 0; y < 100000; y++) // Перебором ищем подходящие значения дробной части
    {
        for(double z = y + 1; z < 100000; z++)
        {
            if(sim(y, z) == 1)
            {
                int help_sum, help_sum2;
                help_sum = sum * 1000000; // Избегаем сравнения чисел с плавающей точкой
                help_sum2 = y / z * 1000000;// благодаря сравнению значащих
                if(help_sum2 == help_sum)
                {
                    printf("%.lf %.lf\n", y, z);
                    stop_indicate++;
                    break;
                }
            }
        }
        if(stop_indicate == 1)
            break;
    }
    return 0;
}
