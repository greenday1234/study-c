#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (a > b ? a : b)

typedef struct AVLNode{
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
}AVLNode;

//트리의 높이 반환 함수
int get_height(AVLNode *node){
    int height = 0;
    if(node != NULL)
    height = 1+MAX(get_height(node->left), get_height(node->right));

    return height;
}

//노드의 균형 인수를 반환하는 함수
int get_balance(AVLNode *node){
    if(node == NULL)    //노드가 없는 경우
    return 0;

    return (get_height(node->left) - get_height(node->right));  //왼쪽서브트리-오른쪽서브트리
}

AVLNode* create_node(int key){  //새로운 노드 생성
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

AVLNode* rotate_right(AVLNode* parent){
    AVLNode* child = parent->left;
    parent->left = child->right;
    child->right = parent;

    return child;
}

AVLNode *rotate_left(AVLNode* parent){
    AVLNode *child = parent->right;
    parent->right = child->left;
    child->left = parent;

    return child;
}

AVLNode *insert(AVLNode* node, int key){
    if(node == NULL)    //트리에 노드가 없는 경우
    return create_node(key);    //새 노드 생성

    if(key < node->key) //키값이 노드의 키값보다 작은 경우
    node->left = insert(node->left, key);   //왼쪽 서브트리에 insert
    else if(key > node->key)    //키값이 노드의 키값보다 큰 경우
    node->right = insert(node->right, key); //오른쪽 서브트리에 insert
    else    //동일한 키는 허용하지 않음
    return node;

    int balance = get_balance(node);    //노드들의 균형인수 재계산

    if(balance > 1 && key < node->left->key)    //LL타입 처리
    return rotate_right(node);

    if(balance < -1 && key > node->right->key)  //RR타입 처리
    return rotate_left(node);

    if(balance > 1 && key > node->left->key){   //LR타입 처리
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if(balance < -1 && key < node->right->key){ //RL타입 처리
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

void preorder(AVLNode *root){
    if(root != NULL){
        printf("[%d] ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    AVLNode *root = NULL;

    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 8);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 11);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 9);

    printf("전위 순회 결과\n");
    preorder(root);

    return 0;
}