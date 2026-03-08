#include <stdio.h>
#include <stdlib.h>
#ifndef MY_DLIST_H
#define MY_DLIST_H

typedef struct DNode{
	int data;
	struct DNode* prev;
	struct DNode* next;
}DNode;

typedef struct DList{
	DNode* head;
	DNode* tail;
	int len;
}DList;

DList* create_list();
void push_front(DList* list, int value);
void push_back(DList* list, int value); 

void print_list(DList* list);
void print_reverse(DList* list);

int get_length(DList* list);
void free_list(DList* list);

#endif

