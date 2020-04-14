#include <stdio.h>

int main(void)
{
    char ch;
    printf("Please enter a, b or anything else: ");
    scanf("%c", &ch);
    int val;
    switch( ch )
    {
        case 'a':
            val = 1;
            printf("passed by a!\n");
        case 'b':
            val = 2;
            printf("passed by b!\n");
            break;
        default:
            val = 26;
            printf("passed by default!\n");
    }
    printf("%d\n", val);
    return 0;
}

// (a)        What will val be if ch was 'A'? 
// (b)        What will val be if ch was 'a'? 
// (c)        What will val be if ch was 'b'? 

/* 
* (a) val = 26 // passed by default!
* (b) val = 2 // passed by a! passed by b!
* (c) val = 2 // passed by b!
*/ 
