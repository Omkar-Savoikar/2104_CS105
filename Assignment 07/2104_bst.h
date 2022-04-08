/*
    AUTHOR: MCA.2104
    PROGRAM: BINARY SEARCH TREE TRAVERSALS
    DATE CREATED: 18 OCT 2021
    DATE MODIFIED: 23 OCT 2021
*/
//DS Designer
#ifndef BST_H
    #define BST_H
    typedef int eleType;
    typedef struct bst_node node;
    typedef struct bst_tree BST_tree;

    struct bst_tree{
        struct bst_node *root;
        int count;
    };

    struct bst_node{
        eleType data;
        struct bst_node *left;
        struct bst_node *right;
    };

    /*
        function name: BST_create
        function: Allocates memory for a BST tree head node and returns its address
        pre-condition: None
        output: Head node pointer or null if overflow
        post-condition: Head allocated or memory overflow
    */
    BST_tree* BST_create();

    /*
        function name: BST_insert
        function: Inserts new data into the tree
        pre-condition: Tree is pointed to BST tree structure
        output: Success (true) or overflow (false)
        post-condition: Data is inserted, tree is updated / Memory overflow
    */
    bool BST_insert(BST_tree *b, eleType data);

    /*
        function name: _insert
        function: It uses recurssion to insert new data into a leaf node in the BST
        pre-condition: Application has called BST_insert which passes the tree root and pointer to new node
        output: Pointer to new node
        post-condition: Data is inserted, tree is updated.
    */
    node* _insert(node *b, node *ptr);

    /*
        function name: BST_traverse_inorder
        function: It uses recurssion to display tree data in inorder manner
        pre-condition: Tree is pointed to BST tree structure
        output: None
        post-condition: None
    */
    void BST_traverse_inorder(node *root);

    /*
        function name: BST_traverse_preorder
        function: It uses recurssion to display tree data in preorder manner
        pre-condition: Tree is pointed to BST tree structure
        output: None
        post-condition: None
    */
    void BST_traverse_preorder(node *root);

    /*
        function name: BST_traverse_postorder
        function: It uses recurssion to display tree data in postorder manner
        pre-condition: Tree is pointed to BST tree structure
        output: None
        post-condition: None
    */
    void BST_traverse_postorder(node *root);
    
    /*
        function name: BST_search
        function: Searches for a node in the BST tree
        pre-condition: Tree is pointed to BST tree structure
        output: Pointer to the node if it exists in the tree or else null
        post-condition: None
    */
   node* BST_search(node *root, eleType data);

    /*
        function name: _search
        function: It uses recurssion to search for the data in the BST tree
        pre-condition: Application has called BST_search which passes the tree root, data to be searched and boolean variable
        output: Pointer to the node if it exists in the tree or else null
        post-condition: None
    */
    node* _search(node* root, eleType data, bool *success);

    /*
        function name: BST_delete
        function: Deletes a node from the tree
        pre-condition: Tree exists
        output: True on success or false if key not found
        post-condition: Node is deleted and memory freed if key is found
    */
    bool BST_delete(BST_tree *tree, eleType data);

    /*
        function name: _delete
        function: Searches for node with key = data and if founcd deletes the node from the tree
        pre-condition: Application has called BST_delete which passes the tree root and value of data to be deleted
        output: Pointer to root or null if data not found
        post-condition: If key is found, delete the node from the tree and free the memory or else tree remains unchanged
    */
   node* _delete(node *root, eleType data, bool *success);

    /*
        function name: BST_destroy
        function: Delete all the nodes from the tree and free up the memory space
        pre-condition: Tree is pointed to BST tree structure
        output: True on success or false if BST structure cannot be destroyed
        post-condition: All nodes in the tree are removed and the memory is freed
    */
    void BST_destroy(BST_tree *tree);
#endif