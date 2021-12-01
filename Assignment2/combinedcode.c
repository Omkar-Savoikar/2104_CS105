#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>

typedef int EleType;
typedef struct stack_node node;
typedef struct stack stackType;


struct stack_node{
    EleType data;
    struct stack_node *next;
};

struct stack{
    node *top;
    int count;
};

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

void main(){
    stackType s;
    EleType element;
    int option;
    option = 1;
    s = stackCreate();
    printf("\nSTACK USING LINKEDLIST");
    do{
        printf("\nPress 1 to create new stack");
        printf("\nPress 2 to push new element to the stack");
        printf("\nPress 3 to pop new element to the stack");
        printf("\nPress 4 to peek new element to the stack");
        printf("\nPress 0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1: {
                s = stackCreate();
                printf("\nStack Created");
                break;
            }
            case 2: {
                if(stackIsFull(s) == false){
                    printf("\nEnter element value: ");
                    scanf("%d",&element);
                    if(stackPush(element, &s) == true)
                        printf("\nPush Successful. %d pushed to the stack",element);
                    else
                        printf("Memory full. Cannot add more data.");
                }
                else
                    printf("\nStack overflow. Cannot push more elements.");
                break;
            }
            case 3: {
                if(stackIsEmpty(s) == false){
                    element = stackPop(&s);
                    printf("\nPop successful. %d popped from stack.", element);
                }
                else
                    printf("\nStack underflow. Stack is empty. Cannot pop any elements.");
                break;
            }
            case 4: {
                if(stackIsEmpty(s) == 0){
                    element = stackPeek(s);
                    printf("\nElement at top of stack = %d",element);
                }
                else
                    printf("\nStack is empty");
                break;
            }
            case 0: break;
            default: printf("\nInvalid input. Enter proper input (0 to 4).");
        }
        printf("\n\n");
    }while(option != 0);
    stackDelete(&s);
}