#include <stdio.h>
#include "myheader.h"
#include <stdbool.h>
#include <string.h>

Product newProduct (int id, char name[], double price)
{
    Product item;
    item.id = id;
    strcpy(item.name, name);
    item.price = price;
    return item;
}

void initQueue(Queue *q)
{
    q->front = 2;
    q->rear = 2;
}

Queue newQueue()
{
    Queue q;
    q.front = MAX - 1;
    q.rear = MAX - 1;
    return q;
}

bool isEmpty(Queue q)
{
    return q.front == q.rear;
}

bool isFull(Queue q)
{
    return q.front == (q.rear + 1) % MAX;
}

void enqueue(Queue *q, Product item)
{
    if(!isFull(*q))
    {
        q->elems[q->rear] = item;
        q->rear = (q->rear + 1) % MAX;
    }
}

void dequeue(Queue *q)
{
    if(!isEmpty(*q))
    {
        q->front = (q->front + 1) % MAX;
    }
}

Product checkFront(Queue q)
{
    Product item;
    item.id = 9999; // garbage id

    if(!isEmpty(q))
    {
        item = q.elems[q.front];
    }
    return item;
}

void visualize(Queue q)
{
    printf("%10s | %10s | %20s | %10s |\n", "INDEX", "ID", "NAME", "PRICE");
    for(int i = 0; i < MAX; ++i)
    {
        printf("%10d | %10d | %20s | %10.2f |", i, q.elems[i].id, q.elems[i].name, q.elems[i].price);
        if(i == q.front)
        {
            printf("-> FRONT");
        }
        if(i == q.rear)
        {
            printf("-> REAR");
        }
        printf("\n");
    }
}

void display(Queue q)
{
    printf("{");
    while(!isEmpty(q))
    {
        printf("%d - %s - %.2f", checkFront(q).id, checkFront(q).name, checkFront(q).price);
        dequeue(&q);
        if(!isEmpty(q)) 
        {
            printf(", ");
        }
    }
    printf("}\n");
}

