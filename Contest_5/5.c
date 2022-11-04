#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(void)
{
    int l;
    scanf("%d", &l);
    char* x[3];
    x[0] = malloc((l + 1) * sizeof(char));
    x[1] = malloc((l + 1)* sizeof(char));
    x[2] = malloc((l + 1) * sizeof(char));
    scanf("%s", x[0]);
    scanf("%s", x[1]);
    scanf("%s", x[2]);
    printf("%s%s%s", x[2], x[0], x[1]);
    free(x[0]);
    free(x[1]);
    free(x[2]);
    return 0;
}
