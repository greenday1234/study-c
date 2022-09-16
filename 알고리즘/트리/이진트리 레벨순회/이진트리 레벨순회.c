#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

typedef TreeNode* element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
		int front, rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("empty");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void levelorder(TreeNode *tmp) {
	QueueType q;

	init_queue(&q);
	if (tmp == NULL)
		return;
	enqueue(&q, tmp);
	while (!is_empty(&q)) {
		tmp = dequeue(&q);
		printf(" [%d] ", tmp->data);
		if (tmp->left)
			enqueue(&q, tmp->left);
		if (tmp->right)
			enqueue(&q, tmp->right);
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
	n4->data = 25;
	n4->left = NULL;
	n4->right = NULL;

	printf("레벨 순회=");
	levelorder(n6);
	printf("\n");
	printf("20194012 이찬희");

	return 0;
}