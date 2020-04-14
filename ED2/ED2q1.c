#include <stdio.h>

int main()
{
    double num1 = 1234.56789;
    float num2 = 1234.56789;
    printf("%f\n", num1); // 1234.567890
    printf("%f\n", num2); // 1234.567891
    return 0;
}

/* What difference (if any) do you see? 
* Describe a situation in which you would want to use a double variable.
* Describe a situation in which a float variable would be ample. */

// Double is more precise than float at higher numbers of decimals
// When computing multiple math algorithms you would want a higher degree of precision
// When computing simple cash transactions, where two decimals is enough, a float would do the job


