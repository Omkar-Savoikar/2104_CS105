/*
    AUTHOR: MCA.2104
    PROGRAM: BINARY SEARCH TREE TRAVERSALS
    DATE CREATED: 18 OCT 2021
    DATE MODIFIED: 23 OCT 2021
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
#include"2104_bst.h"

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
        printf("\nPress 3 to display postorder traversal");
        printf("\nPress 4 to search data in the tree");
        printf("\nPress 5 to delete a data from the tree");
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
            case 4: {
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
            case 5: {
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