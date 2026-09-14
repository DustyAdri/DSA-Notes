#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stackArray.h"

// insertatEnd && DeleteAtEnd

void initStack (Stack *s)
{
    for(int i = 0; i > s->top; ++i)
    {
        s->data[i].id = EMPTY;
        strcpy(s->data[i].name, "\0");
        s->data[i].sex = '\0';
        strcpy(s->data[i].program, "\0");
        s->data[i].year = 0;
    }
    s->top = 0;
}

Stack newStack()
{
    Stack s;
    return s;
}

bool isEmpty(Stack s)
{
    if(s.top == 0)
    {
        return true;
    }
    return false;
}

bool isFull(Stack s)
{
    if(s.top == MAX)
    {
        return true;
    }
    return false;
}

bool push(Stack *s, Student stud) // insertAtEnd
{
    if(!isFull(*s))
    {
        s->data[s->top] = stud;
        ++s->top;
        return true;
    }
    return false;
}
bool pop(Stack *s)
{
    if(!isEmpty(*s))
    {
        s->data[s->top].id = EMPTY;
        --s->top;
        return true;
    }
    return false;
}

Student peek(Stack s)
{
    return s.data[s.top];
}

void visualize (Stack s)
{
    if(isEmpty(s))
    {
        printf("The stack is empty no stack to visualize.\n");
    }
    else
    {
        printf("%5s\n", "TOP");
        printf("%5s | %5s | %15s | %5s | %7s | %5s\n", "INDEX", "ID", "NAME", "SEX", "PROGRAM", "YEAR");
        for(int i = s.top - 1; i >= 0; --i)
        {
            printf("%5d | %5d | %15s | %5c | %7s | %5d\n", i, s.data[i].id, s.data[i].name, s.data[i].sex, s.data[i].program, s.data[i].year);
        }
    }
}

