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
int addq(int item) {
	if (isFull()) {
		printf("queue is full\n");
		exit(1);
	}
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		queue[rear] = item;
	}
}
int deletq() {
	if (isEmpty()) {
		printf("queue is empty\n");
		exit(1);
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

int main() {
	int temp;
	int ncount = 0;
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "err");
		exit(1);
	}
	printf("front = %d rear = %d\n", front, rear);

	while (!feof(fp)) {
		fscanf(fp, "%d", &temp);
		addq(temp);
		printf("front = %d rear = %d addq(%d)\n", front, rear, temp);
		ncount++;
	}
	for (int i = 0; i < ncount; i++) {
		printf("front = %d rear = %d deletq(%d)\n", front, rear, deletq());
	}
	printf("front = %d rear = %d\n", front, rear);

	fclose(fp);
	return 0;

}