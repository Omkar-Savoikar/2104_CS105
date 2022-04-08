/*
    AUTHOR: MCA.2104
    PROGRAM: STACK USING LINKEDLIST LIB IMPLEMENTATION
    DATE CREATED: 20 SEPT 2021
    DATE MODIFIED: 22 SEPT 2021
*/
//DS Designer
#ifndef STACK_H
    #define STACK_H
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
    
    /*
        function name: stackCreate
        function: Create a new empty stack
        input: none
        pre-condition: none
        output: stackType
        post-condition: empty stack is created
    */
    stackType stackCreate();
    /*
        function name: stackIsEmpty
        function: Checks if stack is empty
        input: stackType
        pre-condition: stack exist
        output: true if stack is empty, otherwise false
        post-condition: none
    */
    bool stackIsEmpty(stackType);
    /*
        function name: stackIsFull
        function: Checks if stack is full
        input: stackType
        pre-condition: stack exist
        output: true if stack is full, otherwise false
        post-condition: none
    */
    bool stackIsFull(stackType);
    /*
        function name: stackPush
        function: Pushes an element at top of the stack
        input: *stackType, EleType
        pre-condition: stack exists and is not full
        output: true if new element is added at top of the stack, otherwise false
        post-condition: New element added at the top of the stack
    */
    bool stackPush(EleType, stackType *);
    /*
        function name: stackPop
        function: Pops the element at the top of the stack
        input: *stackType
        pre-condition: stack exists and is not empty
        output: EleType
        post-condition: Element at top of the stack is deleted
    */
    EleType stackPop(stackType *);
    /*
        function name: stackPeek
        function: Value of the element at top of the stack is returned
        input: *stackType
        pre-condition: stack ecists and is not empty
        output: EleType
        post-condition: Value of element at top of the stack is returned
    */
    EleType stackPeek(stackType);
    /*
        function name: stackDelete
        function: deletes all the elements in the stack, assigns top to -1
        input: *stackType
        pre-condition: stack exists
        output: none
        post-condition: Stack is deleted
    */
    void stackDelete(stackType *);
#endif