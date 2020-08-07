#include <stdio.h>
#include <stdlib.h>


typedef struct _NODE{
	struct _NODE *next;
	int data;
} NODE;

typedef struct _Linkedlist{
	NODE* head;
}Linkedlist;

void add_data(Linkedlist* link,int data){
	NODE* newNode = malloc(sizeof(NODE));
	newNode->data = data;
	if(link->head == NULL){
		link->head = newNode;
		newNode->next = NULL;
	}
	else{
		newNode->next = link->head;
		link->head = newNode;
	}
}

void remove_data(Linkedlist *link,int data){
	NODE* currNode, *prev;
	currNode = link->head;
	prev = currNode;
	while(currNode != NULL){
		if(currNode->data == data){
			if(currNode == link->head){
				link->head = currNode->next;
			}
			else{
				prev->next = currNode->next;
			}
			return;
		}
		prev = currNode;
		currNode = currNode->next;
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

void print_data(Linkedlist *link){
	NODE* currNode = link->head;
	while(currNode != NULL){
		printf("%d\n", currNode->data);

		currNode = currNode->next;
	}
}

int main(void){

	Linkedlist* link = malloc(sizeof(Linkedlist));

	add_data(link,10);
	add_data(link,20);
	add_data(link,30);
	print_data(link);

	remove_data(link,20);
	remove_data(link,15);
	print_data(link);


	return 0;

}

