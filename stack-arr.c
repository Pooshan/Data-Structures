#include <stdio.h>

#define SIZE 5
int stack[SIZE];
int top=-1;
0.
int isEmpty() {
	if(top==-1) return 1;
	else return 0;
}

int isFull() {
	if(top==SIZE-1) return 1;
	else return 0;
}

int onTop() {
	return stack[top];
}

void push(int element) {
	if(isFull())
		printf("Stack is full\n");
	else {
		top++;
		stack[top]=element;
	}
}

void pop() {
	if(isEmpty()==1)
		printf("Stack is empty\n");
	else 
		top--;
}

main()
{
	push(10); push(11); push(12); push(101); push(21);
	push(50); // should get stack full message

	if(!isEmpty())
	 printf("On top we have %d\n",onTop());

	pop();	pop();	pop(); 

	if(!isEmpty())
	 printf("On top we have %d\n",onTop());

	pop(); pop();
	pop(); // should get stack empty message
}
