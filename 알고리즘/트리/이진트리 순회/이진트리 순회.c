#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;


void  preorder(TreeNode *tmp) {
	if (tmp != NULL) {
		printf("[%d] ", tmp->data);
		preorder(tmp->left);
		preorder(tmp->right);
	}
}
void inorder(TreeNode *tmp) {
	if (tmp != NULL) {
		inorder(tmp->left);
		printf("[%d] ", tmp->data);
		inorder(tmp->right);
	}
}
void postorder(TreeNode *tmp) {
	if (tmp != NULL) {
		postorder(tmp->left);
		postorder(tmp->right);
		printf("[%d] ", tmp->data);
	}
}

int main() {
	TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n6 = (TreeNode*)malloc(sizeof(TreeNode));

	n6->data = 15;
	n6->left = n2;
	n6->right = n5;
	n2->data = 4;
	n2->left = n1;
	n2->right = NULL;
	n1->data = 1;
	n1->left = NULL;
	n1->right = NULL;
	n5->data = 20;
	n5->left = n3;
	n5->right = n4;
	n3->data = 16;
	n3->left = NULL;
	n3->right = NULL;
	n4->data = 24;
	n4->left = NULL;
	n4->right = NULL;

	printf("중위순회=");
	inorder(n6);
	printf("\n");
	printf("전위순회=");
	preorder(n6);
	printf("\n");
	printf("후위순회=");
	postorder(n6);
	printf("\n");
	return 0;
}