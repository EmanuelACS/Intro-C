#include <stdio.h>

int main(void)
{
    FILE *mfl;  
    mfl = fopen("example.txt", "w+");
    fprintf(mfl, "Written using fprintf!\n");
    fprintf(mfl, "And an extra line too!");  
    fclose(mfl); 
    return 0;
}
