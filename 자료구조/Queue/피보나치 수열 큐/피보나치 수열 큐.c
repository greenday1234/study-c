#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {    //원형큐 구조체
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char *message){  //오류
    fprintf(stderr,"%s\n", message);
    exit(1);
}

void init_queue(QueueType *q){  //원형큐 초기화
    q->front = q->rear = 0; //선형큐와 다르게 front와 rear를 0으로 초기화한다
                            //선형큐의 경우 front = -1, rear = -1
}

int is_empty(QueueType *q){ //공백
    return (q->front == q->rear);   //front와 rear가 같으면 공백
}

int is_full(QueueType *q){  //포화
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);    //rear + 1을 전체 크기로 나눈 나머지가 front와 같으면 포화
}

void queue_print(QueueType *q){ //원형큐 출력
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;   //큐에 값이 있으면 front값을 i에 넣는다
        do {
            i = ((i + 1) % (MAX_QUEUE_SIZE));   //i에 front에 1증가한 값을 넣는다
            printf("%d | ", q->data[i]);    //해당 front의 값을 출력
            if(i == q->rear)    //rear와 같아지면 break
            break;
        } while(i != q->front); //i가 다시 front로 돌아가면 멈추기
    }
    printf("\n");
}

void enqueue(QueueType *q, element item){   //삽입
    if(is_full(q))
    error("큐가 포화상태입니다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;   //rear를 1증가시킨다
    q->data[q->rear] = item;    //증가시킨 rear에 item을 넣는다
}
element dequeue(QueueType *q){  //삭제
    if(is_empty(q))
    error("큐가 공백상태입니다.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; //front를 1 증가시킨다
    return q->data[q->front];   //증가된 front를 return한다
}
element peek(QueueType *q){ //삭제
    if(is_empty(q))
    error("큐가 공백상태입니다.");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
int math(int a, int b){
    int sum;
    sum = a+b;
    return sum;
}

int main(){
    int first = 0, second = 1;
    QueueType queue;
    int element;
    init_queue(&queue);

    enqueue(&queue, first);
    enqueue(&queue, second);
    queue_print(&queue);

    for(int i=0;i<50;i++){
        int num;
        num = math(first, second);
        if(i%2 != 0 && i != 0){
          second = num;
        }
        else{
            first = num;
        }
        enqueue(&queue, num);
       element = dequeue(&queue);
        queue_print(&queue);
        
    }
    
    return 0;
}