#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q){
    q->front = q->rear = 0;
}

int is_empty(QueueType *q){
    return (q->front == q->rear);
}

int is_full(QueueType *q){
    return ((q->rear + 1) * MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    q->front = (q->front+1) %MAX_QUEUE_SIZE;
    return q->data[q->front];
}

#define BUCKETS 10  //열
#define DIGITS 4    //자릿수
void radix_sort(int list[], int n){
    int i, b, d, factor = 1;    //factor는 자릿수 비교 변수 1의 자리부터 시작하므로 1로 초기화
    QueueType queues[BUCKETS];

    for(b=0;b<BUCKETS;b++)
    init_queue(&queues[b]); //큐초기화
    for(d=0;d<DIGITS;d++){  //자릿수만큼 반복
        for(i=0;i<n;i++)    //n은 리스트 원소개수
        enqueue(&queues[(list[i]/factor)%10], list[i]); //1의자리가 작은 값부터 넣는다. 다음은 10의 자리
        for(b=i=0;b<BUCKETS;b++)
        while(!is_empty(&queues[b]))    //큐에 있는 값들을 리스트에 넣어서 재정렬
        list[i++] = dequeue(&queues[b]);
        factor *= 10;   //10의자리 만큼 증가
    }
}

#define SIZE 10

int main(){
    int list[SIZE];
    srand(time(NULL));
    for(int i=0;i<SIZE;i++)
    list[i] = rand()%100;

    radix_sort(list, SIZE);
    for(int i=0;i<SIZE;i++)
    printf("%d ", list[i]);
    printf("\n");
    return 0;
}