#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
	char name[20];
	char tel[20];
}element;


typedef struct TreeNode {
	element key;
	struct TreeNode* left, *right;
}TreeNode;

int compare(element e1, element e2) {
	return strcmp(e1.name, e2.name);
}

TreeNode* new_node(element key) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	strcpy(temp->key.name, key.name);
	strcpy(temp->key.tel, key.tel);
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* root, element key) {
	if (root == NULL)
		return new_node(key);

	if (compare(key, root->key) < 0)
		root->left = insert_node(root->left, key);
	else if (compare(key, root->key) > 0)
		root->right = insert_node(root->right, key);

	return root;
}

TreeNode* min_value_node(TreeNode* root) {
	TreeNode* current = root;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
} 

TreeNode* delete_node(TreeNode* root, element key) {
	if (root == NULL)
		return root;

	if (compare(key, root->key) < 0)
		root->left = delete_node(root->left, key);
	else if (compare(key, root->key) > 0)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);
		strcpy(root->key.name, temp->key.name);
		strcpy(root->key.tel, temp->key.tel);
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

TreeNode* search(TreeNode* root, element key) {
   TreeNode* p = root;

   while (p != NULL) {
        int temp = compare(key, p->key);
        if(temp == 0 ) return p;
        if(temp < 0) p = p->left;
        else p = p->right;
   }
   return NULL;
}

void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%s : %s", root->key.name, root->key.tel);
		printf("\n");
		inorder(root->right);
	}
}

int main() {
    element text;
    char str[20] = "\0";
    element m;
    TreeNode* tmp;
    TreeNode* root = NULL;
	FILE* fp = fopen("data.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "file open error\n");
        exit(1);
    }
    while(!feof(fp)){
        fscanf(fp, "%s %s", m.name, m.tel);
		fgetc(fp);
        root = insert_node(root, m);
    }

    inorder(root);

    while(1){
        printf("검색할 이름: ");
        scanf("%s", str);
        if(strcmp(str, "exit") == 0)
        break;
        strcpy(text.name, str);
        strcpy(text.tel, "");
        tmp = search(root, text);
        if(tmp != NULL){
        printf("%s의 전화번호: %s\n", tmp->key.name, tmp->key.tel);
        }
        else{
            printf("찾는 이름이 없습니다.\n");
        }
    }

	while(1){
		printf("삭제할 이름: ");
		scanf("%s", str);
		if(strcmp(str, "exit") == 0)
		break;
		strcpy(text.name, str);
		strcpy(text.tel, "");
		root = delete_node(root, text);
		inorder(root);

	}

    fclose(fp);
    return 0;
}