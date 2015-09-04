#include <stdio.h>
#include <ctype.h>

#define SIZE 500
int stack[SIZE];
int top=-1;

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

int calculate(char operator,int op1,int op2)
{
  switch(operator)
  { 
    case '+': return op1+op2;
    case '-': return op1-op2;
    case '*': return op1*op2;
    case '/': return op1/op2;
    case '%': return op1%op2;
  }
}

main()
{
  char postfix[200],token;
  int i,op1,op2;
   printf("Enter postfix expr \n");
   scanf("%s",postfix);

  for(i=0;postfix[i]!='\0';i++)
  { token=postfix[i];
	if(isdigit(token))
		push(token-48);//get the numer value
	else {
	  op2=onTop(); 
	  pop();
	  op1=onTop(); 
	  pop();
	  push(calculate(token,op1,op2));
	}
  }
  printf("Result=%d\n",onTop());	
}

