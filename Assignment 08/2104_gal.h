/*
    AUTHOR: MCA.2104
    PROGRAM: GRAPH ADJACENCY LIST
    DATE CREATED: 25 OCT 2021
    DATE MODIFIED: 27 OCT 2021
*/
//DS Designer
#ifndef GRAPH_ADJACENCY
    #define GRAPH_ADJACENCY
    
    typedef char EleType;

    struct graphNode{
        int vertextCount;
        struct vertexNode *firstVertex;
    };

    struct vertexNode{
        EleType vName;
        short in_degree, out_degree;
        short processed;
        struct vertexNode *nextVertex;
        struct linkNode *firstlink;
    };

    struct linkNode{
        //float weight;
        struct vertexNode *destination;
        struct linkNode *nextLink;
    };
    
    typedef struct graphNode graphNd;
    typedef struct vertexNode vertexNd;
    typedef struct linkNode linkNd;

    /*
        function name: createGraph
        function: Create an empty graph
        input: none
        pre-condition: none
        output: graphNd* type
        post-condition: empty graph is created
    */
    graphNd* createGraph();

    /*
        function name: insertVertex
        function: Enters new vertex in the graph
        input: graphNd*, EleType
        pre-condition: graph exists
        output: 1 if vertex added, otherwise -1
        post-condition: New verted added in the graph
    */
    int insertVertex(graphNd *graph, EleType name);

    /*
        function name: insertEdge
        function: Inserts an edge between two vertices
        input: graphNd*, EleType, EleType
        pre-condition: graph exists
        output: 1 if edge inserted success, -1 if memory couldnt be created, -2 if source doesnt exist, -3 if destination doesnt exist
        post-condition: 
    */
    int insertEdge(graphNd *graph, EleType srcName, EleType destName);

    /*
        function name: BFS
        function: Displays names of vertices in graph using Breadth First Seach method
        input: graphNd*
        pre-condition: graph exists and is not empty
        output: none
        post-condition: none
    */
    void BFS(graphNd *graph);

    /*
        function name: DFS
        function: Displays names of vertices in graph using Depth First Seach method
        input: graphNd*
        pre-condition: graph exists and is not empty
        output: none
        post-condition: none
    */
    void DFS(graphNd *graph);

    /*
        function name: deleteEdge
        function: Deletes an edge between two vertices from the graph and free the memory allocated
        input: graphNd*, EleType, EleType
        pre-condition: graph exists and is not empty
        output: 1 if edge deleted, otherwise -1
        post-condition: Edge is deleted
    */
    int deleteEdge(graphNd* graph, EleType srcName, EleType destName);

    /*
        function name: deleteVertex
        function: Deletes a vertex from the graph and free the memory allocated
        input: graphNd*, EleType
        pre-condition: graph exists and is not empty
        output: 1 if success, -1 if source not found in the graph adjacency list, -2 if destination not found in the graph adjacency list
        post-condition: Vertex is deleted
    */
    int deleteVertex(graphNd* graph, EleType vName);

    /*
        function name: destroyGraph
        function: Delete the graph
        input: graphNd*
        pre-condition: graph exist
        output: none
        post-condition: All the edges and vertices from the graph are deleted and free the memory allocated
    */
    void destroyGraph(graphNd *graph);
#endif