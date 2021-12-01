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
#include"2104_stack.h"

void main(){
    stackType s;
    EleType element, input[50];
    int i=0;
    printf("\nBracket Matching");
    printf("\nEnter the expression: ");
    scanf("%s",&input);
    for(i = 0;input[i] != '\0';i++){ //Validate the string
        if(i == 50){ //Validate the string length
            printf("\nEntered expression is too long. Expression size should be less than or equal to 50");
            exit(1);
        }
        if((input[i] >= 'a') && (input[i] <= 'z'))
            continue;
        if((input[i] >= 'A') && (input[i] <= 'Z'))
            continue;
       if((input[i] >= '0') && (input[i] <= '9'))
            continue;
        if((input[i] == '(') || (input[i] == ')') || (input[i] == '[') || (input[i] == ']') || (input[i] == '{') || (input[i] == '}'))
            continue;
        if((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/') || (input[i] == '%'))
            continue;
        printf("\nEntered invalid symbol in expression.");
        exit(1);
    }
    s = stackCreate();
    for(i = 0;input[i] != '\0';i++) { 
        //Push opening bracket in the stack
        if(input[i] == '(' || input[i] == '[' || input[i] == '{'){
            s.count++;
            if(stackPush(input[i], &s) == true)
                continue;
            else{
                printf("\nMemory full.");
                exit(1);
            }
        }
        else if(input[i] == ')' || input[i] == ']' || input[i] == '}'){ 
            //Pop from stack when closing bracket found
            if(s.count<1){
                printf("\nInvalid expression. Closing brackets more than opening brackets.");
                exit(1);
            }
            s.count--;
            element = stackPop(&s);
            //Check bracket matching
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