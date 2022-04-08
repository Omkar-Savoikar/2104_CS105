/*
    AUTHOR: MCA.2104
    PROGRAM: IMPLEMENTATION OF QUEUE
    DATE CREATED: 27 SEPT 2021
    DATE MODIFIED: 29 SEPT 2021
*/
//DS DEVELOPER
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include"2104_queue.h"

queueType queueCreate(){
    queueType s;
    s.count = 0;
    s.start = NULL;
    s.end = NULL;
    return s;
}

bool queueIsEmpty(queueType q1){
    if((q1.start == NULL) || (q1.count == 0))
        return true;
    else
        return false;
}

bool queueIsFull(queueType q1){
    return false;
}

bool enqueue(EleType value, queueType *q1){
    node *temp = (node *)malloc(1 * sizeof(node));
    if(temp == NULL)
        return false;
    temp->data = value;
    temp->next = NULL;
    if(q1->count == 0)
        q1->start = temp;
    else
        q1->end->next = temp;
    q1->end = temp;
    q1->count++;
    return true;
}

void queueDisplay(queueType q1){
    node *temp = q1.start;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

EleType dequeue(queueType *q1){
    EleType value;
    node *temp = q1->start;
    q1->start = q1->start->next;
    value = temp->data;
    free(temp);
    q1->count--;
    return value;
}

void queueDelete(queueType *q1){
    node *temp;
    while(q1->start != NULL){
        temp = q1->start;
        q1->start = q1->start->next;
        free(temp);
        q1->count--;
    }
}