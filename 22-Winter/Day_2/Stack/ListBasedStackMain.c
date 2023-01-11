#include <stdio.h>
#include "ListBasedStack.h"

int main (void)
{
    /* Stack initialization */
    Stack stack;
    stack_init(&stack);

    /* Pushing data */
    s_push(&stack, 11);
    s_push(&stack, 22);
    s_push(&stack, 33);
    s_push(&stack, 44);
    s_push(&stack, 55);

    /* Pop data */
    while (!s_is_empty(&stack)) {
        printf("%d\n", s_pop(&stack));
    }

    return 0;
}