//sll_uod.c
#include <stdio.h>
#include <stdlib.h>

typedef 
struct list
{ int data;
  struct list *next;
} node;

node *head=NULL;

node* newNode(int element)
{
	node *temp=(node*)malloc(sizeof(node));
	
	temp->data=element;
	temp->next=NULL;
 return temp;	
}

node* findNode(int e)
{
	node *h=head;
	
	while(h!=NULL)
	{ if(h->data==e)
		return h;
	  
	  h=h->next;
	}
	
 return NULL;
}

void display()
{
	node *h=head;

if(head==NULL)
   printf("List empty");
else	
	while(h!=NULL)
	{ printf("%d ->",h->data);
	  h=h->next;
	}

printf("\n");
}

void insertBegin(int element)
{
	node *temp=newNode(element);
	
	if(head==NULL)
	   head=temp;	
	else
	{ temp->next=head;
	  head=temp;
	}	   
}

void insertAfter(int after_ele,int element)
{
	node *temp,*current=findNode(after_ele);
	
	if(current==NULL)
		printf("Sorry element not found\n");
	else
	{ temp=newNode(element);
	  temp->next=current->next;
	  current->next=temp;
	}
}

void deleteBegin()
{
	node *temp=head;

	if(head!=NULL)
	{ head=head->next;
	  free(temp);
	}
}

void deleteAfter(int after_ele)
{
	node *temp,*current=findNode(after_ele);

	//if no after_ele or if after tail
	if(current==NULL || current->next==NULL)
		printf("Sorry element not found\n");
	else
	{ temp=current->next;
	  current->next=temp->next;
	  free(temp);
	}
}

main()
{
	insertAfter(10,15);

	insertBegin(10);
	display();

	insertAfter(10,15);
	display();

	insertAfter(10,12);
	display();

	insertAfter(10,11);
	display();

	insertAfter(12,14);
	display();
	
	deleteAfter(15);
	deleteAfter(7);
	
	deleteBegin();
	deleteBegin();
	deleteBegin();

	display();
	deleteAfter(14);
	display();
	deleteBegin();
	display();
}
