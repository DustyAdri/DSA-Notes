#ifndef CURSORBASED_H
#define CURSORBASED_H

#define MAX 15 
#define BLANK 1000

typedef int Pos;

typedef struct {
    int data;
    Pos next;
} SType;

typedef struct {
    SType elems[MAX]; 
    int avail;
} VHeap;

typedef int List;

void initVHeap(VHeap *vh);
int allocSpace(VHeap *vh);
void freeSpace(VHeap *vh, int i);
void visualize(VHeap vh);

void insertFront(VHeap *vh, List *list, int item);
void insertRear(VHeap *vh, List *list, int item);
void insertSorted(VHeap *vh, List *list, int item);
void insertPosition(VHeap *vh, List *list, int item, int position);

void deleteRear(VHeap *vh, List *list);
void deleteFront(VHeap *vh, List *list);
void deletePosition(VHeap *vh, List *list, int position);

void displayList(VHeap vh, List list);
#endif