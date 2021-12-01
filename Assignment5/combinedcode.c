/*
    AUTHOR: MCA.2104
    PROGRAM: IMPLEMENTATION OF QUEUE
    DATE CREATED: 27 SEPT 2021
    DATE MODIFIED: 29 SEPT 2021
*/
//Whole Code
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>

typedef int EleType;
typedef struct queue_node node;
typedef struct queue queueType;

struct queue{
    node *start;
    node *end;
    int count;
};

struct queue_node{
    EleType data;
    struct queue_node *next;
};

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

/*
EleType dequeue(queueType *q1){
    EleType value;
    node *temp = q1->start;
    q1->count--;
    if(q1->count == 1)
        q1->start = q1->end = NULL;
    else
        q1->start = q1->start->next;
    value = temp->data;
    free(temp);
    return value;
}
*/

void queueDelete(queueType *q1){
    node *temp;
    while(q1->start != NULL){
        temp = q1->start;
        q1->start = q1->start->next;
        free(temp);
        q1->count--;
    }
}

void main(){
    queueType s;
    EleType element;
    int option;
    option = 1;
    s = queueCreate();
    printf("\nQUEUE USING LINKEDLIST");
    do{
        printf("\nPress 1 to create new queue");
        printf("\nPress 2 to add new element to the end of queue");
        printf("\nPress 3 to delete an element from the start of queue");
        printf("\nPress 4 to display the queue");
        printf("\nPress 0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1: {
                queueDelete(&s);
                s = queueCreate();
                printf("\nNew Queue Created");
                break;
            }
            case 2: {
                if(queueIsFull(s) == false){
                    printf("\nEnter element value: ");
                    scanf("%d",&element);
                    if(enqueue(element, &s) == true)
                        printf("\nEnqueue Successful. %d added to the queue",element);
                    else
                        printf("Memory full. Cannot add more data.");
                }
                else
                    printf("\nQueue overflow. Cannot add more elements.");
                break;
            }
            case 3: {
                if(queueIsEmpty(s) == false){
                    element = dequeue(&s);
                    printf("\nDequeue successful. %d removed from queue.", element);
                }
                else
                    printf("\nQueue underflow. Queue is empty. Cannot dequeue any elements.");
                break;
            }
            case 4: {
                if(queueIsEmpty(s) == false){
                    queueDisplay(s);
                }
                else
                    printf("\nQueue is empty");
                break;
            }
            case 0: break;
            default: printf("\nInvalid input. Enter proper input (0 to 4).");
        }
        printf("\n\n");
    }while(option != 0);
    queueDelete(&s);
}