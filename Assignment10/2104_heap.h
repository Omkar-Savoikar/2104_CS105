/*
    AUTHOR: MCA.2104
    PROGRAM: HEAP SORT
    DATE CREATED: 29 DEC 2021
    DATE MODIFIED: 30 DEC 2021
*/
//DS Designer
#ifndef HEAP
    #define HEAP

    typedef int EleType;
    EleType heap[50];
    int size;

    /*
    function name: swap
    function: swaps two values
    input: EleType*, EleType*
    pre-condition: none
    output: none
    post-condition: values at provided poEleTypeers swapped
    */
    void swap(EleType *x, EleType *y);

    /*
    function name: reHeapUp
    function: swaps current node with parent if current node value is larger than parent
    input: EleType[], EleType*
    pre-condition: value should be inserted in the heap
    output: none
    post-condition: value at index position placed properly in the heap
    */
    void reHeapUp(EleType heap[], EleType *index);

    /*
    function name: insertElement
    function: inserts element in the heap
    input: EleType[], EleType*, EleType
    pre-condition: size != 50
    output: none
    post-condition: new value inserted in the heap at proper position
    */
    void insertElement(EleType heap[], EleType *size, EleType value);

    /*
    function name: display
    function: displays all the elements in the heap
    input: EleType[], EleType
    pre-condition: size > 0
    output: none
    post-condition: all elements in the heap are displayed
    */
    void display(EleType heap[], EleType size);

    /*
    function name: reHeapDown
    function: swaps current node with largest of the child node
    input: EleType[], EleType, EleType
    pre-condition: root element should be deleted
    output: none
    post-condition: value at index position placed properly in the heap
    */
    void reHeapDown(EleType heap[], EleType size, EleType index);

    /*
    function name: deleteRoot
    function: deletes the root element
    input: EleType[], EleType*
    pre-condition: size > 0
    output: EleType
    post-condition: root element deleted
    */
    EleType deleteRoot(EleType heap[], EleType *size);

    /*
    function name: construct
    function: creates new heap from given elements
    input: EleType[], EleType[], EleType*
    pre-condition: none
    output: none
    post-condition: new heap constructed
    */
    void construct(EleType arr[], EleType heap[], EleType *size);

    /*
    function name: sort
    function: sorts the elements in the heap in ascending order
    input: EleType[], EleType
    pre-condition: size > 0
    output: none
    post-condition: sorted heap is displayed
    */
    void sort(EleType heap[], EleType size);
#endif