#include <stdio.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
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



int push(int value)
{
	if(IsFull())
	{
		printf("stack is full\n");
		return 0;
	}
	else
	{
		stack[++top] = value;
		return 1;
	}
}


int pop(void)
{
	if(IsEmpty())
	{
		printf("stack is empty\n");
		return -1;
	}
	else
	{
		return stack[top--];
	}
}

int peek(void)
{
	if(IsEmpty())
	{
		printf("stack is empty\n");
		return -1;
	}
	else
	{
		return stack[top];
	}
}

void test(void)
{

	for(int i = 0; i <= MAX_SIZE; ++i)
	{
		if(!push(i))
		{
			printf("overflow error!!\n");
			break;
		}
		printf("peek : %d\n", peek());
	}
	for(int i = 0; i <= MAX_SIZE; ++i)
	{
		printf("pop : %d\n", pop());
	}
}


int main(void)
{

	test();

	return 0;
}

