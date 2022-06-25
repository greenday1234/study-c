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
    q->rear = q->front = -1;
}
int is_full(QueueType *q){ 
    return (q->rear == MAX_QUEUE_SIZE -1);
}
int is_empty(QueueType *q){
    return (q->front == q->rear);
}
void enqueue(QueueType *q, int item){   //삽입
    if(is_full(q))
        error("큐가 포화상태입니다.");

    q->data[(++q->rear)] = item;    //rear의 값을 1증가시키고 그 자리에 item 넣기
}
int dequeue(QueueType *q){
    if(is_empty(q))
        error("큐가 공백상태입니다.");

    int item = q->data[++(q->front)];   //front가 가르키고 있는 값보다 뒤를 지워야 함. 따라서 ++(q->front)를 해야함
    return item;
}
void queue_print(QueueType *q){ //큐 출력 
    for(int i=0;i<MAX_QUEUE_SIZE;i++){
        if(i<=q->front || i>q->rear)    //i가 fornt보다 작거나 같거나 i가 rear보다 큰 경우(i가 현재 queue의 범위 안에 없는 경우)
        printf(" | ");
        else    //i가 현재 queue의 범위 안에 있는 경우
        printf("%d | ", q->data[i]);    //queue의 data를 출력
    }
    printf("\n");
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