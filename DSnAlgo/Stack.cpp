#include <stdio.h>
#include <conio.h>

#define STACK_SIZE 10

int Stack[STACK_SIZE] = {0};
int top = -1;

void printCurrentState()
{
	for (int i = (STACK_SIZE-1); i >= 0; i--)
	{
		printf("| %2d |", Stack[i]);
		if (i == top)
			printf("<--Top");
		printf("\n");
	}
	if(top == -1)
		printf("<--Top\n");
	printf("------------------------------------\n");
}

void StackImplementation()
{
	printCurrentState();
}
