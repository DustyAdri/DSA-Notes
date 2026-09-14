#ifndef MYLIST_H
#define MYLIST_H
#include <stdbool.h>

typedef int Data;

typedef struct {
    Data *elems;
    int count;
    int size;
} List;

void initList(List *list, int size);
List newList(int size);
void freeList(List *list);

void display(List list);
bool insertFront(List *list, int item);
bool insertRear(List *list, int item);
bool insertAt(List *list, int index, int item);
bool deleteFront(List *list);
bool deleteRear(List *list);
int deleteAllItem(List *list, int item);
int deleteItem(List *list, int item);
bool isInList(List list, int key);
int isFoundAt(List list, int key);

#endif