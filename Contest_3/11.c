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
    float sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) // Нахождение суммы
    {
        float a, b;
        scanf("%f %f", &a, &b);
        sum += a / b;
    }
    int stop_indicate = 0;
    for(float x = 0; x <= 50; x++)
    {
        for (float y = 0; y <= 100; y++)
        {
            for (float z = y + 1; z <= 100; z++)
            {
                if(((x + (y / z)) == sum) && (sim(x, y) == 1))
                {
                    printf("%.f %.f %.f\n", x, y, z);
                    stop_indicate++;
                    break;
                }
            }
            if (stop_indicate == 1)
                break;
        }
        if (stop_indicate == 1)
            break;
    }
    return 0;
}



