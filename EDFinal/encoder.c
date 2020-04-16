#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "encoder.h"    

#define INPUT_FILE 1    // Enter name of input file
#define OUTPUT_FILE 2   // Enter name of output file
#define SHIFT_CHARS 3   // Enter number of characters data should be shifted
#define ENCODE_TEXT 4   // Encode the text
#define PREVIEW_INPUT 5 // Display File
#define QUIT 0          // Quit

int main(void)
{
    int set_input_file = 0;
    int set_output_file = 0;
    char file_name[80];
    char output_file_n[80];
    int shift_x = 0;
    int choice = menu(file_name, output_file_n, shift_x, set_input_file, set_output_file, shift_x); /* get user's first selection */

    while (choice != QUIT)
    {
        switch (choice)
        {
        case INPUT_FILE:
            set_input_file = input_file(file_name);
            break;
        case OUTPUT_FILE:
            set_output_file = output_file(output_file_n);
            break;
        case SHIFT_CHARS:
            shift_x = shift_char();
            break;
        case ENCODE_TEXT:
            encode_text(file_name, output_file_n, shift_x);
            break;
        case PREVIEW_INPUT:
            preview_file(set_input_file, file_name);
            break;
        default:
            printf("Oops! An invalid choice slipped through. ");
            printf("Please try again.\n");
        }
        choice = menu(file_name, output_file_n, shift_x, set_input_file, set_output_file, shift_x); /* get user's subsequent selections */
    }
}

int menu(char *file_name, char *output_file_n, int shift_x, int set_input_file, int set_output_file, int shift_set)
{
    char option_text[80];

    printf("Text Encoder Service\n\n");
    if (set_input_file)
        printf("1. Enter name of input file (currently \"%s\")\n", file_name);
    else
        printf("1. Enter name of input file (currently not set)\n");
    if (set_output_file)
        printf("2. Enter name of output file (currently \"%s\")\n", output_file_n);
    else
        printf("2. Enter name of output file (currently not set)\n");
    if (shift_set != 0)
        if (shift_set < 0)
            printf("3. Enter number of characters data to be shifted (currently %d)\n", shift_set);
        else
            printf("3. Enter number of characters data to be shifted (currently +%d)\n", shift_set);
    else
        printf("3. Enter number of characters data to be shifted (currently not set)\n");
    printf("4. Encode text\n");
    printf("5. View your selected file\n\n");
    printf("0. Quit this program.\n\n");
    printf("Please enter your choice: ");

    // Scanning for user's choice
    // Using %*c to strip input of the newline character
    while ((scanf(" %d%*c", &option_text) != 1) /* non-numeric input */
           || (option_text[0] < 0)              /* number too small */
           || (option_text[0] > 5))             /* number too large */
    {
        // Only collect if more than one char was input by user
        if (strlen(option_text) != 1)
            fgets(option_text, sizeof(option_text), stdin);
        printf("That selection isn't valid. Please try again.\n");
        printf("Your choice:  ");
    }
    return (int) option_text[0];
}

int input_file(char *file_name)
{
    printf("Please enter the name of your input file: \n");
    fgets(file_name, 80, stdin);
    printf("Your file is: %s", file_name);
    file_name[strcspn(file_name, "\n")] = 0;

    return 1;
}

int output_file(char *output_file_n)
{
    printf("Please enter the name of your output file: \n");
    fgets(output_file_n, 80, stdin);
    output_file_n[strcspn(output_file_n, "\n")] = 0;

    return 1;
}

int shift_char(void)
{
    char c[10];
    printf("Enter the amount to be shifted: ");
    fgets(c, 10, stdin);
    c[strcspn(c, "\n")] = 0;

    return atoi(c);
}

void encode_text(char *file_name, char *output_file_n, int shift_chars)
{
    FILE *in_file, *out_file;
    int i = 0, k = 0;
    char ch[128];
    char a[128][128];

    if (access(file_name, F_OK) != -1)
    {
        in_file = fopen(file_name, "r");
        out_file = fopen(output_file_n, "w+");
        int ascii_lower, ascii_higher;
        int shift_n = (int)(shift_chars);
        while (!feof(in_file))
        {
            fscanf(in_file, "%[^\n]%*c", &ch[i]);
            strcpy(a[i], &ch[i]);
            int string_count = strlen(a[i]);

            for (k = 0; k < string_count; k++)
            {
                if (shift_n > 0)
                {
                    ascii_lower = (((a[i][k] - 97) + shift_n) % 26) + 97;
                    ascii_higher = (((a[i][k] - 65) + shift_n) % 26) + 65;
                }
                else
                {
                    shift_n = 26 - (-shift_n);
                    ascii_lower = (((a[i][k] - 97) + shift_n) % 26) + 97;
                    ascii_higher = (((a[i][k] - 65) + shift_n) % 26) + 65;
                }
                if (isalpha(a[i][k]))
                {
                    if (islower(a[i][k]))
                    {
                        fprintf(out_file, "%c", (ascii_lower));
                    }
                    else
                    {
                        fprintf(out_file, "%c", (ascii_higher));
                    }
                }
                else
                {
                    fprintf(out_file, "%c", a[i][k]);
                }
            }
            fprintf(out_file, "\n");
            ++i; /* increment string index*/
        }
        fclose(in_file);
        fclose(out_file);
        printf("\nYour file has finished encoding!\n\n");
    }
    else
        printf("ERROR: Could not find input file \"%s\"\n\n", file_name);
}

void preview_file(int name_set, char *file_name)
{
    FILE *my_file;
    if (access(file_name, F_OK) != -1)
    {
        my_file = fopen(file_name, "r");
        char line[128];
        int lines_printed = 0;

        printf("<<<<<<< Your file >>>>>>>\n");
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
            printf("ERROR: Could not find input file \"%s\"\n\n", file_name);
        else
            printf("ERROR: You have not yet provided the name for the input file.\n\n");
    }
}

//buf[strcspn(buf, "\n")] = 0;