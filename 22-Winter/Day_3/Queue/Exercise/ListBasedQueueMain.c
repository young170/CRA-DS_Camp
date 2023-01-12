#include <stdio.h>
#include "ListBasedQueue.h"

int main (void)
{
    Queue que;

    queue_init(&que);

    enqueue(&que, 1);
    enqueue(&que, 2);
    enqueue(&que, 3);
    enqueue(&que, 4);
    enqueue(&que, 5);

    while (!q_is_empty(&que))
    {
        int data = dequeue(&que);
        printf("%d ", data);

        // printf("%d", dequeue(&que));
    }
    printf("\n");

    /*
    출력을 하려고 dequeue()를 사용했는데
    NSE
    - No Side Effects

    큐를 보존하는 print() 만든다.
    */
    enqueue(&que, 11);
    enqueue(&que, 22);
    enqueue(&que, 33);
    enqueue(&que, 44);
    enqueue(&que, 55);

    print_queue(&que);

    /*
    11 22 33 44 55
    55 44 33 22 11
    */

    return 0;
}