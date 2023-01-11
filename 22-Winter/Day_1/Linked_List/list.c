/**
 * @name [CRA] - DS_Camp - Day_1 - Linked_List_Basics
 * @file list.c
 * @author Junhyeon Kim, Seongbin Kim
 * @version 1.0
 * @date 2023-01-10 ~ 2023-01-13
 * 
 * Compile command : gcc -o note driver.c list.c -I../include
 * With arguments  : ./note <arguments>
 * 
 * This file contains the implementations of the functions.
 * Erase "your code here" printf()s and write your code!
 */
#include "list.h"

/*
Just like checking an array, you can check a linked list if it contains an element.
Using the exact same logic, traverse the entire list and if the element is found break!

Return : int : (1) found
				(0) not found
*/
#if 1
int is_contained (char *title)
{
	Header *itr = list.next;
	
	while(itr != NULL) {
		if(strcmp(itr->name, title) == 0)
			return 0;
		else 
			itr = itr->next;
	}

	return 1;
}
#else

int is_contained (char *title)
{
	Header *itr = list.next;
	
	while(itr != NULL) {
		if(strcmp(itr->name, title) == 0)
			return 1;
		else 
			itr = itr->next;
	}

	return 0;
}

int is_contained (char *title)
{
	Header *itr = list.next;
	
    while(itr != NULL) {
		if(!strcmp(itr->name, title)) {
			return 1;
		} else {
			itr = itr->next;
		}
	}

	return 0;
}


int is_contained (char *title)
{
	Header *itr = list.next;

	
	while(itr != NULL){
			
		
		if(strcmp(itr->name, title) == 0){
			return 1;
		}else{
			itr = itr->next;

		}
			
	}

	return 0;
}


int is_contained (char *title)
{
	Header *itr = list.next;

	while (itr != NULL) {
		if(strcmp(itr->name, title) == 0) {
			return 1;
		}else {
			itr ->name;
		}
	}
	

	// 1 을 return 한다. - 발견했기 때문에

	return 1;
}

int is_contained (char *title)
{
	Header *itr = list.next;

	while (itr != NULL){
		if(strcmp(itr->name, title) == 0)
			return 1;
		else
			itr = itr->next;
	}

	return 0;
}
#endif

/*
The current code only lets add a note in the very beginning.
Therefore, overwriting the previous one.
Implement it so that new notes are appended on the end of the note list.
*/
#if 1
void insert_note (char *title)
{
	if (is_contained(title) == 0)
		return 0;

	Header *itr = list.next;
	Header *newNode = (Header *) malloc(sizeof(Header));

	while(itr->next != NULL) 
		itr = itr->next;

	#if 1
	newNode->next = itr->next;
	itr->next = newNode;
	newNode->name = title;
	#else
	itr->next = newNode;
	newNode->name = title;
	newNode->next = NULL;
	#endif
    // printf("\nyour code here\n");
}

// 끝까지 반복문을 돌아서 (마지막에 추가해야하니)
// 마지막 노드의 연결을 새 노드에 하고
// 새 노드의 연결은 NULL
#else

void insert_note (char *title)
{
	// if (is_contained(title) == 0)
	// 	return 0;

	// Header *newNode = (Header *) malloc(sizeof(Header));
	// newNode->name = title;
	// newNode->next = list.next; 
	// list.next = newNode;

	// return 1;

    printf("\nyour code here\n");
}

void insert_note (char *title)
{
	// if (is_contained(title) == 0)
	// 	return 0;

	// Header *newNode = (Header *) malloc(sizeof(Header));
	// newNode->name = title;
	// newNode->next = list.next; 
	// list.next = newNode;

	// return 1;

    printf("\nyour code here\n");
	
	Header *newNode = (Header *) malloc(sizeof(Header));
	Header *itr = list.next;

	while(itr->next != NULL) 
		itr = itr->next;

	newNode->name = title;
	newNode->next = NULL; 
	list.next = newNode;
	
	return 1;
}


void insert_note (char *title)
{
	// if (is_contained(title) == 0)
	// 	return 0;

	// Header *newNode = (Header *) malloc(sizeof(Header));
	// newNode->name = title;
	// newNode->next = list.next; 
	// list.next = newNode;

	// return 1;
	
	

    printf("\nyour code here\n");
}

void insert_note (char *title)
{
	
	if (is_contained(title) == 0)
		return 0;
 
	Header *newNode = (Header *) malloc(sizeof(Header));
	newNode->name = title;
	Header *itr = &list;
	while(1) {
		if(itr->next==NULL) {
			itr->next = newNode;
			newNode->next = NULL;
			break;
		} else {
			itr = itr->next;
		}
	}
	//a -> b -> c ->
	//
	return 1;

    printf("\nyour code here\n");
}




void insert_note (char *title)
{
	if (is_contained(title) == 0)
		return ;

	Header *newNode = (Header *) malloc(sizeof(Header));
	newNode->name = title;
	newNode->next = NULL;
	
	Header* itr = 
	while (itr->next != NULL) {
		itr = itr->next;
	}
	newNode->next = list.next; 
	// list.next = newNode;

	// return 1;
	
	while (list.next != NULL) {
		
	}


    printf("\nyour code here\n");
}


//yoonsuk
void insert_note (char *title)
{
	if (is_contained(title) == 0)
		return 0;

	Header *newNode = (Header *) malloc(sizeof(Header));//생성
	newNode->name = title;
	newNode->next = list.next; 
	
	list.next = newNode;

	return 1;

    printf("\nyour code here\n");
	
}



// hyungjin
void insert_note (char *title)
{
	Header *newNode = (Header *) malloc(sizeof(Header));
	Header *itr = list.next;

	while(itr->next != NULL) {
			itr = itr->next;
	}

	itr->next = newNode;
	newNode->name = title;
	newNode->next = NULL; 

}
#endif

#if 1
void print_notes (void) 
{
	Header *itr = list.next;
	while (itr != NULL) {	// until NULL
		printf("|"); printf(" %s ", itr->name); printf("| --> ");
		itr = itr->next;
	}
	
	printf("NULL\n");
}
#else

//minseop
void print_notes (void) 
{
	Header *itr = list.next;
	while (itr != NULL) {	// until NULL
		printf("|"); printf(" %s ", itr->name); printf("| --> ");
		itr = itr->next;
	}
	
	printf("NULL\n");
}



//yoonsuk
void print_notes (void) 
{
	Header *itr = list.next;
	while (itr != NULL) {	// until NULL// NULL에 도달했을 떄 끝
		printf("|"); printf(" %s ", itr->name); printf("| --> ");
		itr = itr->next;
	}
	
	printf("NULL\n");
}



void print_notes (void) 
{
	Header *itr = list.next;
	while (itr != NULL) {	// until NULL
		printf("|"); printf(" %s ", itr->name); printf("| --> ");
		itr = itr->next;
	}
	
	printf("NULL\n");
}

//hyungjin
void print_notes (void) 
{
	Header *itr = list.next;
	while (itr != NULL) {	// until NULL
		printf("|"); printf(" %s ", itr->name); printf("| --> ");
		itr = itr->next;
	}
	
	printf("NULL\n");
}


void print_notes (void) 
{
	Header *itr = list.next;
	while (itr->next != NULL) {	// until NULL
		printf("|"); printf(" %s ", itr->name); printf("| --> ");
		itr = itr->next;
	}
	
	printf("NULL\n");
}

#endif

/*
Improve the algorithm's time complexity.
Think of the case when the title doesn't exists.

Return - int - 0 : 성공적으로 찾아서 지웠다.
			   1 : 못찾았다.
*/
#if 1
int remove_note (char *title)
{
	Header *itr = list.next;
	for (; itr != NULL; itr = itr->next) {
		if (strcmp(itr->next->name, title) == 0) {	// strcmp(itr->name, title) == 0, next added.
			// node를 지우는 작업, 찾았으니
			
			Header *b = itr->next;
			itr->next = itr->next->next;
			free(b);

			return 0;
		}
	}

	return 1;
}
#else

while(itr != NULL) {
	itr = itr->next;
}
for(;itr != NULL;itr = itr->next)
if (strcmp(itr->next->name, title) == 0)

for ()
if (strcmp(, title) == 0)

for ()
if (strcmp(, title) == 0)

for (itr = &list; itr->next != NULL; itr = itr->next) 
	if (strcmp(itr->next->name, title) == 0)

for ()
if (strcmp(, title) == 0)

#endif

#if 1
/*
Implement clear() that clears the entire note list.
Basic algorithm : repeatedly call remove_note() until the entire list is traversed.
*/

/*
1. 반복문
2. 삭제하는 부분
*/
void clear (void)
{
	// printf("\nyour code here\n");
    Header *itr = list.next;
	Header *save;
	// 마지막에 save는 null을 가리키게 되고, itr은 마지막 노드를 삭제합니다. 그리고 itr = save로, itr도 null을 가리키게 되죠. 이때 반복문을 종료하면 됩니다.
    while (itr != NULL) {        // 이 함수의 목적은 모든 node를 삭제하는 겁니다. 
		save = itr->next;
		DPRINT(printf("DEBUG - %s\n", save->name););

		free(itr);
		itr = save;
    }
}
#else

while (itr != NULL) {        // 이 함수의 목적은 모든 node를 삭제하는 겁니다.



while (itr != NULL) { // 이 함수의 목적은 모든 node를 삭제하는 겁니다.
	save = itr->next;
	DPRINT(printf("DEBUG - %s\n", save->name););
	free(itr);
	itr = save;
}


while (itr != NULL) {
		




#endif

/*
Finds a node corresponding to the title.
Returns the pointer to the found node.
Null if not found.
*/

#if 1
Header* find (char *title)
{
	Header *itr =  (Header *) malloc(sizeof(Header)); // use malloc to preserve it.
	itr = list.next;
	while (itr != NULL) {
		if (strcmp(itr->name, title) == 0) {
			return itr;
		}
	}
	return NULL;
}
#else
// 1. itr에 malloc 해서 stack이 아닌 heap에 저장되도록
// 		Header *itr = (Header *) malloc(sizeof(?));
// 2. 함수가 끝까지 가도록 while 문 조건 작성
//		while(itr != NULL) vs while(itr->next != NULL)
// 3. 현재 node가 찾고 싶은 node인지 확인하는 strcmp
// 		if (strcmp( ? , title) == 0)
// Return
// 찾은 경우 :  itr == (제목이 같은 node의 주소)
// 못찾은 경우 : NULL
Header* find (char *title)
{
	Header *itr =  (Header *) malloc(sizeof(Header)); // use malloc to preserve it.
	itr = list.next;
	while (itr != NULL) {
		if (strcmp(itr->name, title) == 0) {
			return itr;
		}
	}
	return NULL;
}


Header *find (char *title) {
	Header *itr =  (Header *) malloc(sizeof(Header)); // use malloc to preserve it.
	itr = list.next;
	while (itr != NULL) {	// while(itr != NULL) vs while(itr->next != NULL)
		if (!strcmp(itr->name, title)) {
			return itr;
		}
	}

	return NULL;
}



Header* find (char *title)
{
	Header *itr =  (Header*) malloc(sizeof(Header)); // use malloc to preserve it.
	itr = list.next;
	while (itr != NULL) {
		if (strcmp(itr->name, title) == 0) {
			return itr;
		}
	}

	return NULL;
}


Header* find (char *title)
{
	Header *itr =  (Header*) malloc(sizeof(Header));
	itr = &list;
	while (itr != NULL) {
		if (strcmp(itr->name, title) == 0) {
			return ;
		}
	}

	return ;
}



#endif

#if 0	// need a lot of explanation
/*
Traverses and prints the notes recursively.
*/
void print_notes_recursive (Header* head)
{
    if (head == NULL) {
		printf("NULL\n");
       return;
	}
    
	printf("| Name : %s | --> ", head->name);
	// printf("Content : %s\n", head->content->name);

    print_notes_recursive(head->next);
}
#else
#endif

#if 0	// functions for body.
/*
Create a body and link it back to the header.
*/
void create_content (char *title)
{
	Header *temp = find(title);

	if (temp == NULL) {
		printf("Node not found\n");
		return;
	}

	printf("\nyour code here\n");
}

/*
Write content of body that the head points to.
*/
void write_content (char *title)
{
	Header *temp = find(title);

	if (temp == NULL) {
		printf("Node not found\n");
		return;
	}
	
	printf("\nyour code here\n");

}
#else
#endif