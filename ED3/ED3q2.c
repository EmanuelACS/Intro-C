#include<stdio.h>
 
int main(void)
{
    int i,j;
    
    // Loop 5 times
    for(i = 0; i < 5; i++)
    {
        // Loop one less time after each outer loop
        for(j = 0; j < 5 - i; j++)
        {
            // ASCII 64 = A
            // Convert int to char
            printf("%c", (char)(j + 65));
        }
        printf("\n");
    }
    return 0;
}