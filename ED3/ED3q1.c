#include <stdio.h>

int main()
{
    int userInput;
    printf("Pick a number: ");
    scanf("%d", &userInput);
    int lessFive = userInput - 5;
    printf("Let me count backwards.... ");
    for (int i = userInput; i >= lessFive; i--)
    {
        printf("%d ", i);
    }
    printf("\nGot it! %d - 5 is %d", userInput, lessFive);
    return 0;
}