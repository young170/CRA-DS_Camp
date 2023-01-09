/**
 * @name [CRA] - DS_Camp - Day_1 - Linked_List_Basics
 * @file driver.c
 * @author Junhyeon Kim, Seongbin Kim
 * @version 1.0
 * @date 2023-01-10 ~ 2023-01-13
 * 
 * Compile command : gcc -o note driver.c list.c -I../include
 * With arguments  : ./note "arguments'
 * 
 * This file is the driver file of the program.
 * Erase "your code here" printf()s and write your code!
 */

/*
Notice we don't include <stdio.h>.
Isn't it weird? Using "" instead of <> lets you define your own ".h" header file.
When the compiler is given the directory path of the include path,
it copies the contents to the corresponding place.
Check the "list.h" file in ../include directory for further details.
*/
#include "list.h"

/*
These arguments allows us to use the program with command line arguments.
int argc : number of arguments given *the executing argument "./a.out" is also counted.
char *argv[] : string (character array) array of arguments.
*/
int main(/*int argc, char *argv[]*/)
{

    char input ;
	int result ;

    do {

        printf("\nNote - Linked List\n") ;
        printf("\ti - insert\tr - remove\n") ;
        printf("\tc - contains\tp - print\n") ;
        printf("\tx - clear\tq - quit\n") ;

        printf("Command[q to quit]: ") ;
        input = getchar() ;
        result = -1 ;

        /*
        You can see some code are being repeated again and again for each switch-case.
        Try to implement DRY.
        */

        printf("\nyour code here\n\n") ;

        switch(input) {
            case 'i' :
				char insertName[20];
				
                printf("Input note to insert: ") ;
                scanf("%s", insertName) ;
				DPRINT(printf("\nDEBUG - %s\n", insertName) ;) ;

                result = insert_note(insertName) ;

                if (result == 0) 	printf("Name exists in note.\n") ;
                else 				printf("Successfully inserted!\n") ;

                break ;
            case 'c' :
				char containName[20];
				
                printf("Input note to check contains: ") ;
                scanf("%s", containName) ;
                DPRINT(printf("\nDEBUG - %s\n", containName) ;) ;

				result = is_contained(containName) ;

				if (result == 0)	printf("Name exists in note.\n") ;
                else 				printf("Name does not exist in note.\n") ;

                break ;
            case 'r' :
                char removeName[20] ;
				
                printf("Input note to remove: ") ;
                scanf("%s", removeName) ;
				DPRINT(printf("\nDEBUG - %s\n", removeName) ;) ;

				result = remove_note(removeName) ;

				if (result == 0) 	printf("Successfully removed note\n") ;
                else 				printf("Name does not exist in note.\n") ;

                break ;
			case 'p' :
                print_notes() ;

                break ;
			case 'x' :
                clear() ;

                break ;
			case 'q' :
                break ;
            default :
                printf("- Unknown command\n") ;
                continue ;
        }

		result = -1 ;
        getchar() ;

    } while(input != 'q') ;

    clear() ;
    printf("Congratulations~~\n") ;

    return 0 ;

}