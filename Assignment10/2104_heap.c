/*
    AUTHOR: MCA.2104
    PROGRAM: HEAP SORT
    DATE CREATED: 29 DEC 2021
    DATE MODIFIED: 30 DEC 2021
*/
//DS DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>
#include"2104_heap.h"

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reHeapUp(int heap[], int *index) {
    int parent;
    if (*index > 0) {
        parent = (*index-1)/2;
        if (heap[parent] < heap[*index]) {
            swap(&heap[parent], &heap[*index]);
            reHeapUp(heap, &parent);
        }
    }
}

void insertElement (int heap[], int *size, int value) {
    int i;
    heap[*size] = value;
    i = *size;
    reHeapUp(heap, &i);
    *size = *size + 1;
}

void display(int heap[], int size){
    int i;
    printf("\nHeap array:");
    for (i = 0; i < size; i++)
        printf("\n%d", heap[i]);
}

void reHeapDown(int heap[], int size, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    if ((leftChild < size) && (heap[leftChild] > heap[largest]))
        largest = leftChild;
    if ((rightChild < size) && (heap[rightChild] > heap[largest]))
        largest = rightChild;
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        reHeapDown(heap, size, largest);
    }
}

int deleteRoot(int heap[], int *size) {
    int temp = heap[0];
    if ((*size) != 1) {
        swap(&heap[0], &heap[(*size)-1]);
        reHeapDown(heap, *size-1, 0);
    }
    (*size)--;
    return temp;
}

void construct(int arr[], int heap[], int *size) {
    int i, n;
    n = *size;
    *size = 0;
    for (i = 0; i < n; i++)
        insertElement(heap, &(*size), arr[i]);
    display(heap, *size);
}

void sort(int heap[], int size) {
    int i, j, tsize;
    tsize = size;
    for (i = 0; i < tsize; i++){
        size--;
        swap(&heap[0], &heap[size]);
        reHeapDown(heap, size-1, 0);
    }
    size = tsize;
    printf("\nSorted heap:");
    for (i = 0; i < size; i++)
        printf("\n%d", heap[i]);
}