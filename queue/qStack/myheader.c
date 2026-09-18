#include <stdio.h>
#include <string.h>
#include "myheader.h"

void initQueue(QPtr q) {
    q->rear = q->front = MAX - 1;    
}

Queue newQueue() {
    Queue q;
    
    q.front = q.rear = 0;
    
    return q;
}

int isEmpty(Queue q) { return q.front == q.rear; }
int isFull(Queue q) { return (q.rear + 1) % MAX == q.front; }

void enqueue(QPtr q, ProductOrder po) {
    if(!isFull(*q)) {
        q->orders[q->rear] = po;
        q->rear = (q->rear + 1) % MAX;
    }    
}

void dequeue(QPtr q) {
    if(!isEmpty(*q)) {
        q->front = (q->front + 1) % MAX;
    }    
}

ProductOrder front(Queue q) {
    ProductOrder po = newProductOrder(0, "", -1, 0);
    if(!isEmpty(q)) {
        po = q.orders[q.front];
    } 
    return po;
}

void displayQueue(Queue q) {
    printf("{\n");
    while(!isEmpty(q)) {
        displayProduct(front(q));
        dequeue(&q);
        if(!isEmpty(q)) {
            printf(",");
        }
        printf("\n");
    }
    printf("}\n");
}

void displayProduct(ProductOrder po) {
    char sizeName [5][20] = {"Short", "Tall", "Grande", "Venti", "Trenta"};
    printf("%5d | %15s | %-10s | Php %.2f", po.prodID, po.kopiName, sizeName[po.size], po.prodPrice);
}

ProductOrder newProductOrder(int prodID, char *kopiName, int size, double price) {
    ProductOrder po;
    
    po.prodID = prodID;
    strcpy(po.kopiName, kopiName);
    po.size = size;
    po.prodPrice = price;
    
    return po;
}

void stackPush(QPtr q, ProductOrder po)
{
    int count = (q->rear - q->front + MAX) % MAX;
    enqueue(q, po);
    for(int i = 0; i < count; ++i)
    {
        dequeue(q);
        enqueue(q, front(*q));
    } 
}

void stackPop(QPtr q)
{
    dequeue(q);
}

void upsizeDrink(QPtr q, int prodID)
{
    // change sizename by 1
    // add price by 25
    int count = (q->rear - q->front + MAX) % MAX;

    for(int i = 0; i < count; ++i)
    {
        if(prodID == front(*q).prodID && front(*q).prodID < 5)
        {
            q->orders[q->front].prodPrice += 25;
            q->orders[q->front].size += 1;
        }
        dequeue(q);
        enqueue(q, front(*q));
    }
}

Queue filterAndRemoveBySize(QPtr mainQ, int targetSize)
{
    Queue temp;
    initQueue(&temp);
    while (!isEmpty(*mainQ))
    {
        if(targetSize != front(*mainQ).size) // if not the size
        {
            enqueue(&temp, front(*mainQ)); // add to new queue
        }
        dequeue(mainQ);
    }
    return temp;
}


// enqueue new num
// enqueue front until num count and add front and rear