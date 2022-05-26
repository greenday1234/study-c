#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{ //큐 타입 구조체
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;

void error(char *message){  //에러함수
    fprintf(stderr,"%s\n", message);
    exit(1);
}

void init_queue(QueueType *q){  //큐 초기화
    q->rear = -1;
    q->front = -1;
}

void queue_print(QueueType *q){ //큐 출력 
    for(int i=0;i<MAX_QUEUE_SIZE;i++){
        if(i<=q->front || i>q->rear)
        printf(" | ");
        else
        printf("%d | ", q->data[i]);
    }
    printf("\n");
}
int is_full(QueueType *q){ 
    if(q->rear == MAX_QUEUE_SIZE -1)
    return 1;
    else
    return 0;
}
int is_empty(QueueType *q){
    if(q->front ==q->rear)
    return 1;
    else
    return 0;
}
void enqueue(QueueType *q, int item){   //삽입
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        exit(1);
    }
    q->data[++(q->rear)] = item;
}
int dequeue(QueueType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        exit(1);
    }
    int item = q->data[++(q->front)];   //front가 가르키고 있는 값보다 앞을 지워야 함. 따라서 ++(q->front)를 해야함
    return item;
}

int main(){
    int item = 0;
    QueueType q;

    init_queue(&q);

    enqueue(&q, 10);
    queue_print(&q);
    enqueue(&q, 20);
    queue_print(&q);
    enqueue(&q, 30);
    queue_print(&q);

    item = dequeue(&q);
    queue_print(&q);
    item = dequeue(&q);
    queue_print(&q);
    item = dequeue(&q);
    queue_print(&q);
    return 0;
}