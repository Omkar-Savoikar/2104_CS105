/*
    AUTHOR: MCA.2104
    PROGRAM: MERGE SORT
    DATE CREATED: 30 DEC 2021
    DATE MODIFIED: 31 DEC 2021
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>
#include"2104_merge.h"

void main() {
    int option, arr[50], value, size;
    int i;
    option = 1;
    size = 0;
    do {
        printf("\nPress 1 to construct new array");
        printf("\nPress 2 to insert new element.");
        printf("\nPress 3 to display array");
        printf("\nPress 4 to sort array");
        printf("\nPress 0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                //construct heap
                printf("\nEnter array length: ");
                scanf("%d", &size);
                if (size > 50)
                    printf("\nMax size allowed = 50. Enter length less than or equal to 50.");
                for (i = 0; i < size; i++){
                    printf("\nEnter element value: ");
                    scanf("%d", &arr[i]);
                }
                construct(arr, heap, &size);
                break;
            }
            case 2: {
                //insert new element
                if (size == 50)
                    printf("\nMemory full. Cannot insert new element.");
                printf("\nEnter the value: ");
                scanf("%d", &value);
                insertElement(heap, &size, value);
                printf("\nValue %d added successfully to the heap.", value);
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
                sort(heap, 0, size-1);
                printf("\nArray sorted.");
                display(heap, size);
                break;
            }
            case 0: break;
            default: printf("\nInvalid input. Enter a number between 0 to 4.");
        }
    } while (option != 0);
}