/*
    AUTHOR: MCA.2104
    PROGRAM: GRAPH ADJACENCY LIST
    DATE CREATED: 25 OCT 2021
    DATE MODIFIED: 27 OCT 2021
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>
#include"2104_gal.h"

void main(){
    int option, vertexCreate, edgeCreate, edgeDel, vertexDel;
    char vName, srcName, destName;
    graphNd *graph;
    vertexNd *vertex;
    linkNd *link;
    option = 1;
    graph = createGraph();
    do{
        printf("\nEnter 1 to create new graph.");
        printf("\nEnter 2 to add new vertex.");
        printf("\nEnter 3 to add new edge.");
        printf("\nEnter 4 to do Depth First Search.");
        printf("\nEnter 5 to do Breadth First Search.");
        printf("\nEnter 6 to delete an edge.");
        printf("\nEnter 7 to delete a vertex.");
        printf("\nEnter 0 to exit.");
        printf("\nEnter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1:{
                //create new graph
                graph = createGraph();
                if(graph)
                    printf("\nNew graph adjacency list created.");
                else
                    printf("\nGraph could not be created. Memory overflow. Try again.");
                break;
            }
            case 2:{
                //add new vertex
                printf("\nEnter name of vertex: ");
                scanf(" %c", &vName);
                vertexCreate = insertVertex(graph, vName);
                if(vertexCreate == 1)
                    printf("\nNew vertex added in the graph.");
                else
                    printf("\nVertex could not be created. Memory overflow. Try again.");
                break;
            }
            case 3:{
                //add new edge
                printf("\nEnter name of source vertex: ");
                scanf(" %c", &srcName);
                printf("\nEnter name of destination vertex: ");
                scanf(" %c", &destName);
                edgeCreate = insertEdge(graph, srcName, destName);
                if(edgeCreate == 1)
                    printf("\nNew edge added in the graph.");
                else if(edgeCreate == -1)
                    printf("\nEdge could not be created. Memory overflow. Try again.");
                else if(edgeCreate == -2)
                    printf("\nSource vertex could not be found. Enter valid input. Try again.");
                else if(edgeCreate == -3)
                    printf("\nDestination vertex could not be found. Enter valid input. Try again.");
                break;
            }
            case 4:{
                //DFS
                if(graph->vertextCount == 0)
                    printf("\nGraph have no vertices.");
                else
                    DFS(graph);
                break;
            }
            case 5:{
                //BFS
                if(graph->vertextCount == 0)
                    printf("\nGraph have no vertices.");
                else
                    BFS(graph);
                break;
            }
            case 6:{
                //delete an edge
                if(graph->vertextCount == 0)
                    printf("\nGraph have no vertices.");
                else{
                    printf("\nEnter name of source vertex: ");
                    scanf(" %c", &srcName);
                    printf("\nEnter name of destination vertex: ");
                    scanf(" %c", &destName);
                    edgeDel = deleteEdge(graph, srcName, destName);
                    if(edgeDel == 1)
                        printf("\nEdge deleted from the graph adjacency list.");
                    else
                        printf("\nEdge not be found in the graph adjacency list.");
                }
                break;
            }
            case 7:{
                //delete a vertex
                if(graph->vertextCount == 0)
                    printf("\nGraph have no vertices.");
                else{
                    printf("\nEnter name of vertex: ");
                    scanf(" %c", &vName);
                    vertexDel = deleteVertex(graph, vName);
                    if(vertexDel == 1)
                        printf("\nVertex deleted from the graph adjacency list.");
                    else if(vertexDel == -1)
                        printf("\nVertex not found in the graph adjacency list.");
                    else
                        printf("\nVertex cannot be deleted. It is connected to other vertices.");
                }
                break;
            }
            case 0: break;
            default: printf("\nInvalid input. Enter a number between 0 to 10.");
        }
    }while(option != 0);
    destroyGraph(graph);
}