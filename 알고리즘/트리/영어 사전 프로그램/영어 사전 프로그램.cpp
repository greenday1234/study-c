#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 100

typedef struct element {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
}element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

int compare(element e1, element e2) {
	return strcmp(e1.word, e2.word);
}

void insert_node(TreeNode** root, element key) { //main에서 root의 주소를 보냈기 때문에 이중포인터
	TreeNode* p, *t;
	TreeNode* n;

	t = *root;
	p = NULL;

	while (t != NULL) {
		//같은 키가 있는 경우
		if (compare(key, t->key) == 0)
			return;
		p = t;
		if (compare(key, t->key) < 0)
			t = t->left;
		else {
			t = t->right;
		}
	}
	//신규 노드 메모리 할당
	n = (TreeNode*)malloc(sizeof(TreeNode));
	if (n == NULL) {
		printf("메모리 할당 오류\n");
		return;
	}

	n->key = key;
	n->left = NULL;
	n->right = NULL;

	if (p != NULL) {
		if (compare(key, p->key) < 0) {
			p->left = n;
		}
		else {
			p->right = n;
		}
	}
	else {
		*root = n;
	}
}

void delete_node(TreeNode** root, element key) {
	TreeNode* p, * t, *child, *succ, *succ_p;
	p = NULL;
	t = *root;

	//삭제하고자 하는 단어를 트리에서 검색
	while (t != NULL && compare(t->key, key) != 0) {
		p = t;
		t = (compare(key, t->key) < 0) ? t->left : t->right;
	}
	//검색 결과 NULL이면 삭제 대상 없음
	if (t == NULL) {
		printf("삭제하고자 하는 단어가 없습니다.\n");
		return;
	}
	//단말노드의 경우
	if (t->left == NULL && t->right == NULL) {
		if (p != NULL) {
			if (p->left == t)
				p->left = NULL;
			else
				p->right = NULL;
		}
		else
			*root = NULL;
	}
	//child node가 한개만 있는 경우
	else if (t->left == NULL || t->right == NULL) {
		//삭제할 t노드의 자식이 왼쪽 혹은 오른쪽에 있는지 판단
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)
				p->left = child;
			else
				p->right = child;
		}
		else
			*root = child;
	}
	//child node가 두개가 있는 경우
	else {
		//한칸 오른쪽으로 이동
		succ_p = t;
		succ = t->right;
		//계속 왼쪽으로 이동
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		//후속자의 부모와 자식 연결
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		//후속자가 가진 키값을 현재 노드에 복사
		t->key = succ->key;
		//원래의 후속자 삭제
		t = succ;
	}
	free(t);
}

TreeNode* search(TreeNode* root, element key) {
	TreeNode* p = root;
	printf("%s %s", key.word, p->key.word);
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

void display(TreeNode* root) {
	if (root != NULL) {
		printf("(");
		display(root->left);
		printf("%s : %s", root->key.word, root->key.meaning);
		display(root->right);
		printf(")");
	}
}

int main() {
	element e;
	char ch;
	TreeNode* root = NULL;
	TreeNode *tmp;
	FILE* fp = fopen("data3.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "err");
		exit(1);
	}
	while (!feof(fp)) {
		fscanf(fp, "%c", &ch);
		switch (ch) {
		case 'i':
			fscanf(fp, "%s %s", e.word, e.meaning);
			insert_node(&root, e); // root의 주소를 보냄
			printf("%s : %s 삽입 \n", e.word, e.meaning);
			break;
		case 'd':
			fscanf(fp, "%s", e.word);
			strcpy(e.meaning, "");
			delete_node(&root, e);
			printf("%s 삭제\n", e.word);
			break;
		case 's':
			fscanf(fp, "%s", e.word);
			strcpy(e.meaning, "");
			tmp = search(root, e);
			if (tmp != NULL) {
				printf("단어 %s의 의미 : %s\n", tmp->key.word, tmp->key.meaning);
			}
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 'q':
			exit(1);
			break;
		}
	}
}