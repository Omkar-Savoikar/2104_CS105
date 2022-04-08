/*
    AUTHOR: MCA.2104
    PROGRAM: MERGE SORT
    DATE CREATED: 30 DEC 2021
    DATE MODIFIED: 31 DEC 2021
*/
//DS DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>
#include"2104_merge.h"

void insertElement(int heap[], int *size, int value) {
    heap[*size] = value;
    *size = *size + 1;
}

void display(int heap[], int size) {
    int i;
    printf("\nArray:");
    for (i = 0; i < size; i++)
        printf(" %d", heap[i]);
}

void construct(int arr[], int heap[], int *size) {
    int i, n;
    n = *size;
    *size = 0;
    for (i = 0; i < n; i++)
        insertElement(heap, &(*size), arr[i]);
    display(heap, *size);
}

void merge(int heap[], int low, int mid, int high) {
    int i, j, k, n, heap1[50], heap2[50];
    j = 0;
    for (i = low; i <= mid; i++) //store values from low to mid in heap1
        heap1[i] = heap[i];
    for (;i <= high; i++, j++) //store values from mid+1 to high in heap2
        heap2[j] = heap[i];
    i = low; //index for heap
    j = low; //index for low to mid
    k = mid + 1; //index for mid+1 to high
    n = 0; //index for heap2
    while ((j <= mid) && (k <= high)) {
        if (heap1[j] < heap2[n])
            heap[i] = heap1[j++];
        else {
            heap[i] = heap2[n++];
            k++;
        }
        i++;
    }
    while (j <= mid)
        heap[i++] = heap1[j++];
    while (k <= high) {
        heap[i++] = heap2[n++];
        k++;
    }
}

void sort(int heap[], int low, int high) {
    int i, j, tsize, mid;
    if (low < high) {
        j = 0;
        mid = (low + high) / 2;
        sort(heap, low, mid);
        sort(heap, mid+1, high);
        merge(heap, low, mid, high);
    }
}