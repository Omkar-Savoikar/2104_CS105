/*
    AUTHOR: MCA.2104
    PROGRAM: IMPLEMENTATION OF QUEUE
    DATE CREATED: 27 SEPT 2021
    DATE MODIFIED: 29 SEPT 2021
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include"2104_queue.h"

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
        printf("\nPress 3 to delete new element from the start of queue");
        printf("\nPress 4 to display the queue");
        printf("\nPress 0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1: {
                s = queueCreate();
                printf("\nQueue Created");
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