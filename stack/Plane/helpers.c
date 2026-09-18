#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// TODO: Write helper functions here...
void initializeStack_v1(Group* g)
{
    g->top = -1;
}
bool isFull_v1(Group* g)
{
    return g->top == MAX_PASSENGERS - 1; // top is index of the topmost filled slot
}

bool isEmpty_v1(Group* g)
{
    return g->top == -1;   
}

void push_v1(Group* g, char* value)
{
    if(!isFull_v1(g))
    {
        g->top++;
        strcpy(g->p[g->top].passengerName, value);
    }
}

void pop_v1(Group* g)
{
    if(!isEmpty_v1(g))
    {
        g->top--;
    }
}

void initializeStack_v2(Group* g)
{
    g->top = -1;
}

bool isFull_v2(Group* g)
{
    return g->top == MAX_PASSENGERS - 1;
}

bool isEmpty_v2(Group* g)
{
    return g->top == -1;
}

void push_v2(Group* g, char* value)
{
    if(!isFull_v2(g))
    {
        g->top++;
        strcpy(g->p[g->top].passengerName, value);
    }
}

void pop_v2(Group* g)
{
    if(!isEmpty_v2(g))
    {
        g->top--;
    }
}

 
void displayBoardingList(const BoardingList* list) {
    printf("\n--- Current Boarding List State ---\n\n");
    printf("  %5s %5s %5s   | %5s %5s %5s\n", "A", "B", "C", "D", "E", "F");
    printf("  --------------------------------------------------\n");
 
    for (int i = 0; i < MAX_ROWS; i++) {
        const Group* abc = &list->seatRows[i].ABC;
        const Group* def = &list->seatRows[i].DEF;
 
        const char* a = (abc->top >= 0) ? abc->p[0].passengerName : "-";
        const char* b = (abc->top >= 1) ? abc->p[1].passengerName : "-";
        const char* c = (abc->top >= 2) ? abc->p[2].passengerName : "-";
 
        const char* d = (def->top >= 2) ? def->p[2].passengerName : "-";
        const char* e = (def->top >= 1) ? def->p[1].passengerName : "-";
        const char* f = (def->top >= 0) ? def->p[0].passengerName : "-";
 
        printf("%d | %-5s %-5s %-5s | %-5s %-5s %-5s\n",
               i + 1, a, b, c, d, e, f);
    }
 
    printf("  --------------------------------------------------\n");
    printf("\nTotal passengers remaining: %d\n", list->passengerCount);
    printf("----------------------------------\n");
}
 
 
void initializeBoardingList1(BoardingList* list) {
    list->passengerCount = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        initializeStack_v1(&list->seatRows[i].ABC);
        initializeStack_v2(&list->seatRows[i].DEF);
    }
 
    // Row 1: A=John, B=Mary, C=Bob | E=Sam, F=Eve
    push_v1(&list->seatRows[0].ABC, "John");  list->passengerCount++;
    push_v1(&list->seatRows[0].ABC, "Mary");  list->passengerCount++;
    push_v1(&list->seatRows[0].ABC, "Bob");   list->passengerCount++;
    push_v2(&list->seatRows[0].DEF, "Eve");   list->passengerCount++;
    push_v2(&list->seatRows[0].DEF, "Sam");   list->passengerCount++;
 
    // Row 2: A=Linda | E=Tom, F=Alice
    push_v1(&list->seatRows[1].ABC, "Linda"); list->passengerCount++;
    push_v2(&list->seatRows[1].DEF, "Alice"); list->passengerCount++;
    push_v2(&list->seatRows[1].DEF, "Tom");   list->passengerCount++;
 
    // Row 3: A=Peter, B=Jane
    push_v1(&list->seatRows[2].ABC, "Peter"); list->passengerCount++;
    push_v1(&list->seatRows[2].ABC, "Jane");  list->passengerCount++;
 
    // Row 5: A=Chris, B=Anna | D=Tim, E=Sue, F=Mike
    push_v1(&list->seatRows[4].ABC, "Chris"); list->passengerCount++;
    push_v1(&list->seatRows[4].ABC, "Anna");  list->passengerCount++;
    push_v2(&list->seatRows[4].DEF, "Mike");  list->passengerCount++;
    push_v2(&list->seatRows[4].DEF, "Sue");   list->passengerCount++;
    push_v2(&list->seatRows[4].DEF, "Tim");   list->passengerCount++;
 
    // Row 6: A=David | E=Rob, F=Kate
    push_v1(&list->seatRows[5].ABC, "David"); list->passengerCount++;
    push_v2(&list->seatRows[5].DEF, "Kate");  list->passengerCount++;
    push_v2(&list->seatRows[5].DEF, "Rob");   list->passengerCount++;
 
    // Row 8: A=Sammy, B=Liz | E=Paul, F=Nancy
    push_v1(&list->seatRows[7].ABC, "Sammy"); list->passengerCount++;
    push_v1(&list->seatRows[7].ABC, "Liz");   list->passengerCount++;
    push_v2(&list->seatRows[7].DEF, "Nancy"); list->passengerCount++;
    push_v2(&list->seatRows[7].DEF, "Paul");  list->passengerCount++;
 
    printf("Populating boarding list 1...\n");
    printf("Boarding list 1 populated with %d passengers.\n", list->passengerCount);
}
 
void initializeBoardingList2(BoardingList* list) {
    list->passengerCount = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        initializeStack_v1(&list->seatRows[i].ABC);
        initializeStack_v2(&list->seatRows[i].DEF);
    }
 
    // Row 1: A=Alice, B=Ben | E=Diana, F=Carl
    push_v1(&list->seatRows[0].ABC, "Alice"); list->passengerCount++;
    push_v1(&list->seatRows[0].ABC, "Ben");   list->passengerCount++;
    push_v2(&list->seatRows[0].DEF, "Carl");  list->passengerCount++;
    push_v2(&list->seatRows[0].DEF, "Diana"); list->passengerCount++;
 
    // Row 2: A=Eli, B=Fay, C=Gina | F=Hank
    push_v1(&list->seatRows[1].ABC, "Eli");   list->passengerCount++;
    push_v1(&list->seatRows[1].ABC, "Fay");   list->passengerCount++;
    push_v1(&list->seatRows[1].ABC, "Gina");  list->passengerCount++;
    push_v2(&list->seatRows[1].DEF, "Hank");  list->passengerCount++;
 
    // Row 3: E=Jack, F=Ivy
    push_v2(&list->seatRows[2].DEF, "Ivy");   list->passengerCount++;
    push_v2(&list->seatRows[2].DEF, "Jack");  list->passengerCount++;
 
    // Row 4: A=Kim, B=Leo | F=Mona
    push_v1(&list->seatRows[3].ABC, "Kim");   list->passengerCount++;
    push_v1(&list->seatRows[3].ABC, "Leo");   list->passengerCount++;
    push_v2(&list->seatRows[3].DEF, "Mona");  list->passengerCount++;
 
    // Row 5: A=Nina | F=Oscar
    push_v1(&list->seatRows[4].ABC, "Nina");  list->passengerCount++;
    push_v2(&list->seatRows[4].DEF, "Oscar"); list->passengerCount++;
 
    // Row 6: A=Pam, B=Quinn | D=Ted, E=Sue, F=Ray
    push_v1(&list->seatRows[5].ABC, "Pam");   list->passengerCount++;
    push_v1(&list->seatRows[5].ABC, "Quinn"); list->passengerCount++;
    push_v2(&list->seatRows[5].DEF, "Ray");   list->passengerCount++;
    push_v2(&list->seatRows[5].DEF, "Sue");   list->passengerCount++;
    push_v2(&list->seatRows[5].DEF, "Ted");   list->passengerCount++;
 
    // Row 7: A=Uma
    push_v1(&list->seatRows[6].ABC, "Uma");   list->passengerCount++;
 
    // Row 8: D=Xena, E=Will, F=Vic
    push_v2(&list->seatRows[7].DEF, "Vic");   list->passengerCount++;
    push_v2(&list->seatRows[7].DEF, "Will");  list->passengerCount++;
    push_v2(&list->seatRows[7].DEF, "Xena");  list->passengerCount++;
 
    printf("Populating boarding list 2...\n");
    printf("Boarding list 2 populated with %d passengers.\n", list->passengerCount);
}
 
 
void initializeBoardingList3(BoardingList* list) {
    list->passengerCount = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        initializeStack_v1(&list->seatRows[i].ABC);
        initializeStack_v2(&list->seatRows[i].DEF);
    }
 
    // Row 5: A=Zack | F=Yara
    push_v1(&list->seatRows[4].ABC, "Zack");    list->passengerCount++;
    push_v2(&list->seatRows[4].DEF, "Yara");    list->passengerCount++;
 
    // Row 6: A=Wendy, B=Vera | F=Ulysses
    push_v1(&list->seatRows[5].ABC, "Wendy");   list->passengerCount++;
    push_v1(&list->seatRows[5].ABC, "Vera");    list->passengerCount++;
    push_v2(&list->seatRows[5].DEF, "Ulysses"); list->passengerCount++;
 
    // Row 7: A=Tim | F=Sophie
    push_v1(&list->seatRows[6].ABC, "Tim");     list->passengerCount++;
    push_v2(&list->seatRows[6].DEF, "Sophie");  list->passengerCount++;
 
    // Row 8: A=Ron, B=Quincy | E=Olga, F=Pat
    push_v1(&list->seatRows[7].ABC, "Ron");     list->passengerCount++;
    push_v1(&list->seatRows[7].ABC, "Quincy");  list->passengerCount++;
    push_v2(&list->seatRows[7].DEF, "Pat");     list->passengerCount++;
    push_v2(&list->seatRows[7].DEF, "Olga");    list->passengerCount++;
 
    printf("Populating boarding list 3...\n");
    printf("Boarding list 3 populated with %d passengers.\n", list->passengerCount);
}

 
void initializeBoardingList4(BoardingList* list) {
    list->passengerCount = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        initializeStack_v1(&list->seatRows[i].ABC);
        initializeStack_v2(&list->seatRows[i].DEF);
    }
 
    // Row 1
    push_v1(&list->seatRows[0].ABC, "Aaron");   list->passengerCount++;
    push_v1(&list->seatRows[0].ABC, "Beth");    list->passengerCount++;
    push_v1(&list->seatRows[0].ABC, "Cole");    list->passengerCount++;
    push_v2(&list->seatRows[0].DEF, "Adam");    list->passengerCount++;
    push_v2(&list->seatRows[0].DEF, "Zach");    list->passengerCount++;
    push_v2(&list->seatRows[0].DEF, "Yara");    list->passengerCount++;
 
    // Row 2
    push_v1(&list->seatRows[1].ABC, "Dana");    list->passengerCount++;
    push_v1(&list->seatRows[1].ABC, "Eric");    list->passengerCount++;
    push_v1(&list->seatRows[1].ABC, "Faye");    list->passengerCount++;
    push_v2(&list->seatRows[1].DEF, "Diane");   list->passengerCount++;
    push_v2(&list->seatRows[1].DEF, "Carl");    list->passengerCount++;
    push_v2(&list->seatRows[1].DEF, "Bella");   list->passengerCount++;
 
    // Row 3
    push_v1(&list->seatRows[2].ABC, "Greg");    list->passengerCount++;
    push_v1(&list->seatRows[2].ABC, "Hana");    list->passengerCount++;
    push_v1(&list->seatRows[2].ABC, "Ivan");    list->passengerCount++;
    push_v2(&list->seatRows[2].DEF, "Gary");    list->passengerCount++;
    push_v2(&list->seatRows[2].DEF, "Flora");   list->passengerCount++;
    push_v2(&list->seatRows[2].DEF, "Evan");    list->passengerCount++;
 
    // Row 4
    push_v1(&list->seatRows[3].ABC, "Julia");   list->passengerCount++;
    push_v1(&list->seatRows[3].ABC, "Karl");    list->passengerCount++;
    push_v1(&list->seatRows[3].ABC, "Lena");    list->passengerCount++;
    push_v2(&list->seatRows[3].DEF, "Jade");    list->passengerCount++;
    push_v2(&list->seatRows[3].DEF, "Ian");     list->passengerCount++;
    push_v2(&list->seatRows[3].DEF, "Helen");   list->passengerCount++;
 
    // Row 5
    push_v1(&list->seatRows[4].ABC, "Mark");    list->passengerCount++;
    push_v1(&list->seatRows[4].ABC, "Nora");    list->passengerCount++;
    push_v1(&list->seatRows[4].ABC, "Owen");    list->passengerCount++;
    push_v2(&list->seatRows[4].DEF, "Max");     list->passengerCount++;
    push_v2(&list->seatRows[4].DEF, "Laura");   list->passengerCount++;
    push_v2(&list->seatRows[4].DEF, "Kevin");   list->passengerCount++;
 
    // Row 6
    push_v1(&list->seatRows[5].ABC, "Paula");   list->passengerCount++;
    push_v1(&list->seatRows[5].ABC, "Quinn");   list->passengerCount++;
    push_v1(&list->seatRows[5].ABC, "Ryan");    list->passengerCount++;
    push_v2(&list->seatRows[5].DEF, "Penny");   list->passengerCount++;
    push_v2(&list->seatRows[5].DEF, "Oscar");   list->passengerCount++;
    push_v2(&list->seatRows[5].DEF, "Nancy");   list->passengerCount++;
 
    // Row 7
    push_v1(&list->seatRows[6].ABC, "Sarah");   list->passengerCount++;
    push_v1(&list->seatRows[6].ABC, "Todd");    list->passengerCount++;
    push_v1(&list->seatRows[6].ABC, "Uma");     list->passengerCount++;
    push_v2(&list->seatRows[6].DEF, "Steve");   list->passengerCount++;
    push_v2(&list->seatRows[6].DEF, "Rose");    list->passengerCount++;
    push_v2(&list->seatRows[6].DEF, "Quentin"); list->passengerCount++;
 
    // Row 8
    push_v1(&list->seatRows[7].ABC, "Vera");    list->passengerCount++;
    push_v1(&list->seatRows[7].ABC, "Will");    list->passengerCount++;
    push_v1(&list->seatRows[7].ABC, "Xena");    list->passengerCount++;
    push_v2(&list->seatRows[7].DEF, "Violet");  list->passengerCount++;
    push_v2(&list->seatRows[7].DEF, "Ulric");   list->passengerCount++;
    push_v2(&list->seatRows[7].DEF, "Tina");    list->passengerCount++;
 
    printf("Populating boarding list 4...\n");
    printf("Boarding list 4 populated with %d passengers.\n", list->passengerCount);
}