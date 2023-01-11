#include <stdio.h>
#include <stdlib.h>
#include "ListBasedStack.h"

void stack_init(Stack* pstack)
{
    pstack->head = NULL;
}

int s_is_empty(Stack* pstack)
{
    if(pstack->head == NULL)    return TRUE;
    else                        return FALSE;
}

void s_push (Stack* pstack, Data data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = pstack->head;		// new node points the head(top)

    pstack->head = new_node;        	// head always points the top node
}

Data s_pop (Stack* pstack)
{
    Data rdata;
    Node *rnode;

    if (s_is_empty(pstack)) {			// stack shouldn't be empty
        printf("Stack Memory Error\n");
        exit(-1);
    }

    rdata = pstack->head->data;			// the data of the node popped
    rnode = pstack->head;				// the node popped

    pstack->head = pstack->head->next;	// the head now points to the second-to-the-top

	free(rnode);						// free the node at the top

    return rdata;
}

Data s_peek (Stack* pstack)
{
    if (s_is_empty(pstack)) {
        printf("Stack Memory Error\n");
        exit(-1);
    }

    return pstack->head->data;			// returns (Data) of the top node
}