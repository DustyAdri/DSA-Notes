#ifndef STACKARRAY_H
#define STACKARRAY_H

#define MAX 10
#define EMPTY 1000

typedef struct {
    int id;
    char name[20];
    char sex; // bembang yarn
    char program[10];
    int year;
} Student;

typedef struct {
    Student data[MAX];
    int top;
} Stack;

void initStack (Stack *S); // set all values to default
Stack newStack();
bool isEmpty(Stack s);
bool isFull(Stack s);
bool push(Stack *s, Student stud);
bool pop(Stack *s);
Student peek(Stack s);
void visualize (Stack s);
void display(Stack s);

#endif