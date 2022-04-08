/*
    AUTHOR: MCA.2104
    PROGRAM: GRAPH ADJACENCY MATRIX
    DATE CREATED: 29 OCT 2021
    DATE MODIFIED: 01 NOV 2021
*/
//DS DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>
#include"2104_stack.h"
#include"2104_queue.h"
#include"2104_gam.h"

graphNd* createMatrix(int n){
    graphNd* graph;
    int i, j;
    graph = (graphNd *)malloc(sizeof(graphNd));
    if(graph){
        graph->vertextCount = n;
        graph->vertexVector = (EleType *)malloc(n * sizeof(EleType));
        graph->adjMatrix = (int **)malloc(n* sizeof(int*));
        for(i=0; i<n; i++){
            graph->vertexVector[i] = ' '; //making vector empty
            graph->adjMatrix[i] = (int *)malloc(n * sizeof(int));
            for(j=0; j<n; j++)
                graph->adjMatrix[i][j] = 0; //making edge 0
        }
    }
    return graph;
}

void insertVertex(graphNd *graph, EleType name, int vertexNum){
    graph->vertexVector[vertexNum] = name;
}

int insertEdge(graphNd *graph, EleType srcName, EleType destName){
    //return 1: success
    //return -1: source doesnt exist
    //return -2: destination doesnt exist
    int success = -2, count = 0, src, dest;
    while(count < graph->vertextCount){
        if(graph->vertexVector[count] == srcName){
            success = -1;
            src = count;
            break;
        }
        count++;
    }
    if(success == -1){
        count = 0;
        while(count < graph->vertextCount){
            if(graph->vertexVector[count] == destName){
                success = 1;
                dest = count;
                break;
            }
            count++;
        }
        if(success == 1){
            graph->adjMatrix[src][dest] = 1;
            return(1); //Added new edge
        }
        return(-2); //Destination not found
    }
    return(-1); //Source not found
}

void DFS(graphNd *graph){
    stackType s;
    int count = 0, i, j;
    int processed[20];
    char pop;
    for(count = 0; count < graph->vertextCount; count++)
        processed[count] = 0;
    count = 0;
    s = stackCreate();
    while(count < graph->vertextCount){
        if (processed[count] == 0){
            stackPush(graph->vertexVector[count], &s);
            processed[count] = 1;
        }
        while(stackIsEmpty(s) == false){
            pop = stackPop(&s);
            printf("\n%c", pop);
            for(i = 0; i < graph->vertextCount; i++)
                if(graph->vertexVector[i] == pop)
                    break;
            processed[i] = 2;
            for(j = 0; j < graph->vertextCount; j++)
                if(graph->adjMatrix[i][j] == 1)
                    if(processed[j] == 0){
                        stackPush(graph->vertexVector[j], &s);
                        processed[j] = 1;
                    }
        }
        count++;
    }
    stackDelete(&s);
}

void BFS(graphNd *graph){
    queueType q;
    int count = 0, i, j;
    int processed[20];
    char deq;
    for(count = 0; count < graph->vertextCount; count++)
        processed[count] = 0;
    count = 0;
    q = queueCreate();
    while(count < graph->vertextCount){
        if(processed[count] == 0){
            enqueue(graph->vertexVector[count], &q);
            processed[count] = 1;
        }
        while(queueIsEmpty(q) == false){
            deq = dequeue(&q);
            printf("\n%c", deq);
            for(i = 0; i < graph->vertextCount; i++)
                if(graph->vertexVector[i] == deq)
                    break;
            processed[i] = 2;
            for(j = 0; j < graph->vertextCount; j++)
                if(graph->adjMatrix[i][j] == 1)
                    if(processed[j] == 0){
                        enqueue(graph->vertexVector[j], &q);
                        processed[j] = 1;
                    }
        }
        count++;
    }
    queueDelete(&q);
}

int deleteEdge(graphNd* graph, EleType srcName, EleType destName){
    //return 1: success
    //return -1: source not found in the graph adjacency list
    //return -2: destination not found in the graph adjacency list
    int success = -2, count = 0, src, dest;
    while(count < graph->vertextCount){
        if(graph->vertexVector[count] == srcName){
            success = -1;
            src = count;
            break;
        }
        count++;
    }
    if(success == -1){
        count = 0;
        while(count < graph->vertextCount){
            if(graph->vertexVector[count] == destName){
                success = 1;
                dest = count;
                break;
            }
            count++;
        }
        if(success == 1){
            graph->adjMatrix[src][dest] = 0;
            return(1); //Added new edge
        }
        return(-2); //Destination not found
    }
    return(-1); //Source not found
}

void destroyMatrix(graphNd *graph){
    free(graph);
}