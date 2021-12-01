/*
    AUTHOR: MCA.2104
    PROGRAM: BINARY SEARCH TREE TRAVERSALS
    DATE CREATED: 18 OCT 2021
    DATE MODIFIED: 23 OCT 2021
*/
//DS DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
#include"2104_bst.h"

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