#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
    element key;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode* search(TreeNode* node, int key){
    if(node == NULL)
    return NULL;
    if(key == node->key)
    return node;
    else if(key < node->key)
    return search(node->left, key);
    else
    return search(node->right, key);
}

TreeNode* new_node(int item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, int key){ //순환문 삽입
    if(node == NULL)
    return new_node(key);
    if(key < node->key)
    node->left = insert_node(node->left, key);
    else if(key > node->key)
    node->right = insert_node(node->right, key);
    return node;
}

void insert_node_r(TreeNode ** root, int key){ //반복문 삽입
    TreeNode *p, *t;
    TreeNode *n;
    t = *root;
    p = NULL;
    while(t != NULL){
        if(key == t->key)
        return;
        p = t;
        if(key < t->key)
        t = t->left;
        else
        t = t->right;
    }
    n = (TreeNode*)malloc(sizeof(TreeNode));
    if(n == NULL)
    return;
    n->key = key;
    n->left = n->right = NULL;
    if(p != NULL)
    if(key < p->key)
    p->left = n;
    else
    p->right = n;
    else
    *root = n;
}

TreeNode* min_value_node(TreeNode* node){
    TreeNode* current = node;
    while(current->left != NULL)
    current = current->left;
    return current;
}

TreeNode* delete_node(TreeNode* root, int key){
    if(root == NULL)
    return root;
    if(key < root->key)
    root->left = delete_node(root->left, key);
    else if(key > root->key)
    root->right = delete_node(root->right, key);
    else{
        if(root->left == NULL){
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            TreeNode * temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = min_value_node(root->right);
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void delete_node_r(TreeNode ** root, int key){
    TreeNode *p, *child, *succ, *succ_p, *t;
    p = NULL;
    t = *root;

    while(t != NULL && t->key != key){
        p = t;
        t = (key < t->key) ? t->left : t->right;
    }
    if(t == NULL){
        printf("key is not in the tree\n");
        return;
    }
    if(t->left == NULL && t->right == NULL){
        if(p != NULL){
            if(p->left == t)
            p->left = NULL;
            else
            p->right = NULL;
        }
        else
        *root = NULL;
    }
    else if(t->left == NULL || t->right == NULL){
        child = (t->left != NULL) ? t->left : t->right;
        if(p != NULL){
            if(p->left == t)
            p->left = child;
            else
            p->right = child;
        }
        else
        *root = child;
    }
    else{
        succ_p = t;
        succ = t->right;
        while(succ->left != NULL){
            succ_p = succ;
            succ = succ->left;
        }
        if(succ_p->left == succ)
        succ_p->left = succ->right;
        else
        succ_p->right = succ->right;
        t->key = succ->key;
        t = succ;
    }
    free(t);
}

void inorder(TreeNode* root){
    if(root){
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}

void print_node(TreeNode* p, int th){
    if( p != NULL){
        if(p->key < th)
        printf("%d보다 작은 노드 : %d\n", th, p->key);
        print_node(p->left, th);
        print_node(p->right, th);
    }
}

int main(){
    TreeNode* root = NULL;
    TreeNode* tmp = NULL;

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    insert_node_r(&root, 40);
    insert_node_r(&root, 50);
    insert_node_r(&root, 60);

    printf("이진 탐색 트리 중위 순회 결과\n");
    inorder(root);
    printf("\n\n");
    if(search(root, 30) != NULL)
    printf("이진 탐색 트리에서 30을 발견함\n");
    else
    printf("이진 탐색 트리에서 30을 발견못함.\n");

    int value;
    printf("값을 입력하시오: ");
    scanf("%d", &value);
    print_node(root, value);
    return 0;

}