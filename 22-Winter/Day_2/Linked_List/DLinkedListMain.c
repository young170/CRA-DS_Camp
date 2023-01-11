#include "DLinkedList.h"

int main (void)
{
    /* create & init the list */
    List list;
    int data;
    list_init(&list);

    /* store the five of data */
    /* use alt + sht to copy line */
    list_insert(&list, 11);
    list_insert(&list, 11);
    list_insert(&list, 22);
    list_insert(&list, 22);
    list_insert(&list, 33);

    /* print the number of data */
    printf("The number of data: %d \n", list_count(&list));

    /* print all data */
    if (list_first(&list, &data)) {
        printf("%d ", data);

        while (list_next(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    /* remove all 22 number in the list */
    if (list_first(&list, &data)) {
        if (data == 22)
            list_remove(&list);
        
        while (list_next(&list, &data)) {
            if (data == 22)
                list_remove(&list);
        }
    }

    /* after the removal, print the number of remaining data */
    printf("The number of data: %d \n", list_count(&list));

    /* after the removal, print all remaining data */
    if (list_first(&list, &data)) {
        printf("%d ", data);

        while (list_next(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    
    return 0;
}