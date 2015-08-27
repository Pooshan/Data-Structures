//
//  main.c
//  DataStructure
//
//  Created by Pooshan Vyas on 8/19/15.
//  Copyright © 2015 Pooshan Vyas. All rights reserved.
//

#include <stdio.h>

#define size 5

int stack [size];
int top = -1; // Because index start from 0

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == size -1)
        return 1;
    else
        return 0;
}

int onTop()
{
    return stack[top];
}

void push(int element)
{
    if(isFull())
        printf("stack is Full\n");
    else
    {
        top++;
        stack[top] = element;
    }
}

void pop()
{
    if(isEmpty()==1)
        printf("stack is Empty\n");
    else
        top--;
}

int main()
{
    push(10); push(11); push(101); push(21); push(50);
    pop(); pop(); pop();

    printf("on the top we have %d \n", onTop());
  
    
}






