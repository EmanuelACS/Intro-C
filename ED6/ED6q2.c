/* Write a program that prompts the user to enter 10 double numbers, then displays them back to the user */

#include <stdio.h>

void get_num(double *);

int main(void)
{
    double arr[10];
    printf("Please enter 10 'double' type numbers: \n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%lf", &arr[i]);
    }
    get_num(arr);
    return 0;
}

void get_num(double *arr)
{ 
    int j;    
    printf("Here are all the numbers you have entered: \n");
    for (j = 0; j < 10; j++)
    {
        printf("%d: %lf\n", (j+1), arr[j]);
    }          
}

