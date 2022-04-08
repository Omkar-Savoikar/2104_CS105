/*
    AUTHOR: MCA.2104
    PROGRAM: HUFFMAN'S ALGORITHM
    DATE CREATED: 29 DEC 2021
    DATE MODIFIED: 04 JAN 2022
*/
//DS DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include"2104_heap.h"

void swap(heapNd** a, heapNd** b) {
	heapNd* temp;
    temp = *a;
	*a = *b;
	*b = temp;
}

void reHeapDown(heap* minHeap, int index) {
	int smallest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
		smallest = left;
	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
		smallest = right;
	if (smallest != index) {
		swap(&minHeap->array[smallest], &minHeap->array[index]);
		reHeapDown(minHeap, smallest);
	}
}

heapNd* deleteRoot(heap* minHeap) {
	heapNd* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	(minHeap->size)--;
	reHeapDown(minHeap, 0);
	return temp;
}

void reHeapUp(heap* minHeap, int *index) {
    int parent;
    if (*index > 0) {
        parent = (*index-1)/2;
        if(minHeap->array[parent]->freq > minHeap->array[*index]->freq) {
            swap(&minHeap->array[parent], &minHeap->array[*index]);
            reHeapUp(minHeap, &parent);
        }
    }
}

void insertElement(heap* minHeap, heapNd* minHeapNode) {
    minHeap->array[minHeap->size] = minHeapNode;
    reHeapUp(minHeap, &(minHeap->size));
    (minHeap->size)++;
}

void printArr(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d", arr[i]);
}

heapNd* buildTree(char data[], int freq[], int size) {
	heapNd *left, *right, *top;
	heap* minHeap;
    int i ,n;
	minHeap = (heap*)malloc(sizeof(heap));
    minHeap->size = 0;
	minHeap->capacity = size;
	minHeap->array = (heapNd**)malloc(size * sizeof(heapNd*));
	for (i = 0; i < size; i++) {
		minHeap->array[i] = (heapNd*)malloc(sizeof(heapNd));
		minHeap->array[i]->left = NULL;
		minHeap->array[i]->right = NULL;
		minHeap->array[i]->data = data[i];
		minHeap->array[i]->freq = freq[i];
		reHeapUp(minHeap, &(minHeap->size));
		(minHeap->size)++;
	}
    while (minHeap->size != 1) {
        left = deleteRoot(minHeap);
		right = deleteRoot(minHeap);
		top = (heapNd*)malloc(sizeof(heapNd));
		top->data = '$';
		top->freq = (left->freq + right->freq);
		top->left = left;
		top->right = right;
		insertElement(minHeap, top);
	}
    return deleteRoot(minHeap);
}

void displayCodes(heapNd* root, int arr[], int index) {
	if (root->left) {
		arr[index] = 0;
		displayCodes(root->left, arr, index + 1);
	}
	if (root->right) {
		arr[index] = 1;
		displayCodes(root->right, arr, index + 1);
	}
	if ((!(root->left)) && (!(root->right))) {
		printf("\n%c: ", root->data);
		printArr(arr, index);
	}
}