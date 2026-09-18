#include <stdio.h>
#include <stdlib.h>
#include "cursorbased.h"

void initVHeap(VHeap *vh) {
    vh->avail = MAX-1;
    for(int i = vh->avail; i >= 0; --i) {
        vh->elems[i].next = i-1;
        vh->elems[i].data = BLANK;
    }    
}

int allocSpace(VHeap *vh) {
    int retVal = vh->avail;
    if(retVal != -1) {
        vh->avail = vh->elems[retVal].next;
    }
    return retVal;
}

void freeSpace(VHeap *vh, int i) {
    if(i != -1 && i < MAX) {
        vh->elems[i].next = vh->avail;
        vh->elems[i].data = BLANK;
        vh->avail = i;
    }    
}

void visualize(VHeap vh) {
    printf("%5s | %5s | %5s\n", "INDEX", "DATA", "NEXT");
    for(int i = 0; i < MAX; ++i) {
        printf("%5d |", i);
        if(vh.elems[i].data != BLANK) {
            printf(" %5d |", vh.elems[i].data);
        } else { 
            printf(" %5s |", "");
        }
        printf(" %5d\n", vh.elems[i].next);
    }
}

void insertFront(VHeap *vh, List *list, int item) {
    if(vh->avail != -1) {
        List temp = allocSpace(vh);
        vh->elems[temp].data = item;
        vh->elems[temp].next = *list;
        *list = temp;
    }
}

void insertRear(VHeap *vh, List *list, int item) {
    if(vh->avail != -1) {
        List temp = allocSpace(vh);
        vh->elems[temp].data = item;
        vh->elems[temp].next = -1;

        List *trav;
        for(trav = list; *trav != -1; trav = &vh->elems[*trav].next) {}
        *trav = temp;
    }
}

void insertSorted(VHeap *vh, List *list, int item) {
    if(vh->avail != -1) {
        List *trav;
        for(trav = list; *trav != -1 && item > vh->elems[*trav].data; trav = &vh->elems[*trav].next) {}
        List temp = allocSpace(vh);
        vh->elems[temp].data = item;
        vh->elems[temp].next = *trav;
        *trav = temp;
    }
}

void insertPosition(VHeap *vh, List *list, int item, int position) {
    if(vh->avail != -1 && position >= 1 && position < MAX) {
        List temp = allocSpace(vh);
        vh->elems[temp].data = item;

        List *trav = list;
        for(int i = 1; *trav != -1 && i < position; i++, trav = &vh->elems[*trav].next) {}
        vh->elems[temp].next = *trav;
        *trav = temp;
    }
}

void deleteFront(VHeap *vh, List *list) {
    if(*list != -1) {
        List temp = vh->elems[*list].next;
        freeSpace(vh, *list);
        *list = temp;
    }
}

void deleteRear(VHeap *vh, List *list) {
    if(*list != -1) {
        List *trav;
        for(trav = list; vh->elems[*trav].next != -1; trav = &vh->elems[*trav].next) {}
        freeSpace(vh, *trav);
        *trav = -1;
    }
}

void deletePosition(VHeap *vh, List *list, int position) {
    if(position >= 1 && position < MAX) {
        List *trav = list;
        for(int i = 1; *trav != -1 && i < position; i++, trav = &vh->elems[*trav].next) {}
        if(*trav != -1) {
            List temp = vh->elems[*trav].next;
            freeSpace(vh, *trav);
            *trav = temp;
        }
    }
}

void displayList(VHeap vh, List list) {
    printf("{");
    while(list != -1) {
        printf("%5d", vh.elems[list].data);
        list = vh.elems[list].next;
    }
    printf("}\n");
}
