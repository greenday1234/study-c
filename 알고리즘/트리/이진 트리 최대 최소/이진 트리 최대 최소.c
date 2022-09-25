#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;

void insert_node(TreeNode** root, element key) {
	TreeNode* p, * t;
	TreeNode* n;

	t = *root;
	p = NULL;

	//search
	while (t != NULL) {
		if (key == t->data)
			return;
		p = t;
		if (key < p->data) {
			t = p->left;
		}
		else {
			t = p->right;
		}
	}
	//insert
	n = (TreeNode*)malloc(sizeof(TreeNode));

	if (n == NULL)
		return;

	n->data = key;
	n->left = n->right = NULL;

	if (p != NULL) {
		if (key < p->data)
			p->left = n;
		else
			p->right = n;
	}
	else
		*root = n;
}	

int power(int a) {	//2^a를 계산
	int i, result = 1;
	for (i = 0; i < a; i++) {
		result *= 2;
	}
	return result;
}

int MAX(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
	return 1;
}

int get_height(TreeNode* node) {
	int height = 0;

	if (node != NULL) {
		height = 1 + MAX(get_height(node->left), get_height(node->right));
	}
	return height;
}

int get_leaf_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) {
			return 1;
		}
		else {
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
		}
	}
	return count;
}

void inorder(TreeNode* tmp) {
	if (tmp != NULL) {
		inorder(tmp->left);
		printf("[%d] ", tmp->data);
		inorder(tmp->right);
	}
}

int max_node(TreeNode* root) {
	TreeNode* tmp = root;
	while (tmp->right != NULL) {
		tmp = tmp->right;
	}
	return tmp->data;
}

int min_node(TreeNode* root) {
	TreeNode* tmp = root;
	while (tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp->data;
}

int main() {
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;
	int height = 0, leaf_count = 0;
	FILE* fp = fopen("data.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%d", &e);
		insert_node(&root, e);
		printf("inserted %d\n", e);
	}
	inorder(root);
	printf("\n");
	printf("최대값 : %d\n", max_node(root));
	printf("최소값 : %d\n", min_node(root));
	fclose(fp);
}