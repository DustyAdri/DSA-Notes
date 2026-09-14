#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

List insertFront(List list, int item) {
    Node *temp = malloc(sizeof(Node));
    temp->data = item;
    temp->next = list;
    return temp;
}

List insertRear(List list, int item) {
    Node *temp = malloc(sizeof(Node));
    temp->data = item;
    temp->next = NULL;

    if(list == NULL)
        return temp;

    Node *trav;
    for(trav = list; trav->next != NULL; trav = trav->next) {}
    trav->next = temp;
    return list;
}

List insertSorted(List list, int item) {
    Node *temp = malloc(sizeof(Node));
    temp->data = item;

    if(list == NULL || item <= list->data) {
        temp->next = list;
        return temp;
    }

    Node *trav;
    for(trav = list; trav->next != NULL && item > trav->next->data; trav = trav->next) {}
    temp->next = trav->next;
    trav->next = temp;
    return list;
}

List insertPosition(List list, int item, int position) {
    if(position < 1)
        return list;

    Node *temp = malloc(sizeof(Node));
    temp->data = item;

    if(position == 1) {
        temp->next = list;
        return temp;
    }

    Node *trav = list;
    for(int i = 1; trav != NULL && i < position - 1; i++, trav = trav->next) {}
    temp->next = trav->next;
    trav->next = temp;
    return list;
}

List deleteFront(List list) {
    if(list != NULL) {
        Node *temp = list->next;
        free(list);
        return temp;
    }
    return list;
}

List deleteRear(List list) {
    if(list == NULL)
        return NULL;

    if(list->next == NULL) {
        free(list);
        return NULL;
    }

    Node *trav;
    for(trav = list; trav->next->next != NULL; trav = trav->next) {}
    free(trav->next);
    trav->next = NULL;
    return list;
}

List deletePosition(List list, int position) {
    if(list == NULL || position < 1)
        return list;

    if(position == 1) {
        Node *temp = list->next;
        free(list);
        return temp;
    }

    Node *trav = list;
    for(int i = 1; trav->next != NULL && i < position - 1; i++, trav = trav->next) {}
    if(trav->next != NULL) {
        Node *temp = trav->next->next;
        free(trav->next);
        trav->next = temp;
    }
    return list;
}

void displayList(List list) {
    printf("{");
    for(Node *trav = list; trav != NULL; trav = trav->next) {
        printf("%5d", trav->data);
    }
    printf("}\n");
}
