/**
 * @name [CRA] - DS_Camp - Day_1 - Linked_List_Basics
 * @file list.h
 * @author Junhyeon Kim, Seongbin Kim
 * @version 1.0
 * @date 2023-01-10 ~ 2023-01-13
 * 
 * Compile command : gcc -o note driver.c list.c -I../include
 * With arguments  : ./note "arguments'
 * 
 * This file includes dependecies for the other files.
 * Set its include directory path to enable the compiler to access it.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
#ifdef option can be activated with the command line option "-D".
For this case the option would be "-DDEBUG".
Would it better to name the option "EBUG"?

#define replaces the statement on the left with the one on the right.
This process is done before building the executable file.
Simply, if DEBUG is defined all functions surrounded with the DPRINT() will be activated.
*/
#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

/*
In the code you will see the following.
These flags are very useful so you should learn them!
If the flag #if is off (0), everything between #if 0 ~ #else is unaccessible. While #else ~ #endif is activated.
If the flag #if is on (1), the opposite of the above happens.
*/
#if 0
#else
#endif

int is_contained(char *title) ;
int insert_note(char *title) ;
void print_notes() ;
int remove_note(char *title) ;
void clear() ;