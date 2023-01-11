#include <stdio.h>
#include "ListBaseQueue.h"

int main(void)
{
	/* queue create & init */
	Queue q;
	queue_init(&q);

	/* enqueue 5 data */
	enqueue(&q, 1);  enqueue(&q, 2);
	enqueue(&q, 3);  enqueue(&q, 4);
	enqueue(&q, 5);

	/* print all data */
	while(!q_is_empty(&q))
		printf("%d ", dequeue(&q));
    printf("\n");

    /*
    NSE - No Side Effects
    함수는 모듈화를 위해 정해진 역할만 수행해야한다.
    예를 들면, 출력하는 함수면 출력만. 위 예시 처럼 출력과 node를 삭제하는 것이 아니라, 출력만.
    */
    #if 1
    /* enqueue 5 data */
	enqueue(&q, 1);  enqueue(&q, 2);
	enqueue(&q, 3);  enqueue(&q, 4);
	enqueue(&q, 5);

	/* print all data */
	print_queue(&q);
    #endif

	return 0;
}