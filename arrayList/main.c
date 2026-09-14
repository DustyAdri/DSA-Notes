#include "MYLIST.H"
#include <stdio.h>

int main ()
{
    printf("=== 1. INITIALIZING LIST ===\n");
    List list = newList(6);
    display(list);

    printf("\n=== 2. TESTING INSERTIONS ===\n");
    insertRear(&list, 20);
    insertRear(&list, 30);
    display(list); //  20 30 

    insertFront(&list, 10);
    display(list); // 10 20 30

    insertAt(&list, 1, 15); // Insert 15 at index 1
    display(list); //  10 15 20 30 

    insertRear(&list, 20); // Add duplicate for deletion tests
    insertRear(&list, 20);
    display(list); //  10 15 20 30 20 20 

    printf("\nTesting overflow (capacity 6 full):\n");
    bool overflowResult = insertRear(&list, 99);
    printf("Insert on full list status: %s\n", overflowResult ? "Success" : "Failed (Expected)");

    printf("\n=== 3. TESTING SEARCH & LOOKUP ===\n");
    printf("Is 15 in list? %s\n", isInList(list, 15) ? "Yes" : "No");
    printf("Is 99 in list? %s\n", isInList(list, 99) ? "Yes" : "No");
    printf("Index of 30: %d\n", isFoundAt(list, 30));
    printf("Index of 99: %d\n", isFoundAt(list, 99));

    printf("\n=== 4. TESTING DELETIONS ===\n");
    deleteFront(&list);
    printf("After deleteFront: ");
    display(list); //  15 20 30 20 20 

    deleteRear(&list);
    printf("After deleteRear: ");
    display(list); //  15 20 30 20 

    deleteItem(&list, 30);
    printf("After deleteItem(30): ");
    display(list); //  15 20 20 

    printf("\n=== 5. TESTING DELETE ALL OCCURRENCES ===\n");
    int removed = deleteAllItem(&list, 20);
    printf("Removed %d occurrence(s) of 20.\n", removed);
    printf("After deleteAllItem(20): ");
    display(list); //  15 

    printf("\n=== 6. CLEANUP ===\n");
    freeList(&list);
    printf("Memory freed successfully.\n");

    return 0;
}