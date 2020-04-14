#include <stdio.h>
#define PI 3.141592654

double area_of_circle(double radius)
{
    static double largest_area = -1.0;
    double area;

    area = PI * radius * radius;
    printf("The area is %lf\n", area);

    if (area > largest_area)
    {
        printf("This is the largest area so far!\n");
        largest_area = area;
    }
    else if (largest_area > -1.0)
    {
        printf("I've seen bigger circles\n");
    }
    return (area);
}

int main()
{
    area_of_circle(1.0);
    area_of_circle(5.0);
    area_of_circle(2.0);
    return 0;
}

/* 
* a) What is the output of this program?
* b) Why isn't largest_area set to -1.0 the second time the function is called?
* c) When you run the program a second time, will it remember the largest area from the previous run? Why or why not?
*/

/* (a) output:
The area is 3.141593
This is the largest area so far!
The area is 78.539816
This is the largest area so far!
The area is 12.566371
I've seen bigger circles
*/

/* (b) 
Because it is declared as static, meaning it's value will be preserved between function calls.
Therefore, the second time the function was called, its value was 3.141593.
*/

/* (c) 
No, since static variables are only preserved during the proccess. 
After running the program the proccess ends, and the variable is re-initialized 
during the next run. 
*/
