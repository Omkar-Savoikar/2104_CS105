/*
    AUTHOR: MCA.2104
    PROGRAM: STACK USING ARRAY LIB IMPLEMENTATION
    DATE CREATED: 08 SEPT 2021
    DATE MODIFIED: 22 SEPT 2021
*/
//DS DEVELOPER
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include"2104_stack.h"

stackType stackCreate(int size){ //Will create a stack of given size and return back the stack
    stackType s1;
    int i;
    s1.top = -1; // top = -1 when stack is empty
    s1.size = size;
    for(i=0;i<size;i++){
        s1.stack_array[i] = (EleType *)malloc(size * sizeof(EleType)); //Allocates memeory for the stack array
        if(s1.stack_array == NULL){
            printf("\nError in creating stack of given size.");
            exit(1); //Enough memeory could not be allocated
        }
    }
    return s1;
}

bool stackIsEmpty(stackType s){ //Will check if stack is empty or not
    if(s.top == -1)
        return true;
    else
        return false;
}

bool stackIsFull(stackType s){ //Will check if stack is full or not
    if(s.top == s.size-1)
        return true;
    else
        return false;
}

bool stackPush(EleType element, stackType *s1){ //Push an element at the top of the stack
    s1->top +=1;
    s1->stack_array[s1->top] = element;
    return true;
}

EleType stackPop(stackType *s1){ //Remove an element from the top of the stack
    EleType element;
    element = s1->stack_array[s1->top];
    s1->top -=1;
    return element;
}

EleType stackPeek(stackType *s1){ //Return back the value of the element at the top of the stack
    EleType element;
    element = s1->stack_array[s1->top];
    return element;
}

void stackDelete(stackType *s1){ //Destroy the stack
    int i;
    for(i=0;i<s1->size;i++)
        free(s1->stack_array[i]); //Deallocate the memory allocated for the stack array
    s1->top = -1; 
}