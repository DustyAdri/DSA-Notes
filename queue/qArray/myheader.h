#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h>
#define MAX 5

typedef struct {
    int id;
    char name[20];
    double price;
} Product;

typedef struct {
    Product elems[MAX];
    int front;
    int rear;
} Queue;

Product newProduct (int id, char name[], double price);
void initQueue(Queue *q);
Queue newQueue();
bool isEmpty(Queue q);
bool isFull(Queue q);
void enqueue(Queue *q, Product item);
void dequeue(Queue *q);
Product checkFront(Queue q);
void visualize(Queue q);
void display(Queue q);

#endif