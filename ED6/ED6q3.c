#include <stdio.h>

int sort_two(int *x, int *y);

int main(void)
{
    int num1, num2;
    char str1[15], str2[15];
    int sorted;
    printf("Please enter a number: ");
    gets(str1);
    num1 = atoi(str1);
    printf("%d", num1);

    printf("\nPlease enter another number: ");
    gets(str2);
    num2 = atoi(str2);
    printf("%d", num2);

    sorted = sort_two(&num1, &num2);
    printf("\nYour ordered numbers are: %d %d", num1, num2);

    if (sorted)
        printf("\nYour numbers had to be sorted.");
    else
        printf("\nYour numbers were already sorted.");
    
    
}

int sort_two(int *n, int *m)
{
    int temp;

    if (*n > *m)
    {
        temp = *n;
        *n = *m;
        *m = temp;
        return 1;
    }
    else
        return 0;
}
