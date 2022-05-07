#include <Stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
	int nNum;
	char name[100];
}QueueObject;

QueueObject queue[MAX_QUEUE_SIZE];
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
void addq(QueueObject item) {
	if (isFull()) {
		printf("queue is full\n");
		exit(1);
	}
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		queue[rear] = item;
	}
}
QueueObject deletq() {
	if (isEmpty()) {
		printf("queue is empty\n");
		exit(1);
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}
int get_count() {
	return rear-front;
}
void print(int count) {
	for (int i = 0; i < count; i++) {
		QueueObject temp = deletq();
		printf("%d       | %s\n", temp.nNum, temp.name);
	}
}
void print_count(){
	printf("element : %d\n", get_count());
}

int main() {
	int temp;
	char name[100];
	int ncount = 0;
	int num;
	QueueObject cnt;
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL){
		fprintf(stderr,"err");
		exit(1);
		}
	while (!feof(fp)) {
		fscanf(fp, "%d%s", &cnt.nNum,&cnt.name);
		addq(cnt);
	}
	
	printf("front = %d rear = %d\n", front, rear);
	print_count();
	printf("student number | name \n");
	print(rear);
	printf("front = %d rear = %d\n", front, rear);
	print_count();
	fclose(fp);
	return 0;
}