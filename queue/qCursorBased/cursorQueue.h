#ifndef CURSOR_QUEUE_H
#define CURSOR_QUEUE_H

#include <stdbool.h>
#define MAX 10

typedef struct {
    int id;
    char name[20];
    double price;
} Product;

typedef struct {
    Product data;
    int next;
} CNode;

typedef struct {
    CNode pool[MAX];
    int front;
    int rear;
    int avail;
} Queue;

Product newProduct(int id, char name[], double price);
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
