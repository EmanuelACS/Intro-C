#include <stdio.h>

int main()
{
    int userInput;
    printf("Enter an integer: ");
    scanf("%d", &userInput);  

    char character = userInput;
    printf("ASCII code %d corresponds to the character %c.", userInput, character);   

    return 0;
}

