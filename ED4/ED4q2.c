#include <stdio.h>
#include <ctype.h>

int get_int(void); /* validate that input is an integer */

int main(void)
{
    printf("Enter some integers. When you are done, enter 0 (zero)\n");
    int getInput = get_int();
    while (getInput != 0)
    {
        printf("I got the number %d.\n", getInput);
        getInput = get_int();
    }
    return 0;
}


int get_int(void)
{
    int input;
    char ch;
    char str = "";
    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) == (isspace(ch)))
        {
            putchar(ch);
        }
        if ((ch != isspace(ch)))
        {
            str += ch;
        }
        printf("%c is not an integer\n", str);
        str = "";
    }
    return input;
}