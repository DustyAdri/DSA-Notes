#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stackCursor.h"

static int allocNode(Stack *s)
{
    if (s->avail == -1)
        return -1;
    int retVal = s->avail;
    s->avail = s->elems[retVal].next;
    return retVal;
}

static void freeNode(Stack *s, int i)
{
    s->elems[i].next = s->avail;
    s->avail = i;
}

void initStack(Stack *s)
{
    s->top = -1;
    s->size = 0;
    for (int i = 0; i < MAX - 1; ++i)
        s->elems[i].next = i + 1;
    s->elems[MAX - 1].next = -1;
    s->avail = 0;
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
    return s.avail == -1;
}

bool push(Stack *s, Student stud)
{
    int idx = allocNode(s);
    if (idx == -1)
        return false;
    s->elems[idx].data = stud;
    s->elems[idx].next = s->top;
    s->top = idx;
    s->size++;
    return true;
}

bool pop(Stack *s)
{
    if (isEmpty(*s))
        return false;
    int idx = s->top;
    s->top = s->elems[idx].next;
    freeNode(s, idx);
    s->size--;
    return true;
}

Student peek(Stack s)
{
    return s.elems[s.top].data;
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
        printf("%5d | %5d | %15s | %5c | %7s | %5d\n", index, s.elems[curr].data.id, s.elems[curr].data.name, s.elems[curr].data.sex, s.elems[curr].data.program, s.elems[curr].data.year);
        curr = s.elems[curr].next;
        index--;
    }
}
