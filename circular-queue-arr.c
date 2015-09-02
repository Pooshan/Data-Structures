//cir-queue-arr.c
#include <stdio.h>

#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;

int isEmpty() {
	if(front==-1) return 1;
	else return 0;
}

int isFull() {
	if( (rear+1)%SIZE==front) return 1;
	else return 0;
}

int atFront() {
	return queue[front];
}

void insert(int element) {
	if(isFull())
		printf("Queue is full\n");
	else {
		if(rear==-1)
			front=rear=0;
		else
			rear=(rear+1)%SIZE;
			
		queue[rear]=element;
	}
}

void del() {
	if(isEmpty()==1)
		printf("Queue is empty\n");
	else 
	{
		if(front==rear)
			front=rear=-1;
		else
			front=(front+1)%SIZE;
	}
}

main()
{
	insert(10); insert(11); insert(12); insert(13); insert(14);
	insert(50); // should get queue full message

	if(!isEmpty())
	 printf("At front we have %d\n",atFront());

	del();	del();
	if(!isEmpty())
	 printf("At front we have %d\n",atFront());
	
	insert(50);
	insert(60);
	
	del(); del(); del();
	if(!isEmpty())
	 printf("At front we have %d\n",atFront());

	del();
	if(!isEmpty())
	 printf("At front we have %d\n",atFront());

	del();
	
	del(); // should get queue empty message
}
