#include "stdio.h"




int main(void)
{
    int n, mass_str = 0;
    scanf("%d", &n);
    int switch_mass[n][2];
    int a[n], b[n];
    for(int i = 0; i < n; i++) // Заполнение массива перестановки
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) // Правильная последовательность
        b[i] = i + 1;
    
    
    for(int i = 0; i < n; i++)
    {
        switch_mass[mass_str][0] = i;
        switch_mass[mass_str][1] = a[i] - 1;
        mass_str++;

    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        {
            if(switch_mass[i][0] == switch_mass[j][1])
            {
                for(int z = 0; z < 2; z++)
                    switch_mass[j][z] = 0;
            }
        }
    }
    
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < mass_str; j++){
            int c = 0;
            //switcher(switch_mass[j][0], switch_mass[j][1]);
            c = a[switch_mass[j][0]];
            a[switch_mass[j][0]] = a[switch_mass[j][1]];
            a[switch_mass[j][1]] = c;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d ", b[i]);
    
    
    
    return 0;
}




















/*#include "stdio.h"

int main(void)
{
    int n;
    scanf("%d", &n);
    
    int a[n], count;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
    {
        for(int x = i + 1; x < n; x++){
            if(a[i] > a[x])
                count += 1;
        }
    }
    printf("%d", count);
}*/
