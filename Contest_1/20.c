#include "stdio.h"
#include "math.h"

int main(void)
{
    double a, b, c, d, d2;
    double sin_alpha;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    
    d2 = c * c + d * d;
    sin_alpha = c / sqrt(d2);
    if (sin_alpha > 1 || sin_alpha < (-1))
        return printf("No");
    if((sin_alpha * sin_alpha * d2) - (2 * c * a * sin_alpha) + (a * a) - (d * d) >= 0){
        if((sin_alpha * sin_alpha * d2) - (2 * d * b * sin_alpha) + (b * b) - (c * c) >= 0)
            printf("YES\n");
    }
    else
       printf("NO\n");
    return 0;
}


