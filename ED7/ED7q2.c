#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    int upper = 0;
    int lower = 0;
    int punctuation = 0;
    int digit = 0;
    int word = 0;
    int inword = 0;

    printf("Hit Ctrl+D to inset EOF\n");

    // Reads to EOF
    while ((ch = getchar()) != EOF)
    {
        int part_of_word = ((isalpha(ch)) || (isdigit(ch)));

        if (isupper(ch))
            upper++;
        else if (islower(ch))
            lower++;
        else if (ispunct(ch))
            punctuation++;
        else if (isdigit(ch))
            digit++;

        if (!part_of_word && !inword)
        {
            inword = 1; // starting a new word
            word++;     // count word
        }
        if (part_of_word && inword)
            inword = 0;
    }

    printf("%d uppercase characters read\n", upper);
    printf("%d lowercase characters read\n", lower);
    printf("%d punctuation characters read\n", punctuation);
    printf("%d digits read\n", digit);
    printf("%d words read\n", word);

    return 0;
}