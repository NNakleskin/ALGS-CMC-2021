#include <stdio.h>

int main(void){
    int n, i, a, pred = 0, count = 1, count2 = 0;
    
    scanf("%d %d", &n, &pred);
    for(i = 0; i < (n - 1); i++){
        scanf("%d", &a);
        if(a > pred)
            count++;
        if(count > count2)
            count2 = count;
        if(a <= pred)
            count = 1;
        pred = a;
    }
    if(count > count2)
        count2 = count;
    printf("%d\n", count2);
}
