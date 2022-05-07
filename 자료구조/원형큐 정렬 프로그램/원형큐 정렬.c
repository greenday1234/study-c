#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front, rear;

void initialize() {
	front = rear = 0;
}
int isEmpty() {
	return (front == rear);
}
int isFull() {
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}
void addq(int item, int nCount) {
	int i = 0;
	if (isFull()) {
		fprintf(stderr, "queue is full\n");
		exit(1);
	}
	for (i = nCount; i >= 0; i--) {
		if (item < queue[i]) {
			queue[i + 1] = queue[i];
		}
		else {
			break;
		}
	}
		queue[i+1] = item;
		rear = (rear + 1) % MAX_QUEUE_SIZE;
}
int deleteq() {
	if (isEmpty()) {
		printf("queue is empty\n");
		exit(1);
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

int main() {
	int temp;
	int nCount = 0;

	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "err");
		exit(1);
	}

	while (!feof(fp)) {
		fscanf(fp, "%d", &temp);
		addq(temp, nCount);
		nCount++;
	}
	for (int i = 0; i < nCount; i++) {
		printf("%d -> ", deleteq());
	}
	fclose(fp);
	return 0;
}