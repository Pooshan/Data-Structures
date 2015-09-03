//stack_list.c
#include <stdio.h>
#include <stdlib.h>

typedef 
struct list
{ int data;
  struct list *next;
} node;

node *top=NULL;

int isEmpty() {
	if(top==NULL) return 1;
	else return 0;
}

int onTop() {
	return top->data;
}

node* newNode(int element)
{
	node *temp=(node*)malloc(sizeof(node));
	
	temp->data=element;
	temp->next=NULL;
 return temp;	
}

void push(int element)
{
	node *temp=newNode(element);
	
	if(isEmpty())
	   top=temp;	
	else
	{ temp->next=top;
	  top=temp;
	}	   
}

void pop()
{	int element;
	node *temp;

	if(isEmpty())
		printf("Stack empty\n");
	else
	{	temp=top;
		top=top->next;
		free(temp);
	}	
}

main()
{
	push(10); push(11); push(12); push(101); push(21);

	if(!isEmpty())
	 printf("On top we have %d\n",onTop());

	pop();	pop();	pop(); 

	if(!isEmpty())
	 printf("On top we have %d\n",onTop());

	pop(); pop();
	pop(); // should get stack empty message
}
