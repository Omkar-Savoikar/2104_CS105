/*
    AUTHOR: MCA.2104
    PROGRAM: HUFFMAN'S ALGORITHM
    DATE CREATED: 29 DEC 2021
    DATE MODIFIED: 04 JAN 2022
*/
//DS Designer
#ifndef HUFFMAN
    #define HUFFMAN

    typedef struct MinHeapNode heapNd;
    typedef struct MinHeap heap;

    struct MinHeapNode {
        char data;
        int freq;
        struct MinHeapNode *left, *right;
    };

    struct MinHeap {
        int size;
        int capacity;
        struct MinHeapNode** array;
    };

    /*
    function name: swap
    function: swaps two values
    input: heapNd**, heapNd**
    pre-condition: none
    output: none
    post-condition: values at provided pointers swapped
    */
    void swap(heapNd** a, heapNd** b);

    /*
    function name: reHeapUp
    function: swaps current node with parent if current node value is larger than parent
    input: heap*, int*
    pre-condition: value should be inserted in the heap
    output: none
    post-condition: value at index position placed properly in the heap
    */
    void reHeapUp(heap* minHeap, int *index);

    /*
    function name: insertElement
    function: inserts element in the heap
    input: heap*, heapNd*
    pre-condition: none
    output: none
    post-condition: new value inserted in the heap at proper position
    */
    void insertElement(heap* minHeap, heapNd* minHeapNode);

    /*
    function name: printArr
    function: displays all the elements in the array
    input: int[], int
    pre-condition: none
    output: none
    post-condition: all elements in the array are displayed
    */
    void printArr(int arr[], int n);

    /*
    function name: reHeapDown
    function: places node at index position at proper position in the heap
    input: heap*, int
    pre-condition: none
    output: none
    post-condition: value at index position placed properly in the heap
    */
    void reHeapDown(heap* minHeap, int index);

    /*
    function name: deleteRoot
    function: deletes the root element
    input: heap*
    pre-condition: none
    output: heapNd*
    post-condition: root element deleted
    */
    heapNd* deleteRoot(heap* minHeap);

    /*
    function name: buildTree
    function: creates Huffman heap from given elements
    input: strNode[], strNode[], int*
    pre-condition: none
    output: none
    post-condition: Huffman heap constructed
    */
    heapNd* buildTree(char data[], int freq[], int size);

    /*
    function name: displayCodes
    function: generates Huffman code for each element
    input: strNode[], int[], int
    pre-condition: none
    output: none
    post-condition: Huffman code generates for each element
    */
    void displayCodes(heapNd* root, int arr[], int index);
#endif