#include <stdio.h>

int main(void)
{
    int user_input;
    printf("Enter an integer: ");
    scanf("%d", &user_input);  

    char character = user_input;
    printf("ASCII code %d corresponds to the character %c\n", user_input, character);   

    return 0;
}

