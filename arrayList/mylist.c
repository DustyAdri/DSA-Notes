#include "MYLIST.H"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void initList(List *list, int size){
    list->size = size;
    list->elems = malloc(sizeof(Data) * size);
    list->count = 0;
}

List newList(int size){
    List list;
    list.size = size;
    list.elems = malloc(sizeof(Data) * size);
    list.count = 0;
    return list;
}


void display(List list)
{
    printf("\nList contents: ");
    for(int i = 0; i < list.count; i++)
    {
        printf("%d ", list.elems[i]);
    }
}

bool insertFront(List *list, int item)
{
    if(list->count < list->size)
    {
        for(int i = list->count; i > 0; i--)
        {
            list->elems[i] = list->elems[i - 1];
        }
        list->elems[0] = item;
        list->count++;
        return true;
    }
    return false;
}

bool insertRear(List *list, int item)
{
    if(list->count < list->size)
    {
        list->elems[list->count] = item;
        list->count++;
        return true;
    }
    return false;
}

bool insertAt(List *list, int index, int item)
{
    if(list->count < list->size && index >= 0 && index <= list->count)
    {
        for(int i = list->count; i > index; i--)
        {
            list->elems[i] = list->elems[i - 1];
        }
        list->elems[index] = item;
        list->count++;
        return true;
    }
    return false;
}

bool deleteFront(List *list)
{
    if(list->count != 0)
    {
        for(int i = 0; i < list->count - 1; i++)
        {
            list->elems[i] =  list->elems[i + 1];
        }
        list->count--;
        return true;
    }
    return false;
}

bool deleteRear(List *list)
{
    if(list->count != 0)
    {
        list->count--;
        return true;
    }
    return false;
}

int deleteAllItem(List *list, int item)
{
    int numRemoved = 0;
    for(int i = 0; i < list->count; i++)
    {
        if(list->elems[i] == item)
        {
            for(int j = i; j < list->count - 1; j++)
            {
                list->elems[j] = list->elems[j + 1];
            }
            list->count--;
            numRemoved++;
            i--; // recheck same index after deleting
        }
    }
    return numRemoved;
}

int deleteItem(List *list, int item)
{
    int found = -1;
    for(int i = 0; i < list->count; i++)
    {
        if (item == list->elems[i])
        {
            found = i;
            break;
        }
    }

    if(found == -1)
    {
        printf("Item not found.\n");
        return -1;
    }

    for(int j = found; j < list->count - 1; j++)
    {
        list->elems[j] = list->elems[j + 1];
    }

    list->count--;
    return item;
}

bool isInList(List list, int key)
{
    for(int i = 0; i < list.count; i++)
    {
        if(list.elems[i] == key)
        {
            return true;
        }
    }
    return false;
}

int isFoundAt(List list, int key)
{
    for(int i = 0; i < list.count; i++)
    {
        if(list.elems[i] == key)
        {
            return i;
        }
    }
    return -1;
}


void freeList (List *list)
{
    if (list->elems != NULL)
    {
        free(list->elems);
    }
    list->count = 0;
    list->size = 0;
}