#include "ListBasedQueue.h"
#include <stdio.h>
#include <stdlib.h>

void queue_init(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int q_is_empty(Queue * pq)
{
	if (pq->front == NULL)	return TRUE;
	// if (pq->rear == NULL)
	else 					return FALSE;
}

void enqueue(Queue * pq, Data data)
{
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;

	if (q_is_empty(pq))
	{
		// 새로 만든 node가 가장 앞이자 뒤다
		pq->front = new_node;
		pq->rear = new_node;
	}
	else
	{
		pq->rear->next = new_node;
		pq->rear = new_node;
	}
}

Data dequeue(Queue * pq)
{
	Data remove_data;
	Node *remove_node;

	if (q_is_empty(pq))
	{
		printf("Memory Error - dequeue()\n");
		exit(-1);
	}

	remove_data = pq->front->data;	// 가장 앞에 있는 node의 data
	remove_node = pq->front;		// 삭제해야 하는 node (가장 앞)

	// 나중에 이 함수를 다시 실행하면, 작동이 안돼요.
	// 이유는, remove_data = pq->front->data인데
	// pq->front가 없어요.
	pq->front = pq->front->next;		// 굳
	// pq->front = remove_node->next;

	free(remove_node);

	return remove_data;
}

Data q_peek(Queue * pq)
{
	if (q_is_empty(pq))
	{
		printf("Memory Error - q_peek()\n");
		exit(-1);
	}

	return  pq->front->data;
}

void print_queue(Queue * pq)
{
	Stack stack;
	stack_init(&stack);

	// 출력
	while(!q_is_empty(pq))
	{
		printf("%d ", pq->front->data);

		// free()가 아니라 stack에 push()
		s_push(&stack, pq->front->data);

		// free()를 한다
		Node *delete = pq->front;
		pq->front = pq->front->next;	// front가 2번째 node 가리킴
		free(delete);					// 가장 앞 node free
	}
	printf("\n");

	// 큐는 비어있고, stack에는 node들이 들어있다.
	// stack을 pop()하면서 큐에 enqueue()
	while(!s_is_empty(&stack))
	{
		int data = s_pop(&stack);	// stack의 값이 담김
		printf("%d ", data);
		enqueue(pq, data);
	}

	printf("\n");
}