#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cursorQueue.h"

static void initPool(Queue *q)
{
    for (int i = 0; i < MAX - 1; i++)
    {
        q->pool[i].next = i + 1;
    }
    q->pool[MAX - 1].next = -1;
    q->avail = 0;
}

Product newProduct(int id, char name[], double price)
{
    Product item;
    item.id = id;
    strcpy(item.name, name);
    item.price = price;
    return item;
}

void initQueue(Queue *q)
{
    initPool(q);
    q->front = -1;
    q->rear = -1;
}

Queue newQueue()
{
    Queue q;
    initPool(&q);
    q.front = -1;
    q.rear = -1;
    return q;
}

bool isEmpty(Queue q)
{
    return q.front == -1;
}

bool isFull(Queue q)
{
    return q.avail == -1;
}

void enqueue(Queue *q, Product item)
{
    if (!isFull(*q))
    {
        int idx = q->avail;
        q->avail = q->pool[idx].next;
        q->pool[idx].data = item;
        q->pool[idx].next = -1;
        if (isEmpty(*q))
        {
            q->front = idx;
            q->rear = idx;
        }
        else
        {
            q->pool[q->rear].next = idx;
            q->rear = idx;
        }
    }
}

void dequeue(Queue *q)
{
    if (!isEmpty(*q))
    {
        int idx = q->front;
        q->front = q->pool[idx].next;
        if (q->front == -1)
        {
            q->rear = -1;
        }
        q->pool[idx].next = q->avail;
        q->avail = idx;
    }
}

Product checkFront(Queue q)
{
    Product item;
    item.id = 9999;
    if (!isEmpty(q))
    {
        item = q.pool[q.front].data;
    }
    return item;
}

void visualize(Queue q)
{
    printf("%10s | %10s | %20s | %10s | %10s |\n", "INDEX", "ID", "NAME", "PRICE", "NEXT");
    for (int i = 0; i < MAX; i++)
    {
        printf("%10d | %10d | %20s | %10.2f | %10d |", i, q.pool[i].data.id, q.pool[i].data.name, q.pool[i].data.price, q.pool[i].next);
        if (i == q.front)
        {
            printf(" -> FRONT");
        }
        if (i == q.rear)
        {
            printf(" -> REAR");
        }
        printf("\n");
    }
}

void display(Queue q)
{
    printf("{");
    int curr = q.front;
    while (curr != -1)
    {
        printf("%d - %s - %.2f", q.pool[curr].data.id, q.pool[curr].data.name, q.pool[curr].data.price);
        curr = q.pool[curr].next;
        if (curr != -1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}
