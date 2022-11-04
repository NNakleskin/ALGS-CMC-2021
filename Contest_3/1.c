#include "stdio.h"

int euc(int a, int b) { // Алгоритм Евклида
  int c;
  while (b)
  {
     c = a % b;
     a = b;
     b = c;
  }
  return a;
}

int main(void)
{
    int a[4], d1, d2, d3;
    for(int i = 0; i < 4; i++)
        scanf("%d", &a[i]);
    d1 = euc(a[0], a[1]);
    d2 = euc(d1, a[2]);
    d3 = euc(d2, a[3]);
    printf("%d", d3);
    return 0;
}
