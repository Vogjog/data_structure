#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10

char* stack[MAX_SIZE];
int top = -1; //init value of top

int IsEmpty(void)
{
	if(top < 0)
		return 1;
	else
		return 0;
}

int IsFull(void)
{
	if(top >= MAX_SIZE - 1)
		return 1;
	else
		return 0;
}



int push(char* data)
{
	if(IsFull())
	{
		printf("stack is full\n");
		return 0;
	}
	else
	{
		stack[++top] = data;
		return 1;
	}
}


char* pop(void)
{
	if(IsEmpty())
	{
		printf("stack is empty\n");
		return NULL;
	}
	else
	{
		return stack[top--];
	}
}

char* peek(void)
{
	if(IsEmpty())
	{
		printf("stack is empty\n");
		return NULL;
	}
	else
	{
		return stack[top];
	}
}

void test(void)
{
	char data[MAX_SIZE+1] = "a";
	char* temp;
	for(int i = 0; i <= MAX_SIZE; ++i)
	{
		temp = malloc(MAX_SIZE+1);
		strcpy(temp, data);
		push(temp);
		strcat(data, "P");

		printf("peek : %s\n", peek());
	}


	for(int i = 0; i <= MAX_SIZE; ++i)
	{
		temp = pop();	
		printf("pop : %s\n", temp);
		free(temp);
	}
}


int main(void)
{

	test();

	return 0;
}

