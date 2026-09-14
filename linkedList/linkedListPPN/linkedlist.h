#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef Node *List;

void insertFront(List *list, int item);
void insertRear(List *list, int item);
void insertSorted(List *list, int item);
void insertPosition(List *list, int item, int position);

void deleteFront(List *list);
void deleteRear(List *list);
void deletePosition(List *list, int position);

void displayList(List list);

#endif
