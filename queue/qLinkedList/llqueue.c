#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "llqueue.h"

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
    q->front = NULL;
    q->rear = NULL;
}

Queue newQueue()
{
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}

bool isEmpty(Queue q)
{
    return q.front == NULL;
}

bool isFull(Queue q)
{
    return false;
}

void enqueue(Queue *q, Product item)
{
    Node *node = malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;
    if (isEmpty(*q))
    {
        q->front = node;
        q->rear = node;
    }
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
}

void dequeue(Queue *q)
{
    if (!isEmpty(*q))
    {
        Node *temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        free(temp);
    }
}

Product checkFront(Queue q)
{
    Product item;
    item.id = 9999;
    if (!isEmpty(q))
    {
        item = q.front->data;
    }
    return item;
}

void visualize(Queue q)
{
    printf("%10s | %10s | %20s | %10s |\n", "NODE", "ID", "NAME", "PRICE");
    Node *curr = q.front;
    int index = 0;
    while (curr != NULL)
    {
        printf("%10d | %10d | %20s | %10.2f |", index, curr->data.id, curr->data.name, curr->data.price);
        if (curr == q.front)
        {
            printf(" -> FRONT");
        }
        if (curr == q.rear)
        {
            printf(" -> REAR");
        }
        printf("\n");
        curr = curr->next;
        index++;
    }
    if (index == 0)
    {
        printf("  (empty)\n");
    }
}

void display(Queue q)
{
    printf("{");
    Node *curr = q.front;
    while (curr != NULL)
    {
        printf("%d - %s - %.2f", curr->data.id, curr->data.name, curr->data.price);
        curr = curr->next;
        if (curr != NULL)
        {
            printf(", ");
        }
    }
    printf("}\n");
}
