/*
    AUTHOR: MCA.2104
    PROGRAM: GRAPH ADJACENCY LIST
    DATE CREATED: 25 OCT 2021
    DATE MODIFIED: 27 OCT 2021
*/
//DS DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>
#include"2104_stack.h"
#include"2104_queue.h"
#include"2104_gal.h"

graphNd* createGraph(){
    graphNd* graph;
    graph = (graphNd *)malloc(sizeof(graphNd));
    if(graph){
        graph->vertextCount = 0;
        graph->firstVertex = NULL;
    }
    return graph;
}

int insertVertex(graphNd *graph, EleType name){
    //return 1: success
    //return -1: memory couldnt be created
    vertexNd *newvertex =(vertexNd *) malloc (sizeof(vertexNd));
    vertexNd *temp;
    newvertex =(vertexNd *) malloc (sizeof(vertexNd));
    if (newvertex==NULL)
        return -1;
    newvertex->vName = name; 
    newvertex->in_degree=0;
    newvertex->out_degree=0;
    newvertex->processed=0;
    newvertex->firstlink = NULL;
    newvertex->nextVertex=NULL;
    if (graph->firstVertex==NULL){
        graph->firstVertex=newvertex;

    }
    else{
        temp = graph->firstVertex;
        while(temp->nextVertex!=NULL)
            temp=temp->nextVertex;
        temp->nextVertex=newvertex;
    }
    (graph->vertextCount)++;
    return 1;
}

int insertEdge(graphNd *graph, EleType srcName, EleType destName){
    //return 1: success
    //return -1: memory couldnt be created
    //return -2: source doesnt exist
    //return -3: destination doesnt exist
    linkNd *newLink, *temp;
    vertexNd *src, *dest;
    int success = -2;
    src = graph->firstVertex;
    while(src != NULL){
        if(src->vName == srcName){
            success = -1;
            break;
        }
        src = src->nextVertex;
    }
    if(success == -1){
        dest = graph->firstVertex;
        while(dest != NULL){
            if(dest->vName == destName){
                success = 1;
                break;
            }
            dest = dest->nextVertex;
        }
        if(success == 1){
            newLink = (linkNd *)malloc(sizeof(linkNd));
            if(newLink){
                newLink->destination = dest;
                newLink->nextLink = NULL;
                if(src->firstlink == NULL)
                    src->firstlink = newLink;
                else{
                    temp = src->firstlink;
                    while(temp->nextLink != NULL)
                        temp = temp->nextLink;
                    temp->nextLink = newLink;
                }
                (src->out_degree)++;
                (dest->in_degree)++;
                return(1); //Added new edge
            }
            return(-1); //Memory overflow
        }
        return(-3); //Destination not found
    }
    return(-2); //Source not found
}

void DFS(graphNd *graph){
    stackType s;
    vertexNd *temp, *pop;
    linkNd *ltemp;
    temp = graph->firstVertex;
    while(temp != NULL){
        temp->processed = 0;
        temp = temp->nextVertex;
    }
    temp = graph->firstVertex;
    s = stackCreate();
    while(temp != NULL){
        if (temp->processed == 0){
            stackPush(temp, &s);
            temp->processed = 1;
        }
        while(stackIsEmpty(s) == false){
            pop = stackPop(&s);
            printf("\n%c", pop->vName);
            pop->processed = 2;
            ltemp = pop->firstlink;
            while(ltemp != NULL){
                if(ltemp->destination->processed == 0){
                    stackPush(ltemp->destination, &s);
                    ltemp->destination->processed = 1;
                }
                ltemp = ltemp->nextLink;
            }
        }
        temp = temp->nextVertex;
    }
    stackDelete(&s);
}

void BFS(graphNd *graph){
    queueType q;
    vertexNd *temp, *deq;
    linkNd *ltemp;
    temp = graph->firstVertex;
    while(temp != NULL){
        temp->processed = 0;
        temp = temp->nextVertex;
    }
    q = queueCreate();
    temp = graph->firstVertex;
    while(temp != NULL){
        if(temp->processed == 0){
            enqueue(temp, &q);
            temp->processed = 1;
        }
        while(queueIsEmpty(q) == false){
            deq = dequeue(&q);
            printf("\n%c", deq->vName);
            deq->processed = 2;
            ltemp = deq->firstlink;
            while(ltemp != NULL){
                if(ltemp->destination->processed == 0){
                    enqueue(ltemp->destination, &q);
                    ltemp->destination->processed = 1;
                }
                ltemp = ltemp->nextLink;
            }
        }
        temp = temp->nextVertex;
    }
    queueDelete(&q);
}

int deleteEdge(graphNd* graph, EleType srcName, EleType destName){
    //return 1: success
    //return -1: source not found in the graph adjacency list
    //return -2: destination not found in the graph adjacency list
    vertexNd *vertex;
    linkNd *prev, *del;
    int success = -2;
    vertex = graph->firstVertex;
    while(vertex != NULL){
        if(vertex->vName == srcName){
            // Source found
            success = -1;
            break;
        }
        vertex = vertex->nextVertex;
    }
    if(success == -1){
        del = vertex->firstlink;
        prev = NULL;
        while(del != NULL){
            if(del->destination->vName == destName){
                // Edge found
                success = 1;
                break;
            }
            prev = del;
            del = del->nextLink;
        }
        if(success == 1){
            if(prev == NULL)
                vertex->firstlink = del->nextLink;
            else
                prev->nextLink = del->nextLink;
            free(del);
            (vertex->out_degree)--;
            vertex = graph->firstVertex;
            while(vertex != NULL){
                if(vertex->vName == destName){
                    // Reduce in degree of destination vertex
                    (vertex->in_degree)--;
                    break;
                }
                vertex = vertex->nextVertex;
            }
            return(1); // Deleted
        }
        return(-2); // Destination not found
    }
    return(-1); // Source not found
}

int deleteVertex(graphNd* graph, EleType vName){
    //return 1: success
    //return -1: vertex found but in degree or out degree is not 0
    //return -2: vertex not found
    vertexNd *prev, *del;
    int success = 0;
    del = graph->firstVertex;
    prev = NULL;
    while(del != NULL){
        if(del->vName == vName){
            success = 1;
            break;
        }
        prev = del;
        del = del->nextVertex;
    }
    if(success == 1){
        if((del->in_degree != 0) || (del->out_degree != 0))
            return(-2);
        if(prev == NULL)
            graph->firstVertex = del->nextVertex;
        else
            prev->nextVertex = del->nextVertex;
        free(del);
        (graph->vertextCount)--;
        return(1);
    }
    return(-1);
}

void destroyGraph(graphNd *graph){
    vertexNd *src;
    linkNd *dest;
    int delVertex, delEdge;
    delVertex = delEdge = 1;
    while((graph->firstVertex != NULL) && (delVertex == 1)){
        src = graph->firstVertex;
        while((src->firstlink != NULL) && (delEdge == 1))
            delEdge = deleteEdge(graph, src->vName, src->firstlink->destination->vName);
        delVertex = deleteVertex(graph, src->vName);
    }
}