#include <stdio.h>
#include <stdbool.h>
#include "stackArray.h"

int main ()
{
    Stack s = newStack();
    initStack(&s);
    Student arr[10] = {
        {1001, "Alice Johnson", 'F', "BSCS", 1},
        {1002, "Bob Smith", 'M', "BSIT", 2},
        {1003, "Clara Davis", 'F', "BSCE", 3},
        {1004, "David Brown", 'M', "BSCS", 4},
        {1005, "Emma Wilson", 'F', "BSIT", 1},
        {1006, "Frank Miller", 'M', "BSEE", 2},
        {1007, "Grace Taylor", 'F', "BSME", 3},
        {1008, "Henry Anderson", 'M', "BSCS", 1},
        {1009, "Isla Thomas", 'F', "BSIT", 4},
        {1010, "Jack Jackson", 'M', "BSCE", 2}
    };

    visualize(s);

    for(int i = 0; i < MAX; ++i)
    {
        push(&s, arr[i]);
    }

    visualize(s);

    if(isFull(s))
    {
        printf("The stack is full, you can't push anymore.\n");
    }

    for(int i = 0; i < 10; ++i)
    {
        pop(&s);
    }

    if(isEmpty(s));
        printf("The stack is now empty.\n");
}