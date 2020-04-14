#include <stdio.h>
#define SHOW 1
#define SONG 2
#define QUIT 0

void show(void);
void song(void);
int menu(void);

int main(void)
{
    int choice = menu(); /* get user's first selection */

    while (choice != QUIT)
    {
        switch (choice)
        {
            case SHOW:
                show();
                break;
            case SONG:
                song();
                break;
            default:
                printf("Oops! An invalid choice slipped through. ");
                printf("Please try again.\n");
        }
        choice = menu(); /* get user's subsequent selections */
    }

    printf("Bye bye!\n");

    /* These next 3 lines are helpful if your program doesn't pause to let you
      see the output. (Not required.)
   */
    printf("Press Enter to end the program.\n");
    fflush(stdin);
    getchar();

    return 0;
}

int menu(void)
{
    int option;

    /* Write printf() statements to make the following menu appear on the screen:
       
      Learn more about me! Please select from the menu.
 
      1. Learn the name of my favourite show.
      2. Learn the first line of my favourite song.
 
      0. Quit this program.
 
      Please enter your choice:
   */

    printf("Learn more about me! Please select from the menu.\n\n");
    printf("1. Learn the name of my favourite show.\n");
    printf("2. Learn the first line of my favourite song.\n\n");
    printf("0. Quit this program.\n\n");
    printf("Please enter your choice: ");

    while ((scanf(" %d", &option) != 1) /* non-numeric input */
           || (option < 0)              /* number too small */
           || (option > 2))             /* number too large */
    {
        fflush(stdin); /* clear bad data from buffer */
        printf("That selection isn't valid. Please try again.\n");
        printf("Your choice? ");
    }
    return option;
}

void show(void)
{
    /* Write a printf() statement that will display
      the title of your favourite TV (or stage) show. */
    printf("Stargate SG-1\n");
}

void song(void)
{
    /* Write a printf() statement that will display
      the first line of your favourite song. */
    printf("Old MacDonald had a farm, E-I-E-I-O...\n");
}