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


/**
 * The main function which calls all 
 * needed functions at the appropriate 
 * times and runs the program. The encoder
 * program takes a file as input and encodes
 * it n characters based on user's choice, and 
 * then writes to user in an output file of their choosing. 
 * 
 * @return returns 0 if program exited correctly
 */
int main(void)
{
    // ints to hold whether the i/o file names are set
    int is_set_input_file = 0;
    int is_set_output_file = 0;
    // chars to hold the i/o file names
    char file_name[80];
    char output_file_n[80];
    // The shift amount to encode text with
    int shift_amount = 0;
    // Get user's first selection
    int choice = menu(file_name, output_file_n, shift_amount, is_set_input_file, is_set_output_file);
    // While user doesn't choose to quit
    while (choice != QUIT)
    {
        // Get user's selection
        switch (choice)
        {
            case INPUT_FILE:
                // Set file name and set the is_set value to 1
                is_set_input_file = input_file(file_name);
                break;
            case OUTPUT_FILE:
                // Set file name and set the is_set value to 1
                is_set_output_file = output_file(output_file_n);
                break;
            case SHIFT_CHARS:
                // Set the new shift amount
                shift_amount = shift_char();
                break;
            case ENCODE_TEXT:
                // Call the encode_text method to encode text
                encode_text(file_name, output_file_n, shift_amount, is_set_input_file);
                break;
            case PREVIEW_INPUT:
                // Call the preview_file method to preview file
                preview_file(is_set_input_file, file_name);
                break;
            default:
                printf("FATAL ERROR");
                printf("This should never appear\n");
        }
        //get user's subsequent selections
        choice = menu(file_name, output_file_n, shift_amount, is_set_input_file, is_set_output_file);   
    }

    return 0;
}

/**
 * The menu function displays to the user
 * the current options they have, and scans 
 * for their input, and returns it if valid.
 * 
 * @param file_name char * to the name of the input file
 * @param output_file_n char * to the name of the ouput file
 * @param shift_amount int value of the shifting data amount
 * @param is_set_input_file int value representing whether the input file is set
 * @param is_set_output_file int value representing whether the output file is set
 * @return returns the user's int valid input
 */
int menu(char *file_name, char *output_file_n, int shift_amount, int is_set_input_file, int is_set_output_file)
{
    // char holding user's input
    char option_text[80];

    // Displaying the menu to the user
    printf("Text Encoder Service\n\n");
    // If the input file is set, display it
    if (is_set_input_file)
        printf("1. Enter name of input file (currently \"%s\")\n", file_name);
    // Otherwise display "currently not set"
    else
        printf("1. Enter name of input file (currently not set)\n");
    // If the output file is set, display it
    if (is_set_output_file)
        printf("2. Enter name of output file (currently \"%s\")\n", output_file_n);
    // Otherwise display "currently not set"
    else
        printf("2. Enter name of output file (currently not set)\n");
    // If the shift is set
    if (shift_amount != 0)
        // If shift is positive, display +"shift"
        if (shift_amount < 0)
            printf("3. Enter number of characters data to be shifted (currently %d)\n", shift_amount);
        // Otherwise display "shift"
        else
            printf("3. Enter number of characters data to be shifted (currently +%d)\n", shift_amount);
    // Otherwise display as currently not set
    else
        printf("3. Enter number of characters data to be shifted (currently not set)\n");
    // Show the rest of the menu options
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
        // Display to user their input wasn't valid
        printf("That selection isn't valid. Please try again.\n");
        printf("Your choice:  ");
    }
    // Return the valid input
    return (int)option_text[0];
}

/**
 * The input_file function asks user
 * for the name of their input file
 * and returns 1 to represent that a 
 * value has been set. 
 * 
 * @param file_name char * to the name of the input file
 * @return returns int 1 as a name has been set.
 */
int input_file(char *file_name)
{
    printf("Please enter the name of your input file: \n");
    // Get user's input
    fgets(file_name, 80, stdin);
    printf("\n");
    // Remove trailing characters at the end of the input
    file_name[strcspn(file_name, "\n")] = 0;

    return 1;
}

/**
 * The output_file function asks user
 * for the name of their output file
 * and returns 1 to represent that a 
 * value has been set. 
 * 
 * @param output_file_n char * to the name of the output file
 * @return returns int 1 as a name has been set.
 */ 
int output_file(char *output_file_n)
{
    printf("Please enter the name of your output file: \n");
    // Get user's input
    fgets(output_file_n, 80, stdin);
    printf("\n");
    // Remove trailing characters at the end of the input
    output_file_n[strcspn(output_file_n, "\n")] = 0;

    return 1;
}

/**
 * The shift_char function asks user
 * for the amount of characters to 
 * be shifted when encoding their text.
 * 
 * @return returns the int value of user's input
 */
int shift_char(void)
{
    // Char to hold user's input
    char c[10];
    printf("Enter the amount to be shifted: ");
    // Get user input
    fgets(c, 10, stdin);
    printf("\n");
    // Remove trailing characters at the end of the input
    c[strcspn(c, "\n")] = 0;

    // Return the int input
    return atoi(c);
}

/**
 * The encode_text function encodes the input text
 * shift_amount of data ASCII characters for letters
 * inside your input file and writes it to the output
 * file that the user has chosen. 
 * 
 * @param file_name char * to the name of the input file
 * @param output_file_n char * to the name of the output file
 * @param shift_amount int value of the shifting data amount
 * @param is_set_input_file int value representing whether the input file is set
 */
void encode_text(char *file_name, char *output_file_n, int shift_amount, int is_set_input_file)
{
    // Declaring file structure
    FILE *in_file, *out_file;
    // Declare the string and character indexes
    int string_index = 0, char_index = 0;
    // Declare the arrays to hold the string and characters
    char fileString[128];
    char characters[128][128];
    // If file is valid for access
    if (access(file_name, F_OK) != -1)
    {
        // Open i/o files
        in_file = fopen(file_name, "r");
        out_file = fopen(output_file_n, "w+");
        // Declare int to hold lowercase and uppercase shifts
        int ascii_lower, ascii_higher;
        // While not end of input file
        while (!feof(in_file))
        {
            // Scan next string and store it within file string
            fscanf(in_file, "%[^\n]%*c", &fileString[string_index]);
            // Copy it to the characters array at that index
            strcpy(characters[string_index], &fileString[string_index]);
            // Count the length of the current copied string
            int string_count = strlen(characters[string_index]);
            // Loop over the whole string
            for (char_index = 0; char_index < string_count; char_index++)
            {
                // If positive shift amoaunt
                if (shift_amount > 0)
                {
                    // Run the shifting algorithm
                    ascii_lower = (((characters[string_index][char_index] - 97) + shift_amount) % 26) + 97;
                    ascii_higher = (((characters[string_index][char_index] - 65) + shift_amount) % 26) + 65;
                }
                // If negative shift amount
                else
                {
                    // First conver the negative shift to an equal positive shift
                    shift_amount = 26 - (-shift_amount);
                    // Then run the shifting algorithm
                    ascii_lower = (((characters[string_index][char_index] - 97) + shift_amount) % 26) + 97;
                    ascii_higher = (((characters[string_index][char_index] - 65) + shift_amount) % 26) + 65;
                }
                // If character is a letter
                if (isalpha(characters[string_index][char_index]))
                {
                    // If char is lowercase
                    if (islower(characters[string_index][char_index]))
                    {
                        // Apply the lower data shift
                        fprintf(out_file, "%c", (ascii_lower));
                    }
                    // If char is uppercase
                    else
                    {
                        // Apply the upper data shift
                        fprintf(out_file, "%c", (ascii_higher));
                    }
                }
                // If not a letter
                else
                {
                    // Write out the character as it is
                    fprintf(out_file, "%c", characters[string_index][char_index]);
                }
            }
            // Write the newline character after string is over
            fprintf(out_file, "\n");
            // Increment string index
            ++string_index; 
        }
        // After encoding is done close both files
        fclose(in_file);
        fclose(out_file);
        // Alert use encoding was successfull
        printf("\nYour file was successfully encoded!\n");
        // Freeze screen until input
        garbage_collection();
    }
    // If file could not be accessed
    else
    {
        // If the user set a name for the file
        if (is_set_input_file)
        {
            // Tell user their file could not be found
            printf("\nERROR: Could not find input file \"%s\".\n", file_name);
            // Freeze screen until input
            garbage_collection();
        }
        // If user has not yet set a name
        else
        {
            // Tell user they have not yet set a name
            printf("\nERROR: You have not yet provided the name for the input file.\n");
            // Freeze screen until input
            garbage_collection();
        }
    }
}

/**
 * The preview_file function allows the user
 * to view the first 10 lines of their selected
 * file, if valid and has been set.
 *
 * @param is_set_input_file int value representing whether the input file is set
 * @param file_name char * to the name of the input file
 */
void preview_file(int is_set_input_file, char *file_name)
{
    // Declare file structure
    FILE *my_file;

    // Declare variable to hold garbage
    char garbage[100];

    // If file is valid for access
    if (access(file_name, F_OK) != -1)
    {
        // Open file
        my_file = fopen(file_name, "r");
        // Declare char to hold each line's input
        char line[128];
        // Variable to hold the amount of lines displayed
        int lines_printed = 0;
        printf("Reading file \"%s\"\n", file_name);
        // Display start of previrw
        printf("<<<< START OF PREVIEW >>>>\n");
        // While not yet reached the end of file
        while (!feof(my_file))
        {
            // As long less than 10 lines are printed
            if (fgets(line, sizeof(line), my_file) && (lines_printed < 10))
            {
                // Display the line to the user
                printf("%s", line);
                // Increment lines displayed by 1
                lines_printed++;
            }
        }
        // Display end of preview
        printf("<<<< END OF PREVIEW >>>>\n");
        // Freeze screen until input
        garbage_collection();
        // Close file 
        fclose(my_file);
    }
    // If file is invalid
    else
    {
        // If the user set a name for the file
        if (is_set_input_file)
        {
            // Tell user their file could not be found
            printf("\nERROR: Could not find input file \"%s\".\n", file_name);
            // Freeze screen until input
            garbage_collection();
        }
        // If user has not yet set a name
        else
        {
            // Tell user they have not yet set a name
            printf("\nERROR: You have not yet provided the name for the input file.\n");
            // Freeze screen until input
            garbage_collection();
        }
    }
}

/**
 * Collect input garbage that
 * freezes scrolling so that user
 * is able to see all text that
 * is being displayed.
 */
void garbage_collection(void)
{
    // Ask user to hit enter to continue
    printf("\nHit enter to continue: ");
    // Hold the newline character
    // or whatever else user inputs
    // and garbage it
    char garbage[1024];
    fgets(garbage, 100, stdin);
    printf("\n");
}

//buf[strcspn(buf, "\n")] = 0;