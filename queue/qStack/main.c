#include <stdio.h>
#include "myheader.h"

int main() {
    

    Queue q;
    initQueue(&q);

    stackPush(&q, newProductOrder(1, "Coffee", 1, 5.99));
    stackPush(&q, newProductOrder(2, "Coffee1", 2, 7.99));
    stackPush(&q, newProductOrder(3, "Coffee2", 3, 9.99));
    displayQueue(q);
    printf("Front %d Rear %d\n", q.front, q.rear);
    upsizeDrink(&q, 2);
    displayQueue(q);
    printf("Front %d Rear %d\n", q.front, q.rear);

    Queue newqueue = filterAndRemoveBySize(&q, 3);
    printf("Queue 1:\n");
    displayQueue(q);
    printf("Front %d Rear %d\n", q.front, q.rear);
    
    printf("Queue 2:\n");
    displayQueue(newqueue);
    printf("Front %d Rear %d\n", newqueue.front, newqueue.rear);
    

    return 0;
}

// 
// 1   3 2 
// 0 1 2 3 4
// r     f

// 