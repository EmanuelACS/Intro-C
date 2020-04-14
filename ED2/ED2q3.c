#include <stdio.h>

int main()
{
    double num = 1234.56789;
    // With exactly two decimal places is 
    printf("%.2lf\n", num, num);
    // In a field that is 15 columns wide, mark the beginning and end of the field with / characters
    printf("/%15lf/\n", num);
    // As above, but left-justified
    printf("/%-15lf/\n", num);

    return 0;
}

