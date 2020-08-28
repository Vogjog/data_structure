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
		queue->front->next = newNode;
		queue->front = newNode;
	}
}

int dequeue(Queue* queue){
	Node *currNode;
	int res;

	if(queue == NULL) {
		printf("NULL\n");
		return -1;
	}

	if(queue->rear == NULL){
		printf("no data for dequeue\n");
		return -1;
	}
	
	currNode = queue->rear;
	queue->rear = queue->rear->next;
	res = currNode->data;

	free(currNode);

	return res;

}

void printAll(Queue* queue){
	Node* currNode;

	if(queue == NULL) return;

	currNode = queue->rear;

	printf("printAll : \n");
	while(currNode != NULL){
		printf("%d\n", currNode->data);
		currNode = currNode->next;
	}
}

void printRear(Queue* queue){
	Node* node;

	if(queue == NULL) return;
	
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


	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));

	return 0;
}
