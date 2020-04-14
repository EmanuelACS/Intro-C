#include <stdio.h>

float my_min(float num1, float num2);

int main(void)
{
    float x;
    float y;
    printf("Enter any two numbers: (q to quit)\n");
    while(scanf("%f %f", &x, &y) == 2)
    {
        printf("The lowest between");
        printf(" %f and %f is %f\n", x, y, my_min(x,y));
        printf("Enter any two numbers: (q to quit)\n");
    }
    
    
}

float my_min(float n, float m) {
    float min;

    if (n < m)
        min = n;
    else if (m < n)
        min = m;

    return min;
}