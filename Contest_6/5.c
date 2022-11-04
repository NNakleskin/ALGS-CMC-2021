#include "stdio.h"


int main(void)
{
    FILE *input = fopen("input.txt", "r");
    long long sum = 0, a;
    char sign = '+';
    while(fscanf(input, "%lld", &a) == 1)
    {
        if(sign == '+')
        {
            sum += a;
        }
        else if(sign == '-')
        {
            sum -= a;
        }
        sign = ' ';
        while(sign == ' ')
        {
            sign = fgetc(input);
        }
    }
    fclose(input);
    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%lld", sum);
    fclose(output);
    return 0;
}

