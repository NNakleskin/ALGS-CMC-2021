#include "stdio.h"

int main(void)
{
    int a;
    
    scanf("%d", &a);
    
    // Создание и заполнение массива
    int b[a], i;
    
    for (i = 0; i < a; i++)
        scanf("%d", &b[i]);
    

    
    // Нахождение максимума и запоминание номера
    int max = 0, nmax = 0;
    
    for (i = 0; i < a; i++)
    {
        if (max <= b[i]){
            max = b[i];
            nmax = i;
        }
    }

    
    // Нахождение минимума и запоминание номера
    int min = b[0], nmin = 0;
    
    for (i = 0; i < a; i++)
    {
        if (min > b[i]){
            min = b[i];
            nmin = i;
        }
    }

    // Перестановка
    i = 0;
    int s;
    if (nmin > nmax)
    {
        if ((nmin - nmax) % 2 != 0)
        {
            while( i <= ((nmin - nmax) / 2))
            {
                s = b[(nmin - i)];
                b[(nmin -i)] = b[(nmax + i)];
                b[(nmax + i)] = s;
                i++;
            }

        }
        
        
        else
        {
            while ((nmax + i) != (nmin - i))
            {
                s = b[(nmin - i)];
                b[(nmin -i)] = b[(nmax + i)];
                b[(nmax + i)] = s;
                
                i++;
            }
        }
        
    }
    else
    {
        if ((nmax - nmin) % 2 != 0)
        {
            while( i <= ((nmax - nmin) / 2))
            {
                s = b[(nmax - i)];
                b[(nmax -i)] = b[(nmin + i)];
                b[(nmin + i)] = s;
                i++;
            }

        }
        
        
        else
        {
            while ((nmin + i) != (nmax - i))
            {
                s = b[(nmax - i)];
                b[(nmax -i)] = b[(nmin + i)];
                b[(nmin + i)] = s;
                
                i++;
            }
        }
    }
    
    

    // Вывод на экран
    for (i = 0; i<a; i++)
        printf("%d ", b[i]);
    printf("\n");
    
    return 0;
}

