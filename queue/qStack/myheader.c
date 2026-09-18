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
        ProductOrder temp = front(*q);
        dequeue(q);
        enqueue(q, temp);
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
        ProductOrder temp = front(*q);
        if(prodID == temp.prodID && temp.size < 4)
        {
            temp.prodPrice += 25;
            temp.size += 1;
        }
        dequeue(q);
        enqueue(q, temp);
    }
}

Queue filterAndRemoveBySize(QPtr mainQ, int targetSize)
{
    Queue temp;
    Queue cancelled;
    initQueue(&cancelled);
    initQueue(&temp);
    while (!isEmpty(*mainQ))
    {
        ProductOrder prod = front(*mainQ);
        if(targetSize == prod.size) // if the size
        {
            enqueue(&cancelled, prod); // add to new queue
        }
        else
        {
            enqueue(&temp, prod);
        }
        dequeue(mainQ);
    }

    while (!isEmpty(temp))
    {
        enqueue(mainQ, front(temp));
        dequeue(&temp);
    }

    return cancelled;
}

void insertVIPOrder (QPtr q, ProductOrder vipOrder)
{
    Queue temp;
    // dequeue all non-vips
    // enqueue non-vips to temp queue
    // enqueue ang new viporder orig que
    // enqueue all non-vips back to original
    initQueue(&temp);
    ProductOrder new = front(*q);

    while(new.isVip == 0)
    {
        if(new.isVip != 0)
        {
            enqueue(&temp, new);
        }
        dequeue(q);
        new = front(*q);
    }

    while(!isEmpty(temp))
    {
        ProductOrder new = front(temp);
        enqueue(q, new);
        dequeue(&temp);
    }
}

// enqueue new num
// enqueue front until num count and add front and rear