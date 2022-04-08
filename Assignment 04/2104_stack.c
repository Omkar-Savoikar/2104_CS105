/*
    AUTHOR: MCA.2104
    PROGRAM: STACK APPLICATION 1 - BRACKET MATCHING
    DATE CREATED: 22 SEPT 2021
    DATE MODIFIED: 23 SEPT 2021
*/
//DS DEVELOPER
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include"2104_stack.h"

stackType stackCreate(){
    stackType s;
    s.count = 0;
    s.top = NULL;
    return s;
}

bool stackIsEmpty(stackType s1){
    if((s1.top == NULL) || (s1.count == 0))
        return true;
    else
        return false;
}

bool stackIsFull(stackType s1){
    return false;
}

bool stackPush(EleType value, stackType *s1){
    node *temp = (node *)malloc(1 * sizeof(node));
    if(temp == NULL)
        return false;
    temp->data = value;
    temp->next = s1->top;
    s1->top = temp;
    s1->count++;
    return true;
}

EleType stackPeek(stackType s1){
    return s1.top->data;
}

EleType stackPop(stackType *s1){
    EleType value;
    node *temp = s1->top;
    s1->top = s1->top->next;
    value = temp->data;
    free(temp);
    s1->count--;
    return value;
}

void stackDelete(stackType *s1){
    node *temp;
    while(s1->top != NULL){
        temp = s1->top;
        s1->top = s1->top->next;
        free(temp);
        s1->count--;
    }
}