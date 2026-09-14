#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void insertFront(List *list, int item) {
    Node *temp = malloc(sizeof(Node));
    temp->data = item;
    temp->next = *list;
    *list = temp;
}

void insertRear(List *list, int item) {
    Node *temp = malloc(sizeof(Node));
    temp->data = item;
    temp->next = NULL;

    Node **trav;
    for(trav = list; *trav != NULL; trav = &(*trav)->next) {}
    *trav = temp;
}

void insertSorted(List *list, int item) {
    Node *temp = malloc(sizeof(Node));
    temp->data = item;

    Node **trav;
    for(trav = list; *trav != NULL && item > (*trav)->data; trav = &(*trav)->next) {}
    temp->next = *trav;
    *trav = temp;
}

void insertPosition(List *list, int item, int position) {
    if(position >= 1) {
        Node *temp = malloc(sizeof(Node));
        temp->data = item;

        Node **trav = list;
        for(int i = 1; *trav != NULL && i < position; i++, trav = &(*trav)->next) {}
        temp->next = *trav;
        *trav = temp;
    }
}

void deleteFront(List *list) {
    if(*list != NULL) {
        Node *temp = (*list)->next;
        free(*list);
        *list = temp;
    }
}

void deleteRear(List *list) {
    if(*list != NULL) {
        Node **trav;
        for(trav = list; (*trav)->next != NULL; trav = &(*trav)->next) {}
        free(*trav);
        *trav = NULL;
    }
}

void deletePosition(List *list, int position) {
    if(position >= 1) {
        Node **trav = list;
        for(int i = 1; *trav != NULL && i < position; i++, trav = &(*trav)->next) {}
        if(*trav != NULL) {
            Node *temp = (*trav)->next;
            free(*trav);
            *trav = temp;
        }
    }
}

void displayList(List list) {
    printf("{");
    for(Node *trav = list; trav != NULL; trav = trav->next) {
        printf("%5d", trav->data);
    }
    printf("}\n");
}
