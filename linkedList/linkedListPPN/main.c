#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
    List myList = NULL;
    List list2  = NULL;

    displayList(myList);
    displayList(list2);

    insertFront(&myList, 10);
    displayList(myList);
    displayList(list2);

    insertFront(&myList, 20);
    displayList(myList);
    displayList(list2);

    insertFront(&list2, 35);
    displayList(myList);
    displayList(list2);

    insertRear(&list2, 100);
    displayList(myList);
    displayList(list2);

    deleteRear(&list2);
    displayList(myList);
    displayList(list2);

    insertSorted(&list2, 50);
    displayList(myList);
    displayList(list2);

    insertSorted(&list2, 10);
    displayList(myList);
    displayList(list2);

    insertSorted(&list2, 100);
    displayList(myList);
    displayList(list2);

    insertPosition(&list2, 200, 5);
    displayList(myList);
    displayList(list2);

    insertPosition(&list2, 90, 5);
    displayList(myList);
    displayList(list2);

    insertPosition(&list2, 1, 1);
    displayList(myList);
    displayList(list2);

    deletePosition(&list2, 8);
    displayList(myList);
    displayList(list2);

    deletePosition(&list2, 1);
    displayList(myList);
    displayList(list2);

    return 0;
}
