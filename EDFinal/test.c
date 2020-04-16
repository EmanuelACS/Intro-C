#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char txt3[] = "This is my third bad cold in 2008.";
    char txt[] = "Wklv lv pb wklug edg frog lq 2008.";
    int shift_n = -3;
    int ascii_lower, ascii_higher;

    for (int i = 0; i < sizeof(txt); i++)
    {
        if (shift_n > 0)
        {
            ascii_lower = (((txt[i] - 97) + shift_n) % 26) + 97;
            ascii_higher = (((txt[i] - 65) + shift_n) % 26) + 65;
        }
        else if (shift_n < 0)
        {
            shift_n = 26 - (-shift_n);
            ascii_lower = (((txt[i] - 97) + shift_n) % 26) + 97;
            ascii_higher = (((txt[i] - 65) + shift_n) % 26) + 65;
        }
        if (isalpha(txt[i]))
        {
            if (islower(txt[i]))
            {
                printf("%c", ascii_lower);
            }
            else
            {
                printf("%c", ascii_higher);
            }
        }
        else
        {
            printf("%c", txt[i]);
        }
    }
    printf("\n");
}