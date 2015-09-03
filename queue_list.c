//queue_list.c
#include <stdio.h>
#include <stdlib.h>

typedef 
struct list
{ int data;
  struct list *next;
} node;

node *front=NULL,*rear=NULL;

node* newNode(int element)
{
	node *temp=(node*)malloc(sizeof(node));
	
	temp->data=element;
	temp->next=NULL;
 return temp;	
}

int isEmpty()
{ if(front==NULL) 
	return 1;
  else 
  	return 0;
}

int atFront()
{ return front->data;
}

void insert(int element)
{
	node *temp=newNode(element);
	
	if(isEmpty())
	   front=rear=temp;	
	else
	{ rear->next=temp;
	  rear=temp;
	}	   
}

void del()
{ node *temp=front;

	if(isEmpty())
		printf("Queue empty\n");
	else
	{ 
		front=front->next;
		if(front==NULL) rear=NULL;
		
	  free(temp);
	}
}

main()
{
	insert(10); insert(11); insert(12); insert(13); insert(14);

	if(!isEmpty())
	 printf("At front we have %d\n",atFront());

	del();	del();	del(); 

	if(!isEmpty())
	 printf("At front we have %d\n",atFront());

	del(); del();
	del(); // should get queue empty message
}

