#ifndef LL_QUEUE_H
#define LL_QUEUE_H

#include <stdbool.h>

typedef struct {
    int id;
    char name[20];
    double price;
} Product;

typedef struct Node {
    Product data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
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
