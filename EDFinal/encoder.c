#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define INPUT_FILE 1    // Enter name of input file
#define OUTPUT_FILE 2   // Enter name of output file
#define SHIFT_CHARS 3   // Enter number of characters data should be shifted
#define ENCODE_TEXT 4   // Encode the text
#define PREVIEW_INPUT 5 //Display File
#define QUIT 0          // Quit

char input_file_name[80];  // Keep track of file to be encoded
char output_file_name[80]; // Keep track of output file
int chars_to_shift;        // Keep track of how many chars to shift

int input_file(void);
int output_file(void);
void shift_char(void);
void encode_text(void);
void preview_file(int);
int menu(void);

int main(void)
{
    int choice = menu(); /* get user's first selection */
    int set_input_file = 0;
    int set_output_file = 0;

    while (choice != QUIT)
    {
        switch (choice)
        {
        case INPUT_FILE:
            set_input_file = input_file();
            break;
        case OUTPUT_FILE:
            set_output_file = output_file();
            break;
        case SHIFT_CHARS:
            shift_char();
            break;
        case ENCODE_TEXT:
            encode_text();
            break;
        case PREVIEW_INPUT:
            preview_file(set_input_file);
            break;
        default:
            printf("Oops! An invalid choice slipped through. ");
            printf("Please try again.\n");
        }
        choice = menu(); /* get user's subsequent selections */
    }
}

int menu(void)
{
    char option_text[80];

    printf("Text Encoder Service\n\n");
    printf("1. Enter name of input file\n");
    printf("2. Enter name of output file\n");
    printf("3. Enter number of characters data should be shifted\n");
    printf("4. Encode text\n");
    printf("5. View your selected file\n\n");
    printf("0. Quit this program.\n\n");
    printf("Please enter your choice: ");

    while ((scanf(" %d", &option_text) != 1) /* non-numeric input */
           || (option_text[0] < 0)           /* number too small */
           || (option_text[0] > 5))          /* number too large */
    {
        // fflush(stdin) should not be used, use fgets() instead
        fgets(option_text, sizeof(option_text), stdin);
        printf("That selection isn't valid. Please try again.\n");
        printf("Please enter your choice:  ");
    }
    return (int)option_text[0];
}

int input_file(void) // WORKS
{
    input_file_name[80];
    printf("Please enter the name of your input file: \n");
    scanf("%s", &input_file_name);

    return 1;
}

int output_file(void) // WORKS!
{
    output_file_name[80];
    printf("Please enter the name of your output file: \n");
    scanf("%s", &output_file_name);

    return 1;
}

void encode_text(void) // not yet encoding anything!
{
    FILE *in_file;
    FILE *out_file;
    int i = 0;
    int j;
    char ch[128];
    char a[128][128];

    if (access(input_file_name, F_OK) != -1)
    {
        in_file = fopen(input_file_name, "r");
        while (!feof(in_file))
        {
            fscanf(in_file, "%[^\n]%*c", &ch[i]);
            strcpy(a[i], &ch[i]);
            //printf("\n%s", &ch[i]);
            ++i;
        }
        fclose(in_file);
        j = i;

        out_file = fopen(output_file_name, "w+");
        for (i = 0; i < j; i++)
        {
            fprintf(out_file, a[i]);
            fprintf(out_file, "\n");
            printf("a[%d] = %s\n", i, &a[i]);
        }
        fclose(out_file);
        printf("\nYour file has finished encoding!\n\n");
    }
    else
        printf("ERROR: Could not fine input file\n\n");
}

void preview_file(int name_set)
{
    FILE *my_file;

    if (access(input_file_name, F_OK) != -1)
    {
        my_file = fopen(input_file_name, "r");
        char line[128];
        int lines_printed = 0;

        printf("<<<<< Your file >>>>>\n");
        while (!feof(my_file))
        {
            if (fgets(line, sizeof(line), my_file) && (lines_printed < 10))
            {
                printf("%s", line);
                lines_printed++;
            }
        }
        printf("\n");
        fclose(my_file);
    }
    else
    {
        if (name_set)
            printf("ERROR: Could not find input file\n\n");
        else
            printf("ERROR: You have not yet provided the name for the input file.\n\n");
    }
}

void shift_char(void)
{
    char c[10];
    fgets(c, 10, stdin);
    fgets(c, 10, stdin);
    chars_to_shift = atoi(c);
    printf("Num: %d\n", chars_to_shift);
}