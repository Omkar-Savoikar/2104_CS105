/*
    AUTHOR: MCA.2104
    PROGRAM: HUFFMAN'S ALGORITHM
    DATE CREATED: 29 DEC 2021
    DATE MODIFIED: 04 JAN 2022
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"2104_heap.h"

void main() {
    heapNd *tree;
	char arr[30];
	int freq[30], data[30], i, size;
    printf("\nEnter number of elements: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++) {
        printf("\nEnter the charachter: ");
        scanf(" %c", &arr[i]);
        printf("\nEnter the frequency: ");
        scanf("%d", &freq[i]);
    }
    tree = buildTree(arr, freq, size);
	displayCodes(tree, data, 0);
}