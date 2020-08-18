#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node* next;
} Node;

typedef struct _Queue {
	Node* front;
	Node* rear;
} Queue;

void enqueue(Queue* queue, int data){
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if(queue->front == NULL){
		queue->front = newNode;
		queue->rear = newNode;
	}
	else{
		newNode->next = queue->front;
		queue->front = newNode;
	}
}

void dequeue(Queue* queue){
	Node *currNode, *prev, *rearCheck;

	if(queue->rear == NULL){
		printf("no data for dequeue\n");
		return;
	}

	rearCheck = queue->rear;
	currNode = queue->front;
	prev = currNode;
	//help
	while(currNode != NULL){
		if(rearCheck == queue->front){
			queue->front = NULL;
			queue->rear = NULL;
			return;
		} else {
			prev->next = currNode->next;
		}
		prev = currNode;
		currNode = currNode->next;
		if(currNode->next == NULL){
			queue->rear = prev;
			prev->next = NULL;
			return;
		}
	}
}

void printAll(Queue* queue){
	Node* currNode;

	if(queue == NULL) return;

	currNode = queue->front;

	printf("printAll : \n");
	while(currNode != NULL){
		printf("%d\n", currNode->data);
		currNode = currNode->next;
	}
}

void printRear(Queue* queue){
	Node* node;
	
	node = queue->rear;

	if(node != NULL){
		printf("dequeue : %d\n", node->data);
	}
}



int main(void) {

	Queue* queue = malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);

	printAll(queue);

	printRear(queue);
	dequeue(queue);
	printRear(queue);
	dequeue(queue);
	printRear(queue);
	dequeue(queue);
	printRear(queue);
	dequeue(queue);

	return 0;
}
