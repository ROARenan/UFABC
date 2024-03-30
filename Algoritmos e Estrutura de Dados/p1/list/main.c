#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

void test_comparacao()
{
    List *milky = create_list();
    insertEnd_list(milky, 44);
    insertEnd_list(milky, 77);
    insertEnd_list(milky, 98);
    insertEnd_list(milky, 14);
    insertEnd_list(milky, 21);
    insertEnd_list(milky, 8);

    print_list(milky);
    printf("\n");
    List *index = create_list();
    insertEnd_list(index, 5);
    insertEnd_list(index, 2);
    insertEnd_list(index, 0);

    list_printElements(milky, index);
    printf("\n");
}

void test_asc_desc(){
    List *milky = create_list();
    insertEnd_list(milky, 1);
    insertEnd_list(milky, 2);
    insertEnd_list(milky, 3);
    insertEnd_list(milky, 7);
    insertEnd_list(milky, 9);
    insertEnd_list(milky, 20);

    print_list(milky);
    printf("\n");

    printf("%d\n", list_isSorted(milky));
}

int main()
{
    List *milky = create_list();
    insertEnd_list(milky, 1);
    insertEnd_list(milky, 1);
    insertEnd_list(milky, 2);
    insertEnd_list(milky, 2);
    insertEnd_list(milky, 3);
    insertEnd_list(milky, 7);
    insertEnd_list(milky, 9);
    insertEnd_list(milky, 3);
    insertEnd_list(milky, 20);
    insertEnd_list(milky, 20);


    print_list(milky);
    printf("\n");

    list_removeDuplicates(milky);

    print_list(milky);
    printf("\n");
    return 0;
}