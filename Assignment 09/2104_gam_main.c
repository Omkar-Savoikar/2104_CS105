/*
    AUTHOR: MCA.2104
    PROGRAM: matrix ADJACENCY MATRIX
    DATE CREATED: 29 OCT 2021
    DATE MODIFIED: 29 OCT 2021
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>
#include"2104_gam.h"

void main(){
    int option, vertexNum, check, i;
    char vName, srcName, destName;
    graphNd *matrix;
    option = 1;
    printf("\nEnter number of vectors: ");
    scanf("%d", &vertexNum);
    matrix = createMatrix(vertexNum);
    if(matrix)
        printf("\nNew matrix adjacency matrix created.");
    else
        printf("\nMatrix could not be created. Memory overflow. Try again.");
    for(i=0; i<vertexNum; i++){
        printf("\nEnter name of vertex: ");
        scanf(" %c", &vName);
        insertVertex(matrix, vName, i);
        printf("\nNew vertex added in the matrix.");
    }
    do{
        printf("\nEnter 1 to create new matrix.");
        printf("\nEnter 2 to add new edge.");
        printf("\nEnter 3 to do Depth First Search.");
        printf("\nEnter 4 to do Breadth First Search.");
        printf("\nEnter 5 to delete an edge.");
        printf("\nEnter 0 to exit.");
        printf("\nEnter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1:{
                //create new matrix
                printf("\nEnter number of vectors: ");
                scanf("%d", &vertexNum);
                matrix = createMatrix(vertexNum);
                if(matrix)
                    printf("\nNew matrix adjacency matrix created.");
                else{
                    printf("\nMatrix could not be created. Memory overflow. Try again.");
                    break;
                }
                for(i=0; i<vertexNum; i++){
                    printf("\nEnter name of vertex: ");
                    scanf(" %c", &vName);
                    insertVertex(matrix, vName, i);
                    printf("\nNew vertex added in the matrix.");
                }
                break;
            }
            case 2:{
                //add new edge
                printf("\nEnter name of source vertex: ");
                scanf(" %c", &srcName);
                printf("\nEnter name of destination vertex: ");
                scanf(" %c", &destName);
                check = insertEdge(matrix, srcName, destName);
                if(check == 1)
                    printf("\nNew edge added in the matrix.");
                else if(check == -1)
                    printf("\nSource vertex could not be found. Enter valid input. Try again.");
                else if(check == -2)
                    printf("\nDestination vertex could not be found. Enter valid input. Try again.");
                break;
            }
            case 3:{
                //DFS
                if(matrix->vertextCount == 0)
                    printf("\nMatrix have no vertices.");
                else
                    DFS(matrix);
                break;
            }
            case 4:{
                //BFS
                if(matrix->vertextCount == 0)
                    printf("\nMatrix have no vertices.");
                else
                    BFS(matrix);
                break;
            }
            case 5:{
                //delete an edge
                if(matrix->vertextCount == 0)
                    printf("\nMatrix have no vertices.");
                else{
                    printf("\nEnter name of source vertex: ");
                    scanf(" %c", &srcName);
                    printf("\nEnter name of destination vertex: ");
                    scanf(" %c", &destName);
                    check = deleteEdge(matrix, srcName, destName);
                    if(check == 1)
                        printf("\nEdge deleted from the matrix adjacency list.");
                    else
                        printf("\nEdge not be found in the matrix adjacency list.");
                }
                break;
            }
            case 0: break;
            default: printf("\nInvalid input. Enter a number between 0 to 10.");
        }
    }while(option != 0);
    destroyMatrix(matrix);
}