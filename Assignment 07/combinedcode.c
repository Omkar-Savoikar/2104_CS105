#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>

typedef int eleType;
typedef struct bst_node node;
typedef struct bst_tree BST_tree;

struct bst_node{
    eleType data;
    struct bst_node *left;
    struct bst_node *right;
};

struct bst_tree{
    struct bst_node *root;
    int count;
};

bool isEmpty(BST_tree *b){
    if(b == NULL)
        return true;
    return false;
}

BST_tree* BST_create(){
    BST_tree *tree;
    tree = (BST_tree *)malloc(sizeof(BST_tree));
    if(tree != NULL){
        tree->root = NULL;
        tree->count = 0;
    }
    return tree;
}

node* _insert(node *root, node *ptr){
    if(!root)
        return ptr;
    if(ptr->data < root->data)
        root->left = _insert(root->left, ptr);
    else
        root->right =  _insert(root->right, ptr);
    return root;
}

bool BST_insert(BST_tree *tree, eleType data){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    if(temp == NULL)
        return false;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if(tree->count == 0) //(or b->root == NULL)
        tree->root = temp;
    else
        tree->root = _insert(tree->root, temp);
    (tree->count)++;
    return true;
}

void BST_traverse_inorder(node *root){
    //left, root, right
    if(root->left != NULL)
        BST_traverse_inorder(root->left);
    printf("%d ", root->data);
    if(root->right != NULL)
        BST_traverse_inorder(root->right);
}

void BST_traverse_preorder(node *root){
    //root, left, right
    printf("%d ", root->data);
    if(root->left != NULL)
        BST_traverse_preorder(root->left);
    if(root->right != NULL)
        BST_traverse_preorder(root->right);
}

void BST_traverse_postorder(node *root){
    //left, right, root
    if(root->left != NULL)
        BST_traverse_postorder(root->left);
    if(root->right != NULL)
        BST_traverse_postorder(root->right);
    printf("%d ", root->data);
}

node* _search(node* root, eleType data, bool *success){
    if(root == NULL){
        *success = false;
        return NULL;
    }
    if(data == root->data) {
        *success = true;
        return root;
    }
    if(data < root->data)
        root->left = _search(root->left, data, success);
    else
        root->right = _search(root->right, data, success);
}

node* BST_search(node *root, eleType data){
    node *temp;
    bool success;
    if(root->data == data)
        return root;
    temp = _search(root, data, &success);
    if(success == true)
        return temp;
    return NULL;
}

node* _delete(node *root, eleType data, bool *success){
    if(root == NULL){ //if data doesnt exist
        success = false;
        return NULL;
    }
    // Find inorder_predecessor
    if(data < root->data)
        root->left = _delete(root->left, data, success);
    else if(data > root->data)
        root->right = _delete(root->right, data, success);
    else{
        if(root->left && root->right){ // 2 children
            node *inorder_pre = root->left;
            while(inorder_pre->right)
                inorder_pre = inorder_pre->right;
            root->data = inorder_pre->data;
            root->left = _delete(inorder_pre, inorder_pre->data, success);
        }
        else{ // 0 or 1 child
            node *temp = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            free(temp);
        }
        *success = true;
    }
    return root;
}

bool BST_delete(BST_tree *tree, eleType data){
    bool success;
    node *temp;
    temp = _delete(tree->root, data, &success);
    if(success){
        tree->root = temp;
        (tree->count)--;
        if(tree->count == 0)
            tree->root = NULL;
    }
    return success;
}

void BST_destroy(BST_tree *tree){
    bool success;
    while(tree->root->left != NULL)
        success = BST_delete(tree, tree->root->left->data);
    while(tree->root->right != NULL)
        success = BST_delete(tree, tree->root->right->data);
    while(tree->count != 0){
        success = BST_delete(tree, tree->root->data);
        if(success == false)
            break;
    }
    if(success == false){
        printf("\nCouldnt delete node %d", tree->root->data);
        printf("\nNodes left %d", tree->count);
    }
}

void main(){
    BST_tree *tree;
    eleType data;
    int op;
    tree = BST_create();
    printf("\nBinary Search Tree Program");
    if(tree == NULL){
        printf("\nError. Tree cannot be created.");
        exit(1);
    }
    do{
        printf("\n");
        printf("\nPress 1 to create new tree");
        printf("\nPress 2 to insert new data in the tree");
        printf("\nPress 3 to display inorder traversal");
        printf("\nPress 4 to display preorder traversal");
        printf("\nPress 5 to display postorder traversal");
        printf("\nPress 6 to search data in the tree");
        printf("\nPress 7 to delete a data from the tree");
        printf("\nPress 0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d",&op);
        switch(op){
            case 1: {
                //Create new tree
                if(tree == NULL){
                    printf("\nError. Tree cannot be created.");
                    exit(1);
                }
                else
                    printf("\nNew tree created.");
                break;
            }
            case 2: {
                //Insert new data
                if(tree == NULL)
                    printf("Tree is not created. Create tree before inserting data.");
                else{
                    printf("\nEnter data key value: ");
                    scanf("%d", &data);
                    if(BST_insert(tree, data) == false){
                        printf("Error in inserting data. Memory is full.");
                        exit(1);
                    }
                    else
                        printf("\nData inserted in the tree.");
                }
                break;
            }
            case 3: {
                //Inorder traversal
                if(tree == NULL)
                    printf("Tree is not created. Create tree before inserting data.");
                else{
                    if(tree->root == NULL)
                        printf("\nTree is empty.");
                    else
                        BST_traverse_inorder(tree->root);
                }
                break;
            }
            case 4: {
                //Preorder traversal
                if(tree == NULL)
                    printf("Tree is not created. Create tree before inserting data.");
                else{
                    if(tree->root == NULL)
                        printf("\nTree is empty.");
                    else
                        BST_traverse_preorder(tree->root);
                }
                break;
            }
            case 5: {
                //Postorder traversal
                if(tree == NULL)
                    printf("Tree is not created. Create tree before inserting data.");
                else{
                    if(tree->root == NULL)
                        printf("\nTree is empty.");
                    else
                        BST_traverse_postorder(tree->root);
                }
                break;
            }
            case 6: {
                //Search for data in tree
                if(tree == NULL)
                    printf("Tree is not created. Create tree before searching data.");
                else{
                    if(tree->root == NULL)
                        printf("\nTree is empty.");
                    else{
                        printf("\nEnter data to be searched: ");
                        scanf("%d", &data);
                        if(BST_search(tree->root, data) == NULL)
                            printf("\nData not found in the tree.");
                        else
                            printf("\nData found in the tree.");
                    }
                }
                break;
            }
            case 7: {
                //Delete data from tree
                if(tree == NULL)
                    printf("Tree is not created. Create tree before deleting data.");
                else{
                    if(tree->root == NULL)
                        printf("\nTree is empty.");
                    else{
                        printf("\nEnter data to be deleted: ");
                        scanf("%d", &data);
                        if(BST_delete(tree, data) == true)
                            printf("\nData deleted from the tree.");
                        else
                            printf("\nData not found in the tree.");
                    }
                }
                break;
            }
            case 0: break;
            default: printf("\nIncorrect input. Enter a number between 0 to 7.");
        }
    }while(op != 0);
    BST_destroy(tree);
}