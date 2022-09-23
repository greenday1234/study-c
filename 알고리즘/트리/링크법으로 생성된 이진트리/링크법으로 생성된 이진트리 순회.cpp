#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define max(x,y) ((x>y)?x:y)

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

//      15
//  4       20
//1     16     25

TreeNode n1 = {1,NULL, NULL};
TreeNode n2 = {4,&n1, NULL};
TreeNode n3 = {16,NULL, NULL};
TreeNode n4 = {25,NULL, NULL};
TreeNode n5 = {20,&n3, &n4};
TreeNode n6 = {15,&n2, &n5};
TreeNode *root = &n6;

void inorder(TreeNode *root){
    if(root != NULL){
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

void preorder(TreeNode *root){
    if(root != NULL){
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->data);
    }
}

int get_node_count(TreeNode *root){
    int count = 0;

    if(root != NULL)
    count  = 1 + get_node_count(root->left) + get_node_count(root->right);
    return count;
}

int get_leaf_count(TreeNode *root){
    int count = 0;
    if(root != NULL){
        if(root->left == NULL && root->right == NULL)
        return 1;
        else
        count = get_leaf_count(root->left) + get_leaf_count(root->right);
    }
    return count;
}

int get_height(TreeNode *root){
    int height = 0;
    if(root != NULL)
    height = 1 + max(get_height(root->left), get_height(root->right));
    return height;
}

TreeNode * search_s(TreeNode* root, int key){
    if(root == NULL)
    return NULL;
    if(key == root->data)
    return root;
    else if(key < root->data)
    return search_s(root->left, key);
    else
    return search_s(root->right, key);
}

TreeNode * search_r(TreeNode* root, int key){
    while(root != NULL){
        if(key == root->data)
        return root;
        else if(key < root->data)
        root = root->left;
        else
        root = root->right;
    }
    return NULL;
}

int main(){
    printf("중위 순회 = ");
    inorder(root);
    printf("\n");

    printf("전위 순회 = ");
    preorder(root);
    printf("\n");

    printf("후위 순회 = ");
    postorder(root);
    printf("\n");

    printf("노드의 개수 = %d\n", get_node_count(root));
    printf("단일 노드의 개수 = %d\n", get_leaf_count(root));
    printf("높이 = %d\n", get_height(root));
    TreeNode *node = search_s(root, 16);
    printf("순환적인 탐색함수 = %d\n", node->data);
    node = search_r(root, 25);
    printf("반복적인 탐색함수 = %d\n", node->data);
    return 0;
}