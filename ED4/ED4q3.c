#include <stdio.h>

int main(void)
{
	int max = 100;
	int min = 0;
	int guess = 50;

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with an h if my guess is higher, with an l ");
    printf("\nif my guess is lower or a y if my guess is correct.\n");
    printf("Uh...is your number %d?\n", guess);
    
    char userInput;
	while ((userInput = getchar()) != 'y')
	{
		while (getchar() != '\n');
		if (userInput == 'h')
		{
            max = guess;
		}
		else if (userInput == 'l')
		{
            min = guess;
		}
		guess = (min + max) / 2;
		printf("Well, then, is it %d?\n", guess);
		// If user's number is 100, increment guess after trying 99
		if (guess == 99)
		{
		    guess++;
		}
	}
	printf("I knew I could do it!\n");
	return 0;
}
