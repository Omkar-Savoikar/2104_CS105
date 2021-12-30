/*
    AUTHOR: MCA.2104
    PROGRAM: HEAP SORT
    DATE CREATED: 29 DEC 2021
    DATE MODIFIED: 30 DEC 2021
*/
//DS Designer
#ifndef HEAP
    #define HEAP

    int heap[50];

    /*
    function name: swap
    function: swaps two values
    input: int*, int*
    pre-condition: none
    output: none
    post-condition: values at provided pointers swapped
    */
    void swap(int *x, int *y);

    /*
    function name: reHeapUp
    function: swaps current node with parent if current node value is larger than parent
    input: int[], int*
    pre-condition: value should be inserted in the heap
    output: none
    post-condition: value at index position placed properly in the heap
    */
    void reHeapUp(int heap[], int *index);

    /*
    function name: insertElement
    function: inserts element in the heap
    input: int[], int*, int
    pre-condition: size != 50
    output: none
    post-condition: new value inserted in the heap at proper position
    */
    void insertElement(int heap[], int *size, int value);

    /*
    function name: display
    function: displays all the elements in the heap
    input: int[], int
    pre-condition: size > 0
    output: none
    post-condition: all elements in the heap are displayed
    */
    void display(int heap[], int size);

    /*
    function name: reHeapDown
    function: swaps current node with largest of the child node
    input: int[], int, int
    pre-condition: root element should be deleted
    output: none
    post-condition: value at index position placed properly in the heap
    */
    void reHeapDown(int heap[], int size, int index);

    /*
    function name: deleteRoot
    function: deletes the root element
    input: int[], int*
    pre-condition: size > 0
    output: int
    post-condition: root element deleted
    */
    int deleteRoot(int heap[], int *size);

    /*
    function name: construct
    function: creates new heap from given elements
    input: int[], int[], int*
    pre-condition: none
    output: none
    post-condition: new heap constructed
    */
    void construct(int arr[], int heap[], int *size);

    /*
    function name: sort
    function: sorts the elements in the heap in ascending order
    input: int[], int
    pre-condition: size > 0
    output: none
    post-condition: sorted heap is displayed
    */
    void sort(int heap[], int size);
#endif