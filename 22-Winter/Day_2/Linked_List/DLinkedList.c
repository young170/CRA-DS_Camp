#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void list_init (List *plist)
{
    plist->head = (Node *) malloc (sizeof(Node));
    plist->head->next = NULL;						// as it is the first pointer there exists no other
    plist->numOfData = 0;							// head is just used as a pointer
}

/* nodes are inserted to the front due to time complexity */
void list_insert (List *plist, LData data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;				// inserting between the head and the first node
    plist->head->next = newNode;					// head now points the new node

    (plist->numOfData)++;							// increase the number of data
													// brackets () added due to the rank of operators
}

int list_first (List *plist, LData *pdata)
{
    if (plist->head->next == NULL)
        return FALSE;
    
    plist->before = plist->head;
    plist->curr = plist->head->next;

    *pdata = plist->curr->data;
    return TRUE;
}

int list_next (List *plist, LData *pdata)
{
    if (plist->curr->next == NULL)
        return FALSE;
    
    plist->before = plist->curr;
    plist->curr = plist->curr->next;

    *pdata = plist->curr->data;
    return TRUE;
}

LData list_remove (List *plist) 
{
    Node *rpos = plist->curr;
    LData rdata = rpos->data;

    plist->before->next = plist->curr->next;
    plist->curr = plist->before;

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int list_count(List *plist)
{
    return plist->numOfData;	// returns (int) the number of data
}

