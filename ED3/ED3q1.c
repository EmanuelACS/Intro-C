#include <stdio.h>

int main(void)
{
    int user_input;
    printf("Pick a number: ");
    scanf("%d", &user_input);
    int lessFive = user_input - 5;
    printf("Let me count backwards.... ");
    for (int i = user_input; i >= lessFive; i--)
    {
        printf("%d ", i);
    }
    printf("\nGot it! %d - 5 is %d\n", user_input, lessFive);

    return 0;
}