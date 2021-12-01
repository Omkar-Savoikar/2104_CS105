#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>

typedef struct graphNode graphNd;
typedef struct vertexNode vertexNd;
typedef struct linkNode linkNd;

struct graphNode{
    int vertextCount;
    struct vertexNode *firstVertex;
};

struct vertexNode{
    char vName;
    short in_degree, out_degree;
    short processed;
    struct vertexNode *nextVertex;
    struct linkNode *firstlink;
};

struct linkNode{
    struct vertexNode *destination;
    struct linkNode *nextLink;
};

graphNd* createGraph(){
    graphNd* graph;
    graph = (graphNd *)malloc(sizeof(graphNd));
    if(graph){
        graph->vertextCount = 0;
        graph->firstVertex = NULL;
    }
    return graph;
}

void BFS(graphNd *graph){
    queueType q;
    vertexNd *temp;
    linkNd *ltemp;
    char vName;
    temp = graph->firstVertex;
    while(temp != NULL){
        temp->processed = 0;
        temp = temp->nextVertex;
    }
    q = queueCreate();
    temp = graph->firstVertex;
    while(temp != NULL){
        if(temp->processed == 0){
            enqueue(temp->vName, &q);
            temp->processed = 1;
        }
        strcpy(vName, dequeue(&q));
        printf("\n%c", vName);
        temp->processed = 2;
        ltemp = temp->firstlink;
        while(ltemp != NULL)
            if(ltemp->destination->processed == 0){
                enqueue(temp->vName, &q);
                temp->processed = 1;
            }
        temp = temp->nextVertex;
    }
    queueDelete(&q);
}

void DFT(graphNd *graph){
    stackType s;
    vertexNd *temp;
    linkNd *ltemp;
    char vName;
    temp = graph->firstVertex;
    while(temp != NULL){
        temp->processed = 0;
        temp = temp->nextVertex;
    }
    temp = graph->firstVertex;
    s = stackCreate();
    if(temp->processed == 0){
        stackPush(temp->vName, &s);
        temp->processed = 1;
    }
    else if(temp->processed == 1){
        strcpy(vName, stackPop(&s));
        printf("%c", vName);
        temp->processed = 2;
        ltemp = temp->firstlink;
        while(ltemp != NULL)
            if(ltemp->destination->processed == 0){
                stackPush(temp->vName, &s);
                temp->processed = 1;
            }
        //pop a vertex
        //print vertex name
        //processed = 2
        //push all vertices from adj list of vertex if their processed = 0 and make their processed = 1
    }
    stackDelete(&s);
    //destroy stack
}

int searchVertex(graphNd *graph, char vName[]){
    vertexNd *temp;
    int success = 0;
    temp = graph->firstVertex;
    while(temp != NULL){
        if(strcmp(temp->vName, vName) == 0){
            success = 1;
            break;
        }
        temp = temp->nextVertex;
    }
    return(success);
}

int searchEdge(graphNd *graph, char srcName[], char destName[]){
    vertexNd *vtemp;
    linkNd *ltemp;
    int success = 0;
    vtemp = graph->firstVertex;
    while(vtemp != NULL){
        if(strcmp(vtemp->vName, srcName) == 0){
            success = 1;
            break;
        }
        vtemp = vtemp->nextVertex;
    }
    if(success == 1){
        success = 0;
        ltemp = vtemp->firstlink;
        while(ltemp != NULL){
            if(strcmp(ltemp->destination->vName, destName) == 0){
                success = 1;
                break;
            }
            ltemp = ltemp->nextLink;
        }
    }
    return(success);
}

bool insertVertex(graphNd *graph, char name[]){
    vertexNd *newVertex;
    newVertex = (vertexNd *)malloc(sizeof(vertexNd));
    if(newVertex){
        strcpy(newVertex->vName, name);
        newVertex->in_degree = 0;
        newVertex->out_degree = 0;
        newVertex->processed = 0;
        newVertex->nextVertex = NULL;
        newVertex->firstlink = NULL;
        if(graph->firstVertex == NULL)
            graph->firstVertex = newVertex;
        else{
            vertexNd *temp;
            temp = graph->firstVertex;
            while(temp->nextVertex != NULL)
                temp = temp->nextVertex;
            temp->nextVertex = newVertex;
        }
        (graph->vertextCount)++;
        return true;
    }
    else
        return false;
}

int insertEdge(graphNd *graph, char srcName[], char destName[]){
    //return 1: success
    //return -1: memory couldnt be created
    //return -2: source doesnt exist
    //return -3: destination doesnt exist
    linkNd *newLink, *ltemp;
    vertexNd *src, *dest, *temp;
    int success = 0;
    src = graph->firstVertex;
    //src = searchVertex(graph, srcName);
    //dest = searchVertex(graph, destName);
    while(src != NULL){
        if(strcmp(src->vName, srcName) == 0){
            success = 1;
            break;
        }
        src = src->nextVertex;
    }
    if(success == 1){
        dest = graph->firstVertex;
        while(dest != NULL){
            if(strcmp(dest->vName, destName) == 0){
                success = 0;
                break;
            }
            dest = dest->nextVertex;
        }
        if(success == 0){
            newLink = (linkNd *)malloc(sizeof(linkNd));
            if(newLink){
                newLink->destination = dest;
                newLink->nextLink = NULL;
                temp = graph->firstVertex;
                while(temp != src)
                    temp = temp->nextVertex;
                ltemp = temp->firstlink;
                while(ltemp->nextLink != NULL)
                    ltemp = ltemp->nextLink;
                ltemp->nextLink = newLink;
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

int deleteEdge(graphNd* graph, char srcName[], char destName[]){
    //return 1: success
    //return -1: source not found in the graph adjacency list
    //return -2: destination not found in the graph adjacency list
    vertexNd *vertex;
    linkNd *prev, *del;
    int success = 0;
    vertex = graph->firstVertex;
    while(vertex != NULL){
        if(strcmp(vertex->vName, srcName) == 0){
            // Source found
            success = 1;
            break;
        }
        vertex = vertex->nextVertex;
    }
    if(success == 1){
        del = vertex->firstlink;
        while(del != NULL){
            if(strcmp(del->destination, destName) == 0){
                // Edge found
                success = 0;
                break;
            }
            prev = del;
            del = del->nextLink;
        }
        if(success == 0){
            prev->nextLink = del->nextLink;
            free(del);
            (vertex->out_degree)--;
            vertex = graph->firstVertex;
            while(vertex != NULL){
                if(strcmp(vertex->vName, destName) == 0){
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

int deleteVertex(graphNd* graph, char vName[]){
    //return 1: success
    //return -1: vertex found but in degree or out degree is not 0
    //return -2: vertex not found
    vertexNd *prev, *del;
    int success = 0;
    prev = graph->firstVertex;
    while(del != NULL){
        if(strcmp(del->vName, vName) == 0){
            success = 1;
            break;
        }
        prev = del;
        del = del->nextVertex;
    }
    if(success == 1){
        if((prev->nextVertex->in_degree != 0) || (prev->nextVertex->out_degree != 0))
            return(-1);
        prev->nextVertex = del->nextVertex;
        free(del);
        return(1);
    }
    return(-2);
}

void destroyGraph(graphNd *graph){
    //destroy graph g
}

void main(){
    int option, edgeCreate, edgeDel, vertexDel;
    bool success;
    char vName, srcName, destName;
    graphNd *graph;
    vertexNd *vertex;
    linkNd *link;
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
                scanf("%s", vName);
                success = insertVertex(graph, vName);
                if(success)
                    printf("\nNew vertex added in the graph.");
                else
                    printf("\nVertex could not be created. Memory overflow. Try again.");
                break;
            }
            case 3:{
                //add new edge
                printf("\nEnter name of source vertex: ");
                scanf("%s", srcName);
                printf("\nEnter name of destination vertex: ");
                scanf("%s", destName);
                edgeCreate = insertEdge(graph, srcName, destName);
                if(edgeCreate = 1)
                    printf("\nNew edge added in the graph.");
                else if(edgeCreate = -1)
                    printf("\nEdge could not be created. Memory overflow. Try again.");
                else if(edgeCreate = -2)
                    printf("\nSource vertex could not be found. Enter valid input. Try again.");
                else if(edgeCreate = -3)
                    printf("\nDestination vertex could not be found. Enter valid input. Try again.");
                break;
            }
            case 4:{
                //DFS
                break;
            }
            case 5:{
                //BFS
                break;
            }
            case 6:{
                //delete an edge
                edgeDel = deleteEdge(graph, srcName, destName);
                if(edgeDel == 1)
                    printf("\nEdge deleted from the graph adjacency list.");
                else
                    printf("\nEdge not be found in the graph adjacency list.");
                break;
            }
            case 7:{
                //delete a vertex
                vertexDel = deleteVertex(graph, vName);
                if(vertexDel == 1)
                    printf("\nVertex deleted from the graph adjacency list.");
                else if(vertexDel == -1)
                    printf("\nVertex not found in the graph adjacency list.");
                else
                    printf("\nVertex cannot be deleted. It is connected to other vertices.");
                break;
            }
            case 0: break;
            default: printf("\nInvalid input. Enter a number between 0 to 10.");
        }
        //switch case
    }while(option != 0);
    destroyGraph(graph);
}