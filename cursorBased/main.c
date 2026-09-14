#include <stdio.h>
#include <stdlib.h>
#include "cursorbased.h"

int main() {
    VHeap vh;
    initVHeap(&vh);
    
    List myList = -1;
    List list2 = -1;
    
    visualize(vh);
    
    displayList(vh, myList);
    displayList(vh, list2);
    
    insertFront(&vh, &myList, 10);
    displayList(vh, myList);
    displayList(vh, list2);
    
    insertFront(&vh, &myList, 20);
    displayList(vh, myList);
    displayList(vh, list2);
    
    insertFront(&vh, &list2, 35);
    displayList(vh, myList);
    displayList(vh, list2);
    
    insertRear(&vh, &list2, 100);
    displayList(vh, myList);
    displayList(vh, list2);
    
    deleteRear(&vh, &list2);
    displayList(vh, myList);
    displayList(vh, list2);
    
    insertSorted(&vh, &list2, 50);
    displayList(vh, myList);
    displayList(vh, list2);
    
    insertSorted(&vh, &list2, 10);
    displayList(vh, myList);
    displayList(vh, list2);
    
    insertSorted(&vh, &list2, 100);
    displayList(vh, myList);
    displayList(vh, list2);
    

    insertPosition(&vh, &list2, 200, 5);
    displayList(vh, myList);
    displayList(vh, list2);

    insertPosition(&vh, &list2, 90, 5);
    displayList(vh, myList);
    displayList(vh, list2);

    insertPosition(&vh, &list2, 1, 1);
    displayList(vh, myList);
    displayList(vh, list2);
    
    deletePosition(&vh, &list2, 8);
    displayList(vh, myList);
    displayList(vh, list2);
    
    deletePosition(&vh, &list2, 1);
    displayList(vh, myList);
    displayList(vh, list2);
    
    visualize(vh);
    
}