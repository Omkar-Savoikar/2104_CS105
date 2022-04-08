/*
    AUTHOR: MCA.2104
    PROGRAM: matrix ADJACENCY MATRIX
    DATE CREATED: 29 OCT 2021
    DATE MODIFIED: 01 NOV 2021
*/
//DS Designer
#ifndef MATRIX_ADJACENCY
    #define MATRIX_ADJACENCY

    typedef char EleType;
    typedef struct graphNode graphNd;

    struct graphNode{
        int vertextCount; 
        EleType *vertexVector;
        int **adjMatrix;
    };

    /*
        function name: creatematrix
        function: Create an empty matrix
        input: int
        pre-condition: none
        output: graphNd* type
        post-condition: empty matrix is created
    */
    graphNd* createMatrix(int n);

    /*
        function name: insertVertex
        function: Enters new vertex in the matrix
        input: graphNd*, EleType
        pre-condition: matrix exists
        output: 1 if vertex added, otherwise -1
        post-condition: New verted added in the matrix
    */
    void insertVertex(graphNd *matrix, EleType name, int vertexNum);

    /*
        function name: insertEdge
        function: Inserts an edge between two vertices
        input: graphNd*, EleType, EleType
        pre-condition: matrix exists
        output: 1 if edge inserted success, -1 if memory couldnt be created, -2 if source doesnt exist, -3 if destination doesnt exist
        post-condition: 
    */
    int insertEdge(graphNd *matrix, EleType srcName, EleType destName);

    /*
        function name: BFS
        function: Displays names of vertices in matrix using Breadth First Seach method
        input: graphNd*
        pre-condition: matrix exists and is not empty
        output: none
        post-condition: none
    */
    void BFS(graphNd *matrix);

    /*
        function name: DFS
        function: Displays names of vertices in matrix using Depth First Seach method
        input: graphNd*
        pre-condition: matrix exists and is not empty
        output: none
        post-condition: none
    */
    void DFS(graphNd *matrix);

    /*
        function name: deleteEdge
        function: Deletes an edge between two vertices from the matrix and free the memory allocated
        input: graphNd*, EleType, EleType
        pre-condition: matrix exists and is not empty
        output: 1 if edge deleted, otherwise -1
        post-condition: Edge is deleted
    */
    int deleteEdge(graphNd *matrix, EleType srcName, EleType destName);

    /*
        function name: destroymatrix
        function: Delete the matrix
        input: graphNd*
        pre-condition: matrix exist
        output: none
        post-condition: All the edges and vertices from the matrix are deleted and free the memory allocated
    */
    void destroyMatrix(graphNd *matrix);
#endif