#include <stdio.h>
#include <stdlib.h>


typedef struct _NODE{
	struct _NODE *next;
	struct _NODE *prev;
	int data;
} NODE;

typedef struct _Linkedlist{
	NODE* head;
	NODE* tail;
}Linkedlist;

void add_data(Linkedlist* link,int data){
	NODE* newNode = malloc(sizeof(NODE));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	if(link->head == NULL){
		link->head = newNode;
		link->tail = newNode;
	}
	else{
		newNode->next = link->head;
		newNode->next->prev = newNode;
		link->head = newNode;
	}
}

NODE* search_data(Linkedlist *link,int data){
	NODE* searchNode = link->head;
	while(searchNode != NULL){
		if(searchNode->data == data){
			return searchNode;
		}
		searchNode = searchNode->next;
	}
	return NULL;
}

void remove_data(Linkedlist *link,int data){
	NODE* currNode;

	currNode = search_data(link, data);

	if(currNode == NULL){
		return;
	}
	else{
		if(link->head == link->tail){
			link->head=NULL;
			link->tail=NULL;
		}
		else if(link->head == currNode){
			link->head = currNode->next;
			currNode->next->prev = NULL;
		}
		else if(link->tail == currNode){
			link->tail = currNode->prev;
			currNode->prev->next = NULL;
		}
		else{
			currNode->prev->next = currNode->next;
			currNode->next->prev = currNode->prev;
		}
	}
}

void print_data(Linkedlist *link){
	NODE* currNode = link->head;
	while(currNode != NULL){
		printf("print : %d\n", currNode->data);

		currNode = currNode->next;
	}
}

void reverse_print(Linkedlist *link){
	NODE* currNode = link->tail;
	while(currNode !=NULL){
		printf("Rprint : %d\n", currNode->data);

		currNode = currNode->prev;
	}
}

int main(void){

	Linkedlist* link = malloc(sizeof(Linkedlist));
	link->head = NULL;

	add_data(link,10);
	add_data(link,20);
	add_data(link,30);
	print_data(link);
	reverse_print(link);

	remove_data(link,20);
	remove_data(link,15);
	print_data(link);
	reverse_print(link);

	return 0;

}

