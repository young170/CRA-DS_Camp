/*
Module version of main.c
assert() added.
*/

#include <stdio.h>
#include <assert.h>

void even(int num);
void odd(int num);

int main(void)
{
    int input;

    while(1)
    {
        printf("Input: ");
        scanf("%d", &input);

        if(input == 0) break;

        even(input);
        odd(input);
    }

    printf("Done!\n");

    return 0;
}

void even(int num)
{
    if(num % 2 == 0) {
        printf("Even\n");
        return;
    }

    assert(num != num && "even() has an error");
}

void odd(int num)
{
    if(num % 3 == 0){
        printf("Odd\n");
        return;
    }

    assert(num != num && "odd() has an error");
}