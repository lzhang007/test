#ifndef LIST_H_
#define LIST_H_

#include<stdbool.h>

#define TSIZE 45

//film type
typedef struct film
{
    char title[TSIZE];
    int rating;
}Item;

typedef struct node
{
    Item item;
    struct node *next;
}Node;

typedef Node *List;

void InitializeList(List *list);

bool ListIsEmpty(const List *list);

bool ListIsFull(const List *list);

unsigned int ListItemCount(const List *list);

bool AddItem(Item item,List *list);

void Traverse(const List *list,void (*pfun)(Item item));

void EmptyTheList(List *list);

#endif
