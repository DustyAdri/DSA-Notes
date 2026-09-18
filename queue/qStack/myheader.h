#ifndef MYHEADER_H
#define MYHEADER_H

#define MAX 5

typedef struct {
    int prodID;
    char kopiName[20];
    int size;
    double prodPrice;
} ProductOrder;

typedef struct {
    ProductOrder orders[MAX];
    int front;
    int rear;
} Queue, *QPtr;

void initQueue(QPtr q);
Queue newQueue();
int isEmpty(Queue q);
int isFull(Queue q);

void enqueue(QPtr q, ProductOrder po);
void dequeue(QPtr q);
ProductOrder front(Queue q);

void displayQueue(Queue q);
void displayProduct(ProductOrder po);
ProductOrder newProductOrder(int prodID, char *kopiName, int size, double price);
void stackPush(QPtr q, ProductOrder po);
void stackPop(QPtr q);
void upsizeDrink(QPtr q, int prodID);
Queue filterAndRemoveBySize(QPtr mainQ, int targetSize);

#endif