#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stackCursor.h"

static int allocNode(Stack *s)
{
    if (s->freeList == -1)
        return -1;
    int idx = s->freeList;
    s->freeList = s->pool[idx].next;
    return idx;
}

static void freeNode(Stack *s, int idx)
{
    s->pool[idx].next = s->freeList;
    s->freeList = idx;
}

void initStack(Stack *s)
{
    s->top = -1;
    s->size = 0;
    for (int i = 0; i < MAX - 1; ++i)
        s->pool[i].next = i + 1;
    s->pool[MAX - 1].next = -1;
    s->freeList = 0;
}

Stack newStack()
{
    Stack s;
    return s;
}

bool isEmpty(Stack s)
{
    return s.top == -1;
}

bool isFull(Stack s)
{
    return s.freeList == -1;
}

bool push(Stack *s, Student stud)
{
    int idx = allocNode(s);
    if (idx == -1)
        return false;
    s->pool[idx].data = stud;
    s->pool[idx].next = s->top;
    s->top = idx;
    s->size++;
    return true;
}

bool pop(Stack *s)
{
    if (isEmpty(*s))
        return false;
    int idx = s->top;
    s->top = s->pool[idx].next;
    freeNode(s, idx);
    s->size--;
    return true;
}

Student peek(Stack s)
{
    return s.pool[s.top].data;
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
    int curr = s.top;
    int index = s.size - 1;
    while (curr != -1)
    {
        printf("%5d | %5d | %15s | %5c | %7s | %5d\n", index, s.pool[curr].data.id, s.pool[curr].data.name, s.pool[curr].data.sex, s.pool[curr].data.program, s.pool[curr].data.year);
        curr = s.pool[curr].next;
        index--;
    }
}
