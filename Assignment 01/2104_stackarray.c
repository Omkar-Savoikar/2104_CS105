/*
    AUTHOR: MCA.2104
    PROGRAM: STACK USING ARRAY LIB IMPLEMENTATION
    DATE CREATED: 08 SEPT 2021
    DATE MODIFIED: 22 SEPT 2021
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<stdbool.h>
#include"2104_stack.h"
void main(){
    stackType s;
    EleType element;
    int option, size;
    size = 10;
    option = 1;
    s = stackCreate(size); //Create stack at start
    printf("\nSTACK USING ARRAYS");
    do{
        printf("\nMenu");
        printf("\n1. Create new stack");
        printf("\n2. Push new element to the stack");
        printf("\n3. Pop new element to the stack");
        printf("\n4. Peek new element to the stack");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1: { //Create stack
                printf("\nEnter the size for the stack (max 10): ");
                scanf("%d",&size);
                if((size > 10) || (size < 1)){ //array size = 10
                    printf("\nEntered invalid size. Enter size between 1 to 10.");
                    break;
                }
                s = stackCreate(size);
                printf("\nStack Created");
                break;
            }
            case 2: { //Push
                if(stackIsFull(s) == false){
                    printf("\nEnter element value: ");
                    scanf("%d",&element);
                    if(stackPush(element, &s) == true)
                        printf("\nPush Successful. %d pushed to the stack",element);
                }
                else
                    printf("\nStack overflow. Stack is full. Cannot pop any more elements");
                break;
            }
            case 3: { //Pop
                if(stackIsEmpty(s) == false){
                    element = stackPop(&s);
                    printf("\nPop successful. %d popped from stack.", element);
                }
                else
                    printf("\nStack underflow. Stack is empty. Cannot pop any elements.");
                break;
            }
            case 4: { //Peek
                if(stackIsEmpty(s) == false){
                    element = stackPeek(&s);
                    printf("\nElement at top of stack = %d",element);
                }
                else
                    printf("\nStack is empty");
                break;
            }
            case 0: break; //Exit
            default: printf("\nInvalid input. Enter proper input (0 to 5).");
        }
        printf("\n");
    }while(option != 0);
    stackDelete(&s); //Delete stack at the end
}