/*
    AUTHOR: MCA.2104
    PROGRAM: MERGE SORT
    DATE CREATED: 30 DEC 2021
    DATE MODIFIED: 31 DEC 2021
*/
//DS Designer
#ifndef HEAP
    #define HEAP

    int heap[50];

    /*
    function name: insertElement
    function: inserts an element at the end of array
    input: int[], int*, int
    pre-condition: size != 50
    output: none
    post-condition: new value inserted at the end of array
    */
    void insertElement(int heap[], int *size, int value);

    /*
    function name: display
    function: displays all the elements in the array
    input: int[], int
    pre-condition: size > 0
    output: none
    post-condition: all elements in the array are displayed
    */
    void display(int heap[], int size);

    /*
    function name: construct
    function: creates new array from given elements
    input: int[], int[], int*
    pre-condition: none
    output: none
    post-condition: new array constructed
    */
    void construct(int arr[], int heap[], int *size);

    /*
    function name: merge
    function: merges two arrays into one in ascending order
    input: int[], int, int, int
    pre-condition: call sort function
    output: none
    post-condition: two arrays merged into one in ascending order
    */
    void merge(int heap[], int low, int mid, int high);

    /*
    function name: sort
    function: divides array into two arrays and merges them in ascending order
    input: int[], int, int
    pre-condition: size > 0
    output: none
    post-condition: array is sorted in ascending order
    */
    void sort(int heap[], int low, int high);
#endif