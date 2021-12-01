/*
    AUTHOR: MCA.2104
    PROGRAM: STACK USING LINKEDLIST LIB IMPLEMENTATION
    DATE CREATED: 20 SEPT 2021
    DATE MODIFIED: 22 SEPT 2021
*/
//DS Designer
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include"2104_stack.h"

stackType stackCreate(){ //Create a stack
    stackType s;
    s.count = 0;
    s.top = NULL;
    return s;
}

bool stackIsEmpty(stackType s1){ //Check if stack is empty
    if((s1.top == NULL) || (s1.count == 0))
        return true;
    else
        return false;
}

bool stackIsFull(stackType s1){ //Check if stack is full
    return false;
}

bool stackPush(EleType value, stackType *s1){ //Create a node and push it on stack top
    node *temp = (node *)malloc(1 * sizeof(node)); //Allocate momey for the new node
    if(temp == NULL)
        return false;
    temp->data = value;
    temp->next = s1->top;
    s1->top = temp;
    s1->count++;
    return true;
}

EleType stackPeek(stackType s1){ //Retuen value of element at top of stack
    return s1.top->data;
}

EleType stackPop(stackType *s1){ //Remove node at top of stack
    EleType value;
    node *temp = s1->top;
    s1->top = s1->top->next;
    value = temp->data;
    free(temp); //Deallocate memory of node
    s1->count--;
    return value;
}

void stackDelete(stackType *s1){ //Delete the stack
    node *temp;
    while(s1->top != NULL){
        temp = s1->top;
        s1->top = s1->top->next;
        free(temp); //Deallocate memory allocated to the nodes
        s1->count--;
    }
}