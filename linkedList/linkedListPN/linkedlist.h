#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef Node *List;

List insertFront(List list, int item);
List insertRear(List list, int item);
List insertSorted(List list, int item);
List insertPosition(List list, int item, int position);

List deleteFront(List list);
List deleteRear(List list);
List deletePosition(List list, int position);

void displayList(List list);

#endif
