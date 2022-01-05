/*
    AUTHOR: MCA.2104
    PROGRAM: HEAP SORT
    DATE CREATED: 29 DEC 2021
    DATE MODIFIED: 30 DEC 2021
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include"2104_heap.h"

void main() {
    EleType value, arr[50];
    int option;
    int i;
    option = 1;
    size = 0;
    do {
        printf("\nPress 1 to insert new element.");
        printf("\nPress 2 to construct heap");
        printf("\nPress 3 to display heap");
        printf("\nPress 4 to sort heap");
        printf("\nPress 5 to delete root element");
        printf("\nPress 0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                //insert new element
                if (size == 50)
                    printf("\nMemory full. Cannot insert new element.");
                printf("\nEnter the value: ");
                scanf("%d", &value);
                insertElement(heap, &size, value);
                printf("\nValue %d added successfully to the heap.", value);
                break;
            }
            case 2: {
                //construct heap
                printf("\nEnter array length: ");
                scanf("%d", &size);
                if (size > 50) {
                    printf("\nMax size allowed = 50. Enter length less than or equal to 50.");
                    exit(1);
                }
                for (i = 0; i < size; i++){
                    printf("\nEnter element value: ");
                    scanf("%d", &arr[i]);
                }
                construct(arr, heap, &size);
                break;
            }
            case 3: {
                //display heap
                if (size == 0) {
                    printf("\nNo elements in heap");
                    break;
                }
                display(heap, size);
                break;
            }
            case 4: {
                //sort heap
                if (size == 0) {
                    printf("\nNo elements in heap");
                    break;
                }
                for (i = 0; i < size; i++)
                    arr[i] = heap[i];
                sort(arr, size);
                break;
            }
            case 5: {
                //delete root element
                if (size == 0) {
                    printf("\nNo elements in heap");
                    break;
                }
                value = deleteRoot(heap, &size);
                printf("\nRoot value = %d deleted.", value);
                break;
            }
            case 0: break;
            default: printf("\nInvalid input. Enter a number between 0 to 5.");
        }
    } while (option != 0);
}