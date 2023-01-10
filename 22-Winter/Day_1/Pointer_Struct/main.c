/*
Learn about debugging & assertions.
These are basic operations that are crucial for DS (Programming in general).
As your programs get longer and longer maintenance is time-consuming.
Modularity and repairing should be exercised. 
*/

#include <stdio.h>

int main(void)
{
    int input;

    while(1)
    {
        printf("Input number[0 to quit]: ");
        scanf("%d", &input);

        if(input == 0) break;

        if(input % 2 == 0) printf("Even\n");
        if(input % 3 == 0) printf("Odd\n");
    }

    printf("Done!\n");

    return 0;
}