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
		switch (compare(key, p->key)) {
		case -1:
			p = p->left;
			break;
		case 0:
			return p;
		case 1:
			p = p->right;
			break;
		}
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
	char n;
	element e;
	TreeNode* root = NULL;
	TreeNode *tmp;
	while (1) {
        printf("삽입(i), 탐색(s), 삭제(d), 출력(p) : ");
		scanf("%c", &n);
		switch (n) {
		case 'i':
			printf("친구의 이름: ");
			scanf("%s", e.name);
			printf("친구의 전화번호: ");
			scanf("%s", e.tel);
			root = insert_node(root, e);
			break;
		case 's':
			printf("친구의 이름: ");
			scanf("%s", e.name);
			strcpy(e.tel, "");
			tmp = search(root, e);
			if (tmp != NULL) {
				printf("%s의 전화번호: %s\n", tmp->key.name, tmp->key.tel);
			}
			else {
				printf("%s의 전화번호가 없습니다.\n", e.name);
			}
			break;
		case 'd':
			printf("  > 삭제 단어: ");
			scanf("%s", e.name);
			strcpy(e.tel, "");
			root = delete_node(root, e);
			break;
		case 'p':
			inorder(root);
			break;
		case 'q':
			return 0;
		}
	}
}