/**
 *@name [CRA] - DS_Camp - Day_1 - Linked_List_Basics
 *@file list.c
 *@author Junhyeon Kim, Seongbin Kim
 *@version 1.0
 *@date 2023-01-10 ~ 2023-01-13
 *
 *Compile command : gcc -o note driver.c list.c -I../include
 *With arguments  : ./note "arguments'
 *
 *This file contains the implementations of the functions.
 *Erase "your code here" printf()s and write your code!
 */
#include "list.h"

typedef struct header {
    char *name ;
    struct header *next ;
} Header ;

Header list ;

/*
Just like checking an array, you can check a linked list if it contains an element.
Using the exact same logic, traverse the entire list and if the element is found break!
*/
int is_contained(char *title)
{
	Header *itr = list.next ;

    printf("\nyour code here\n");

	return 1 ;
}

/*
The current code only lets add a note in the very beginning.
Therefore, overwriting the previous one.
Implement it so that (1) new notes are appended on the end of the note list.
                     (2) new notes are inserted in the front, pushing other notes back.
*/
void insert_note(char *title)
{
	// if (is_contained(title) == 0)
	// 	return 0 ;

	// Header *newNode = (Header *) malloc(sizeof(Header)) ;
	// newNode->name = title ;
	// newNode->next = list.next ; 
	// list.next = newNode ;

	// return 1 ;

    printf("\nyour code here\n") ;
}

void print_notes() 
{
	Header *itr = list.next ;
	while (1/*your code here*/) {	// until NULL
		printf("|") ; printf(" %s ", itr->name) ; printf("| --> ") ;
		itr = itr->next ;
	}
	
	printf("NULL\n") ;
}

/*
Improve the algorithm's time complexity.
Think of the case when the title doesn't exists.
*/
int remove_note(char *title)
{
	Header *itr ;
	for (;;/*your code here*/) {	// until NULL
		if (strcmp(itr->next->name, title) == 0) {

			printf("\nyour code here\n");

			return 0 ;
		}
	}

	return 1 ;
}

/*
Implement clear() that clears the entire note list.
Basic algorithm : repeatedly call remove_note() until the entire list is traversed.
*/
void clear() {
	// printf("\nyour code here\n") ;
    Header *itr = list.next ;
	Header *prev;

    while(1) {
		printf("\nyour code here\n");
        DPRINT(printf("DEBUG - %s\n", prev->name) ;) ;
        free(prev) ;
    }
}