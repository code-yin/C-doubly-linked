#include <stdio.h>
#include <stdlib.h>
#include "my_dlist.h"

DList* create_list(){
	DList* list = (DList*)malloc(sizeof(DList));

if (list == NULL){
	return NULL;
}

list->head = NULL; 
list->tail = NULL;
list->len = 0;

return list;
}

void push_back(DList* list, int value) {
	if (list == NULL) return;
	
	DNode* newNode = malloc(sizeof(DNode));
	if (newNode == NULL) return;  

	newNode->data = value;
	newNode->next = NULL;        
	newNode->prev = list->tail; 
	
	if (list->tail != NULL) {
		list->tail->next = newNode;} 
	else {
			list->head = newNode;}
		
	list->tail = newNode;
	list->len++;
}

void push_front(DList* list, int value) {
	if (list == NULL) return;
	
	DNode* newNode = malloc(sizeof(DNode));
	if (newNode == NULL) return;
	
	newNode->data = value;
	newNode->next = list->head;
	newNode->prev = NULL;
	
	if (list->head != NULL) {
		list->head->prev = newNode;}
	else {
		list->tail = newNode;}
	
	list->head = newNode;
	list->len++;
}

void print_list(DList* list) {
	if (list == NULL) {
		printf("List is NULL!\n");
		return;
	}
	if (list->head == NULL) {
		printf("List is empty.\n");
		return;
	}
	
	DNode* p = list->head;
	printf("List contents (head -> tail): ");
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	
	printf("\n");
	printf("Total length: %d\n", list->len);
}


void print_reverse(DList* list) {
	if (list == NULL) {
		printf("List is NULL!\n");
		return;
	}
	
	if (list->tail == NULL) {
		printf("List is empty.\n");
		return;
	}
	
	DNode* p = list->tail;
	
	printf("List contents (tail -> head): ");

	while (p != NULL) {
		printf("%d ", p->data);

		p = p->prev;
	}
	
	printf("\n");
	printf("Total length: %d\n", list->len);
}


int get_length(DList* list) {
	if (list == NULL) {
		return 0;
	}
	return list->len;
}

void free_list(DList* list) {
	if (list == NULL) {
		return;
	}
	
	DNode* current = list->head;
	while (current != NULL) {
		DNode* next = current->next; 
		free(current);              
		current = next;             
	}
	
	free(list); 
}