#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>

typedef char EleType;
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

bool validate(char input){
    if((input >= 'a') && (input <= 'z'))
        return true;
    if((input >= 'A') && (input <= 'Z'))
        return true;
    if((input >= '0') && (input <= '9'))
        return true;
    if((input == '(') || (input == ')') || (input == '[') || (input == ']') || (input == '{') || (input == '}'))
        return true;
    if((input == '+') || (input == '-') || (input == '*') || (input == '/') || (input == '%'))
        return true;
    return false;
}

void main(){
    stackType s;
    EleType element, input[50];
    int i=0;
    printf("\nBracket Matching");
    printf("\nEnter the expression: ");
    scanf("%s",&input);
    for(i=0;input[i]!='\0';i++){
        if(validate(input[i]) == true)
            continue;
        printf("\nEntered invalid symbol in expression.");
        exit(1);
    }
    s = stackCreate();
    for(i=0;input[i] != '\0';i++) {
        if(input[i] == '(' || input[i] == '[' || input[i] == '{'){
            s.count++;
            if(stackPush(input[i], &s) == true)
                continue;
            else
                printf("\nMemory full.");
        }
        else if(input[i] == ')' || input[i] == ']' || input[i] == '}'){
            if(s.count<1){
                printf("\nInvalid expression. Closing brackets more than opening brackets.");
                exit(1);
            }
            s.count--;
            element = stackPop(&s);
            if((element == '(') && (input[i] == ')'))
                continue;
            if((element == '[') && (input[i] == ']'))
                continue;
            if((element == '{') && (input[i] == '}'))
                continue;
            printf("\nInivalid Expression. Bracket mismatch found. Closing bracket not matching opening bracket.");
            exit(1);
        }
    }
    if((stackIsEmpty(s) == true) && s.count == 0)
        printf("\nValid expression.");
    else
        printf("\nInvalid Expression. Opening brackets more than closing brackets.");
}