//dll_uod.c
#include <stdio.h>
#include <stdlib.h>

typedef 
struct list
{ struct list *prev;
  int data;
  struct list *next;
} node;

node *head=NULL,*tail=NULL;

node* newNode(int element)
{
	node *temp=(node*)malloc(sizeof(node));
	
	temp->data=element;
	temp->next=temp->prev=NULL;
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
	node *temp;

if(head==NULL)
   printf("List empty");
else
 {
	printf("\nHead to Tail\n");
	temp=head;
	while(temp!=NULL)
	{ printf("%d ->",temp->data);
	  temp=temp->next;
	}

	printf("\nTail to Head\n");
	temp=tail;
	while(temp!=NULL)
	{ printf("<- %d ",temp->data);
	  temp=temp->prev;
	}
	printf("\n");
 }
}

void insertBegin(int element)
{
	node *temp=newNode(element);
	
	if(head==NULL)
	   head=tail=temp;	
	else
	{ temp->next=head;
	  head->prev=temp;
	  head=temp;
	}	   
}

void insertEnd(int element)
{
	node *temp=newNode(element);
	
	if(tail==NULL)
		head=tail=temp;
	else
	{ tail->next=temp;
	  temp->prev=tail;
	  tail=temp;
	}
}

void insertAfter(int after_ele,int element)
{
	node *temp,*current=findNode(after_ele);
	
	if(current==NULL)
		printf("Sorry element not found\n");
	//if after tail	
	else if(current->next==NULL)
		insertEnd(element);
	else
	{ temp=newNode(element);
	  temp->next=current->next;
	  current->next->prev=temp;
	  temp->prev=current;
	  current->next=temp;
	}
}

void deleteBegin()
{
	node *temp=head;

	if(head!=NULL)
	{ head=head->next;
		
		if(head==NULL)
			tail=NULL;
		else
			head->prev=NULL;
			
	  free(temp);
	}
}

void deleteEnd()
{
	node *temp=tail;
	
	if(tail!=NULL)
	{
		tail=tail->prev;
		
		if(tail==NULL)
			head=NULL;
		else
			tail->next=NULL;
			
		free(temp);
	}
}

void deleteAfter(int after_ele)
{
	node *temp,*current=findNode(after_ele);

	//if no after_ele or if after tail
	if(current==NULL || current->next==NULL)
		printf("Sorry element not found\n");
	//if last node
	else if(current->next->next==NULL)
		deleteEnd();
	else
	{ temp=current->next;
	  current->next=temp->next;
	  current->next->prev=current;
	  free(temp);
	}
}

main()
{
	insertAfter(10,15);

	insertEnd(10);
	display();

	insertAfter(10,12);
	insertAfter(10,11);
	display();

	insertAfter(100,13);
	deleteAfter(12);

	deleteAfter(10);
	display();
	
	deleteEnd();
	deleteBegin();

	display();
}
