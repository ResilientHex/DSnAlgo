#include <stdio.h>
#include <conio.h>

#define STACK_SIZE 3

int Stack[STACK_SIZE] = {0};
int topStack = -1;

void printCurrentStackState()
{
	for (int i = (STACK_SIZE-1); i >= 0; i--)
	{
		printf("| %2d |", Stack[i]);
		if (i == topStack)
			printf("<--Top %d",topStack);
		printf("\n");
	}
	if(topStack == -1)
		printf("<--Top %d\n", topStack);
	printf("------------------------------------\n");
}

//Display
//push
//pop
//Overflow
//Underflow

//Console user convinient application.
int isStackFull()
{
	if (topStack < (STACK_SIZE - 1))
		return 0;
	return 1;
}

int isStackEmpty()
{
	if (topStack < 0)
		return 1;
	return 0;
}

void pushElementToStack(int Element)
{
	if (isStackFull() == 1)
	{
		printf("Stack is Full.\n");
		return;
	}

	topStack++;
	Stack[topStack] = Element;
}

int popElementFromStack()
{
	if (isStackEmpty() == 1)
	{
		printf("Stack is empty, pop operation cannot be performed.");
		return -1;
	}
	int temp = Stack[topStack];
	topStack--;
	return temp;
}

void displayStack()
{
	printf("\nStack contains below elements.\n");
	for (int i = 0; i <= topStack; i++)
	{
		printf(" %d", Stack[i]);
	}
	printf("\n");
}

void stackImplementation()
{
	//printf("Hello From Stack file.");
	printCurrentStackState();

	pushElementToStack(10);
	pushElementToStack(20);
	pushElementToStack(30);
	pushElementToStack(75);


	int val = popElementFromStack();
	//expecting val to 75;
	//top pointing one element down.
	printf("%d is poped.\n", val);
	popElementFromStack();
	displayStack();
	pushElementToStack(47);
	pushElementToStack(38);
	displayStack();
	popElementFromStack();
	displayStack();
	//printCurrentState();
}


void userRequiredActionForStack()
{
	printf("\nPlease select your action.\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Display current data.\n");
	printf("0. Exit.\n");
	printf("\n");
}
void userFriendlyStackOperations()
{
	int userSelection = -1;
	while (userSelection != 0)
	{
		userRequiredActionForStack();
		scanf_s("%d", &userSelection);

		switch (userSelection)
		{
		case 0: // no need to do anything for this case.
			break;
		case 1: // push.			
			if (isStackFull())
			{
				printf("Stack is full. No element can be inserted.\n");
			}
			else{
				printf("Please add element you want to insert in stack:");
				int elementToInsert = 0;
				scanf_s("%d", &elementToInsert);
				pushElementToStack(elementToInsert);
				printf("%d is added in stack.\n\n", elementToInsert);
			}
			break;
		case 2: // pop.
			{
			if (isStackEmpty())
			{
				printf("Stack is Empty.\n\n");
			}
			else {
				int val = popElementFromStack();
				printf("Poped element is %d.\n\n", val);
			}
			}
			break;
		case 3: // display.
			displayStack();
			break;
		default:
			printf("Please select correct input.\n");
			break;
		}
	}
	printf("Thank you.");
}