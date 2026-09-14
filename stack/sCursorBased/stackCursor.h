#ifndef STACKCURSOR_H
#define STACKCURSOR_H

#include <stdbool.h>

#define MAX 10
#define EMPTY 1000

typedef struct {
    int id;
    char name[20];
    char sex;
    char program[10];
    int year;
} Student;

typedef struct {
    Student data;
    int next;
} CursorNode;

typedef struct {
    CursorNode elems[MAX];
    int top;
    int avail;
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
