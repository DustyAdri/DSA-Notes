#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stackLinkedList.h"

void initStack(Stack *s)
{
    s->top = NULL;
    s->size = 0;
}

Stack newStack()
{
    Stack s;
    s.top = NULL;
    s.size = 0;
    return s;
}

bool isEmpty(Stack s)
{
    return s.top == NULL;
}

bool isFull(Stack s)
{
    return false;
}

bool push(Stack *s, Student stud)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        return false;
    newNode->data = stud;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    return true;
}

bool pop(Stack *s)
{
    if (isEmpty(*s))
        return false;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return true;
}

Student peek(Stack s)
{
    return s.top->data;
}

void visualize(Stack s)
{
    if (isEmpty(s))
    {
        printf("The stack is empty, no stack to visualize.\n");
        return;
    }
    printf("%5s\n", "TOP");
    printf("%5s | %5s | %15s | %5s | %7s | %5s\n", "INDEX", "ID", "NAME", "SEX", "PROGRAM", "YEAR");
    Node *curr = s.top;
    int index = s.size - 1;
    while (curr != NULL)
    {
        printf("%5d | %5d | %15s | %5c | %7s | %5d\n", index, curr->data.id, curr->data.name, curr->data.sex, curr->data.program, curr->data.year);
        curr = curr->next;
        index--;
    }
}
