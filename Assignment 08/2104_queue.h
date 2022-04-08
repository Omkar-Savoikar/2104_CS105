/*
    AUTHOR: MCA.2104
    PROGRAM: IMPLEMENTATION OF QUEUE
    DATE CREATED: 25 OCT 2021
    DATE MODIFIED: 27 OCT 2021
*/
//DS Designer
#ifndef QUEUE_H
    #define QUEUE_H
    typedef struct vertexNode* qEleType;
    typedef struct queue_node qnode;
    typedef struct queue queueType;

    struct queue{
        qnode *start;
        qnode *end;
        int count;
    };

    struct queue_node{
        qEleType data;
        struct queue_node *next;
    };

    /*
        function name: queueCreate
        function: Create a new empty queue
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
    _Bool queueIsEmpty(queueType );
    /*
        function name: queueIsFull
        function: Checks if queue is full
        input: queueType
        pre-condition: queue exists
        output: true if queue is full, otherwise false
        post-condition: none
    */
    _Bool queueIsFull(queueType );
    /*
        function name: enqueue
        function: Enters new element at the end of the queue
        input: *queueType, qEleType
        pre-condition: queue exists
        output: true if element added to the queue, otherwise false
        post-condition: New element inserted at the end of the queue
    */
    _Bool enqueue(qEleType , queueType *);
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
        output: qEleType
        post-condition: Element at the start of the queue is deleted and start is shifted to the next element.
    */
    qEleType dequeue(queueType *);
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