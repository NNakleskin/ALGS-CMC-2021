#include "stdio.h"
#include "math.h"


int main(void)
{
    int n;
    double time_spent;
    scanf("%d", &n);
    float s[n], a[n], v[n], t[n];
    for(int i = 0; i < n; i++)
        scanf("%f", &s[i]);
    for(int i = 0; i < n; i++)
        scanf("%f", &a[i]);
    t[0] = sqrt((2 * s[0]) / a[0]); // Вычисление времени прохождения первого участка
    v[0] = a[0] * t[0];// Вычисление скорости в конце певого участка
    time_spent = t[0]; // Счетчик времени
    for(int i = 0; i < n - 1; i++) // Цикл, считающий время, затраченное на весь путь
    {
        if((a[i + 1] > 0) || (a[i + 1] < 0))  // Если а != 0
        {
            t[i + 1] = ((2 * sqrt(v[i] * v[i] + 2 * a[i + 1] * s[i + 1]) - 2 * v[i]) / (2 * a[i + 1]));
            v[i + 1] = v[i] + a[i + 1] * t[i + 1];
            time_spent += t[i + 1];
        }
        if((a[i + 1] >= 0) && (a[i + 1] <= 0)) // Если а == 0
        {
            v[i + 1] = v[i];
            t[i + 1] = s[i + 1] / v[i + 1];
            time_spent += t[i + 1];
        }
    }
    printf("%.4f\n", time_spent);
    return 0;
}

