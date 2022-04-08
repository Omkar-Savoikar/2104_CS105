/*
    AUTHOR: MCA.2104
    PROGRAM: STACK APPLICATION 2 - EVALUATING POSTFIX EXPRESSION
    DATE CREATED: 22 SEPT 2021
    DATE MODIFIED: 27 SEPT 2021
*/
//Whole Code
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include<ctype.h>

typedef int EleType;
typedef struct stack_node node;
typedef struct stack stackType;

struct stack{
    node *top;
    int count;
};

struct stack_node{
    EleType data;
    struct stack_node *next;
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

int conv(char x){
    switch(x){
        case '1':return(1);
        case '2':return(2);
        case '3':return(3);
        case '4':return(4);
        case '5':return(5);
        case '6':return(6);
        case '7':return(7);
        case '8':return(8);
        case '9':return(9);
        case '0':return(0);
    }
}

void main(){
    stackType s;
    EleType element;
    char inp_str[50];
    int i=0, pop_ele1, pop_ele2, push_ele;
    printf("\nPostfix Expression Evaluation");
    printf("\nEnter the expression: ");
    scanf("%s",inp_str);
    s = stackCreate();
    for(i=0;inp_str[i]!='\0';i++){ //Validate the inp_string
        if(i == 50){
            printf("\nExpression length too long. Expression length should be less than or equal to 50");
            exit(1);
        }
        if(isdigit(inp_str[i]) == 1){
            //Convert char to int and push operand in the stack
            push_ele = conv(inp_str[i]);
            if(stackPush(push_ele, &s) == true)
                continue;
            else{
                printf("\nMemory full.");
                exit(1);
            }
        }
        else if( (inp_str[i] == '+') ||  (inp_str[i] == '-') ||  (inp_str[i] == '*') ||  (inp_str[i] == '/')){
            //Pop two values out and perform the operation. Then push back the answer
            if(stackIsEmpty(s) == true){
                printf("Invalid expression");
                exit(1);
            }
            else
                pop_ele1 = stackPop(&s);
            if(stackIsEmpty(s) == true){
                printf("Invalid expression");
                exit(1);
            }
            else
                pop_ele2 = stackPop(&s);
            switch(inp_str[i]){
                case '+': {
                    push_ele = pop_ele2 + pop_ele1;
                    break;
                }
                case '-': {
                    push_ele = pop_ele2 - pop_ele1;
                    break;
                }
                case '*': {
                    push_ele = pop_ele2 * pop_ele1;
                    break;
                }
                case '/': push_ele = pop_ele2 / pop_ele1;
            }
            if(stackPush(push_ele, &s) == true)
                continue;
            else{
                printf("\nMemory full.");
                exit(1);
            }
        }
        else{
            printf("\nEntered invalid symbol in the expression. Enter only operators and operands.");
            exit(1);
        }
    }
    if(s.count == 1)
        printf("\nFinal answer: %d",stackPeek(s));
    else
        printf("\nInvalid Expression.");
    stackDelete(&s);
}