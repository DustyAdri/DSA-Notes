#include <stdio.h>
#include <stdlib.h>
#include "cursorQueue.h"

int main()
{
    Queue q1 = newQueue();

    Queue q2;
    initQueue(&q2);

    display(q1);
    visualize(q1);
    display(q2);
    visualize(q2);

    enqueue(&q1, newProduct(5, "BALLPEN", 100.00));
    display(q1);
    enqueue(&q1, newProduct(6, "BACKPACK", 599.99));
    display(q1);
    enqueue(&q1, newProduct(7, "CELLPHONE", 9.99));
    display(q1);
    enqueue(&q1, newProduct(8, "KEYBOARD", 100.00));
    display(q1);
    enqueue(&q1, newProduct(9, "MONITOR", 1999.99));
    display(q1);
    visualize(q1);

    enqueue(&q2, newProduct(5, "BALLPEN", 100.00));
    display(q2);
    enqueue(&q2, newProduct(6, "BACKPACK", 599.99));
    display(q2);
    enqueue(&q2, newProduct(7, "CELLPHONE", 9.99));
    display(q2);
    enqueue(&q2, newProduct(8, "KEYBOARD", 100.00));
    display(q2);
    enqueue(&q2, newProduct(9, "MONITOR", 1999.99));
    display(q2);
    visualize(q2);

    return 0;
}
