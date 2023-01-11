#ifndef __D_LINKED_LIST_H__     // if not defined, first time this file is imported
#define __D_LINKED_LIST_H__     // so that #include files don't overlap

#if 0
#else
#endif

#define TRUE    1
#define FALSE   0

// #include <stdio.h>
// #include <stdlib.h>

typedef int LData;

typedef struct _node 
{
    LData data;
    struct _node* next;
} Node;

typedef struct _linkedList
{
    Node* head;
    Node* curr;
    Node* before;
    int numOfData;
} LinkedList;

typedef LinkedList List;

void list_init (List* plist);                   // initializes linked list
void list_insert (List* plist, LData data);     // inserts new node to the front of the linked list

int list_first (List* plist, LData* pdata);     // the first data of the list
int list_next (List* plist, LData* pdata);      // the next data of the list

LData list_remove (List* plist);                // removes current node from list
int list_count (List* plist);                   // count of nodes in list

#endif