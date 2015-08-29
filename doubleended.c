//doubleended.c
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

int atRear() {
	return queue[rear];
}

void insertRear(int element) {
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

void insertFront(int element) {
	if(isFull())
		printf("Queue is full\n");
	else {
		if(front==-1)
			front=rear=0;
		else
		{
			front=(front-1)%SIZE;
			if(front<0) front=SIZE-1;
		}
			
		queue[front]=element;
	}
}

void delFront() {
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

void delRear() {
	if(isEmpty()==1)
		printf("Queue is empty\n");
	else 
	{
		if(front==rear)
			front=rear=-1;
		else
		{
			rear=(rear-1)%SIZE;
			if(rear<0) rear=SIZE-1;
		}
	}
}

main()
{
	insertRear(11);
	insertRear(12);
	insertRear(13);
	insertRear(14);
	insertRear(15);
	printf("At front:  %d, At Rear: %d\n",atFront(),atRear());
	delRear();
	insertFront(100);
	insertFront(200);

	printf("At front:  %d, At Rear: %d\n",atFront(),atRear());
	delRear();
	insertFront(300);

	printf("At front:  %d, At Rear: %d\n",atFront(),atRear());
}

