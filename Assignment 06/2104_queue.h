/*
    AUTHOR: MCA.2104
    PROGRAM: QUEUE APPLICATION 1 - D'SOUZA DESIGNERS
    DATE CREATED: 29 SEPT 2021
    DATE MODIFIED: 29 SEPT 2021
*/
//DS Designer
#ifndef STACK_H
    #define STACK_H
    typedef struct jobs EleType;
    typedef struct queue_node node;
    typedef struct queue queueType;

    struct queue{
        node *start;
        node *end;
        int count;
    };

    struct jobs{
        int jobid, fees, amount;
    };

    struct queue_node{
        EleType data;
        struct queue_node *next;
    };
    
    /*
        function name: queueCreate
        function: Creates an empty queue
        input: none
        pre-condition: none
        output: queueType
        post-condition: none
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
        function: Inserts an element at the end of the queue
        input: *queueType, EleType
        pre-condition: queue exists
        output: true if queue is element added at the end of the queue, otherwise false
        post-condition: New element inserted at the end of the queue
    */
    bool enqueue(EleType , queueType *);
    /*
        function name: queueDisplay
        function: Displays all the elements in the queue
        input: queueType
        pre-condition: queue exists and is not empty
        output: none
        post-condition: none
    */
    void queueDisplay(queueType );
    /*
        function name: dequeue
        function: Deletes the element the start of the queue
        input: EleType
        pre-condition: queue exists and is not empty
        output: EleType
        post-condition: Element at the start of the queue is deleted and queue start is shifted to next element.
    */
    EleType dequeue(queueType *);
    /*
        function name: queueDelete
        function: Delete the queue
        input: *queueType
        pre-condition: queue exists
        output: none
        post-condition: All elements in the queue are removed and the space is freed.
    */
    void queueDelete(queueType *);
#endif