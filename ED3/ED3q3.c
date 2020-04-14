// Write a program that looks for the first number over 100 that is divisible both by 3 and 4.

#include <stdio.h>

int main() 
{
    int i = 100;
    while (i < 200)
    {
        if (i%3 && i%4)
        {
            printf("%d is the first number over 100 that is divisible by 3 AND 4!\n", i);
            break;
        } else if (i%3)
        {
            printf("%d is divisible by 3, but not by 4\n", i);
        } else if (i%4)
        {
            printf("%d is divisible by 4, but not by 3\n", i);
        } else 
        {
            printf("%d is not divisible by 3 or by 4\n", i);
        }
        i++;
    }
    return 0;
}