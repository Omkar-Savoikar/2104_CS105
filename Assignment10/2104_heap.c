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

void swap(EleType *x, EleType *y) {
    EleType temp = *x;
    *x = *y;
    *y = temp;
}

void reHeapUp(EleType heap[], int *index) {
    int parent;
    if (*index > 0) {
        parent = (*index-1)/2;
        if (heap[parent] < heap[*index]) {
            swap(&heap[parent], &heap[*index]);
            reHeapUp(heap, &parent);
        }
    }
}

void insertElement (EleType heap[], int *size, EleType value) {
    int i;
    heap[*size] = value;
    i = *size;
    reHeapUp(heap, &i);
    *size = *size + 1;
}

void display(EleType heap[], int size){
    int i;
    printf("\nHeap array:");
    for (i = 0; i < size; i++)
        printf("\n%d", heap[i]);
}

void reHeapDown(EleType heap[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if ((left < size) && (heap[left] > heap[largest]))
        largest = left;
    if ((right < size) && (heap[right] > heap[largest]))
        largest = right;
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        reHeapDown(heap, size, largest);
    }
}

void sort(EleType heap[], int size) {
    int i, j, tsize;
    tsize = size-1;
    for (i = 0; i < size; i++){
        swap(&heap[0], &heap[tsize]);
        reHeapDown(heap, tsize, 0);
        tsize--;
    }
    printf("\nSorted heap:");
    for (i = 0; i < size; i++)
        printf("\n%d", heap[i]);
}

EleType deleteRoot(EleType heap[], int *size) {
    EleType temp = heap[0];
    if ((*size) != 1) {
        swap(&heap[0], &heap[(*size)-1]);
        reHeapDown(heap, *size-1, 0);
    }
    (*size)--;
    return temp;
}

void construct(EleType arr[], EleType heap[], int *size) {
    int i, n;
    n = *size;
    *size = 0;
    for (i = 0; i < n; i++)
        insertElement(heap, &(*size), arr[i]);
    display(heap, *size);
}