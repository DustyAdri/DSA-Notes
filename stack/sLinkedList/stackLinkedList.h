#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

#include <stdbool.h>

#define EMPTY 1000

typedef struct {
    int id;
    char name[20];
    char sex;
    char program[10];
    int year;
} Student;

typedef struct Node {
    Student data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Stack;

void initStack(Stack *s);
Stack newStack();
bool isEmpty(Stack s);
bool isFull(Stack s);
bool push(Stack *s, Student stud);
bool pop(Stack *s);
Student peek(Stack s);
void visualize(Stack s);

#endif
