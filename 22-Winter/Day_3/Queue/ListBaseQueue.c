#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void queue_init(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int q_is_empty(Queue * pq)
{
	if(pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void enqueue(Queue * pq, Data data)
{
	Node * new_node = (Node*)malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = data;

	if(q_is_empty(pq))
	{
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
	Node * delNode;
	Data retData;

	if(q_is_empty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return retData;
}

Data q_peek(Queue * pq)
{
	if(q_is_empty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}

void print_queue(Queue * pq)
{
    if(q_is_empty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

    Stack stack;
    stack_init(&stack);

    printf("Order from fron-end of Queue: \n");

    while(!q_is_empty(pq))
    {
        int data = dequeue(pq);

        printf("%d ", data);     // data of node at the front
        s_push(&stack, data);    // push data of node to stack
    }

    printf("\nOrder from rear-end of Queue: \n");
    
    while(!s_is_empty(&stack))
    {
        int data = s_pop(&stack);

        printf("%d ", data);    // data of node at the top
        enqueue(pq, data);      // make new queue from stack
    }

    printf("\n");
}