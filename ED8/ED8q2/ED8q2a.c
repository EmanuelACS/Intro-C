/* CHOSEN: Q2a
Write a program that asks the user for a seed value to pass to srand1(),
then generates 1000 random numbers in the range 1-10. Do NOT store or print the numbers,
but do print how many times each number was produced.
Hint: use a small array to keep track of how many times each number appears.
 
To give you some practice with extern and static variables,
type in the rand1() and srand1() functions from the textbook.
You may put them in a separate .c file from the rest of your program, but you don’t have to.
*/

#include <stdio.h>

extern int rand1(void);
extern void srand1(unsigned int seed);

int main(void)
{
    int count;
    unsigned seed;
    int my_int;

    printf("Please enter your choice of seed.\n");
    while (scanf("%u", &seed) == 1)
    {
        // Insert array here so that it will reset after every loop
        int keep_track[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        srand1(seed); // reset seed
        // Generate 1000 rand ints
        for (count = 0; count < 1000; count++)
        {
            my_int = rand1();
            keep_track[my_int-1]++;
        }
        // Display results
        for (int j = 0; j < 10; j++)
        {
            printf("%d occured %d times\n", (j+1), keep_track[j]);
        }
        printf("Please enter the next seed (q to quit):\n");
    }
    printf("Done\n");

    return 0;
}
