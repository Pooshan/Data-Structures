#include <stdio.h>
#include <ctype.h>

#define SIZE 500
char stack[SIZE];
int top=-1;

int isEmpty() {
	if(top==-1) return 1;
	else return 0;
}

int isFull() {
	if(top==SIZE-1) return 1;
	else return 0;
}

char onTop() {
	return stack[top];
}

void push(char element) {
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

int in_pri(char opr)
{ switch(opr)
  { 
    case '(': return 4;
    case '*':
    case '/':
    case '%': return 3;
    case '+':
    case '-': return 2;
  }
}

int stack_pri(char opr)
{ switch(opr)
  { 
    case '(': return 1;
    case '*':
    case '/':
    case '%': return 3;
    case '+':
    case '-': return 2;
  }
}

main()
{
  char infix[200],postfix[200],token;
  int i,j=0;
  printf("Enter infix expr :\n");
  scanf("%s",infix);

  for(i=0;infix[i]!='\0';i++)
  { token=infix[i];

    if(isdigit(token)) // if operand
		postfix[j++]=token;
    else // if operator
    { 
      if(isEmpty()==1) 
 	      push(token);
      else if(token==')')
	  {
	    while( onTop()!='(')
	    {
		   postfix[j++]=onTop();
		   pop();
	    }
	       pop(); // remove the recent '('
      }
      else if(in_pri(token)>stack_pri(onTop()) ) 
	 			push(token);
       else 
	   {
	     postfix[j++]=onTop();
	     pop();
	     push(token);
	   }	
    }
  }//for ends here

	while(!isEmpty())
	{
		postfix[j++]=onTop();
		pop();
	}
	
	postfix[j++]='\0';
	printf("Postfix:%s\n",postfix);
}
