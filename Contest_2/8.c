#include "stdio.h"

 int main(void)
{
     int n;
     scanf("%d", &n);
     int a[n], k, count = 0;
     for(int i = 0; i < n; i++) // Заполнение массива
         scanf("%d", &a[i]);
     /*
      1 ≤ i < k < j ≤ N
      k = (i + j) / 2
      ak = (ai + aj) / 2 */
     for(int i = 1; i < n; i++) // Вложенный цикл, подбирающий перебором числа, удовлетворяющие заданным условиям(в т.ч проверка на целочисленность) и увеличивающая счетчик в случае совпадения
     {
         for(int j = i + 1; j <= n; j++)
         {
             k = (i + j) / 2;
             if((i < k) && (k < j) && ((i + j) % 2 == 0))
             {
                 if((a[k - 1] == (a[i - 1] + a[j - 1]) / 2) && (a[i - 1] + a[j - 1]) % 2 == 0)
                     count++;
             }
         }
     }
     printf("%d\n", count);
     return 0;
}
