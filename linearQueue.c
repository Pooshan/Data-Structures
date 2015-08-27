//
//  main.c
//  queue
//
//  Created by Pooshan Vyas on 8/24/15.
//  Copyright © 2015 Pooshan Vyas. All rights reserved.
//

/* 

 isEmpty()
 isFull()
 atFront()
 insert(type element)
 del()
 
 As like queue in real life: Insert from rear and Delete from front

*/


#include <stdio.h>

#define size 5
int queue[size];
int front = -1, rear = -1;

int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear == size-1)
        return 1;
    else
        return 0;
}

int atFront(){
    return queue[front];
}

void insert(int element){
    if (isFull())
        printf("\n Queue is full");
    else{
        if (rear==-1)
            front=rear=0;
        else
            rear++;
        queue[rear]=element;
    }
}

void del(){
    if (isEmpty()==1)
        printf("\n Queue is empty");
    else
    {
        if(front==rear)
            front=rear=-1;
        else
            front++;
    }
}

int main() {
    
    
   
    insert(10); insert(11); insert(101); insert(21); insert(50);
    del(); del(); del();
    
    printf("on the top we have %d \n", atFront());
    
}
