/*
    AUTHOR: MCA.2104
    PROGRAM: IMPLEMENTATION OF QUEUE
    DATE CREATED: 27 SEPT 2021
    DATE MODIFIED: 29 SEPT 2021
*/
//DS Designer
#ifndef STACK_H
    #define STACK_H
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

    /*
        function name: queueCreate
        function: Create a new empty queue of given size
        input: none
        pre-condition: none
        output: queueType
        post-condition: empty queue is created
    */
    queueType queueCreate();
    /*
        function name: queueIsEmpty
        function: Checks if queue is empty
        input: queueType
        pre-condition: queue exists
        output: true if queue is empty, otherwise false
        post-condition: none
    */
    bool queueIsEmpty(queueType );
    /*
        function name: queueIsFull
        function: Checks if queue is full
        input: queueType
        pre-condition: queue exists
        output: true if queue is full, otherwise false
        post-condition: none
    */
    bool queueIsFull(queueType );
    /*
        function name: enqueue
        function: Enters new element at the end of the queue
        input: *queueType, EleType
        pre-condition: queue exists
        output: true if element added to the queue, otherwise false
        post-condition: New element inserted at the end of the queue
    */
    bool enqueue(EleType , queueType *);
    /*
        function name: queueDisplay
        function: Displays all elements in the queue
        input: queueType
        pre-condition: queue exists and is not empty
        output: none
        post-condition: none
    */
    void queueDisplay(queueType );
    /*
        function name: dequeue
        function: Deletes the element at the start of the queue
        input: *queueType
        pre-condition: queue exists and is not empty
        output: EleType
        post-condition: Element at the start of the queue is deleted and start is shifted to the next element.
    */
    EleType dequeue(queueType *);
    /*
        function name: queueDelete
        function: Deletes the queue
        input: *queueType
        pre-condition: queue exists
        output: none
        post-condition: All elements from queue are deleted and the space is freed.
    */
    void queueDelete(queueType *);
#endif