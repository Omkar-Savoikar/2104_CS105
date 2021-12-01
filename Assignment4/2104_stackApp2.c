/*
    AUTHOR: MCA.2104
    PROGRAM: STACK APPLICATION 1 - BRACKET MATCHING
    DATE CREATED: 22 SEPT 2021
    DATE MODIFIED: 23 SEPT 2021
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include<ctype.h>
#include"2104_stack.h"

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

int calc(int x, int y, char op){
    switch(op){
        case '+': return(y+x);
        case '-': return(y-x);
        case '*': return(y*x);
        case '/': return(y/x);
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
            push_ele = calc(pop_ele1, pop_ele2,inp_str[i]);
            if(stackPush(push_ele, &s) == true)
                continue;
            else{
                printf("\nMemory full.");
                exit(1);
            }
        }
        else{
            printf("\nEntered invalid symbol in the expression.");
            exit(1);
        }
    }
    if(s.count == 1)
        printf("\nFinal answer: %d",stackPeek(s));
    else
        printf("\nInvalid Expression.");
    stackDelete(&s);
}