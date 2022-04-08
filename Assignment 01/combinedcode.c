#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>

typedef int EleType;
typedef struct stack stackType;

struct stack{
    EleType *stack_array[10];
    int top;
    int size;
};

stackType stackCreate(int size){
    stackType s1;
    int i;
    s1.top = -1;
    s1.size = size;
    for(i=0;i<size;i++)
        s1.stack_array[i] = (EleType *)malloc(size * sizeof(EleType));
    if(s1.stack_array == NULL)
        exit(1);
    return s1;
}

bool stackIsEmpty(stackType s){
    if(s.top == -1)
        return true;
    else
        return false;
}

bool stackIsFull(stackType s){
    if(s.top == s.size-1)
        return true;
    else
        return false;
}

int stackPush(EleType element, stackType *s1){
    s1->top +=1;
    s1->stack_array[s1->top] = element;
    return 0;
}

EleType stackPop(stackType *s1){
    EleType element;
    element = s1->stack_array[s1->top];
    s1->top -=1;
    return element;
}

EleType stackPeek(stackType *s1){
    EleType element;
    element = s1->stack_array[s1->top];
    return element;
}

void stackDelete(stackType *s1){
    int i;
    for(i=0;i<s1->size;i++)
        free(s1->stack_array[i]);
    s1->top = -1;
}

void main(){
    stackType s;
    EleType element;
    int option, size;
    size = 10;
    option = 1;
    s = stackCreate(size);
    printf("\nSTACK USING ARRAYS");
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
                s = stackCreate(size);
                printf("\nStack Created");
                break;
            }
            case 2: {
                if(stackIsFull(s) == false){
                    printf("\nEnter element value: ");
                    scanf("%d",&element);
                    if(stackPush(element, &s) == 0)
                        printf("\nPush Successful. %d pushed to the stack",element);
                }
                else
                    printf("\nStack overflow. Stack is full. Cannot push any more elements");
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
                if(stackIsEmpty(s) == false){
                    element = stackPeek(&s);
                    printf("\nElement at top of stack = %d",element);
                }
                else
                    printf("\nStack is empty.");
                break;
            }
            case 0: break;
            default: printf("\nInvalid input. Enter proper input (0 to 4).");
        }
        printf("\n\n");
    }while(option != 0);
    stackDelete(&s);
}