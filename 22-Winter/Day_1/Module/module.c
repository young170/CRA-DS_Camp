/*
Module version of main.c
assert() added.
*/

#include <stdio.h>
#include <assert.h>

void oddeven(int num);

int main (void)
{
    int input;

    while (1)
    {
        printf("Input: ");
        scanf("%d", &input);

        if (input == 0) break;

        oddeven(input);
    }

    printf("Done!\n");

    return 0;
}

void oddeven (int num)
{
    if (num % 2 == 0) {
        printf("Even\n");
        return;
    }
    if (num % 3 == 0) {
        printf("Odd\n");
        return;
    }

    assert (num != num && "oddeven() has an error");
}