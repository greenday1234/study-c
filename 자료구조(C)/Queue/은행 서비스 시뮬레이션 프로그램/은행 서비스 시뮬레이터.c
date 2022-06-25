#include <stdio.h>
#include <stdlib.h>
#include <time.h>z
#define MAX_QUEUE_SIZE 5

typedef struct{
    int id; //고객 id
    int arrival_time;   //
    int service_time;   //서비스를 받는 고객의  유무
}element;

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

int main(){
    int minutes = 60;
    int total_wait = 0; //전체 대기시간 
    int total_customers = 0;    //전체 고객
    int service_time = 0;   //업무 시간
    int service_customer;   //서비스 사용중 고객

    QueueType queue;
    init_queue(&queue);

    srand(time(NULL));

    for(int clock = 0;clock<minutes;clock++){   //0부터 시작해 60까지 반복
        printf("현재시각=%d\n", clock); 
        if((rand()%10) < 3){    //0에서 10 사이의 난수를 발생시키고 3 이내면 고객으로 판단(1/3의 확률)
            element customer;   //고객 구조체 생성
            customer.id = total_customers++;    //고객 id(들어온 고객 수) 1증가시켜 적용
            customer.arrival_time = clock;  //고객이 들어온 시간
            customer.service_time = rand() % 3+1;   //고객의 서비스에 필요한 시간
            enqueue(&queue, customer);  //위의 정보를 큐에 삽입
            printf("고객 %d이 %d분에 들어옵니다. 업무처리시간 = %d분\n", customer.id, customer.arrival_time, customer.service_time);
        }
        if(service_time > 0){   //서비스 시간이 0이상일 경우(서비스를 마치지 않은 경우)
            printf("고객 %d 업무처리중입니다.\n", service_customer);    //해당 고객의 id를 출력
            service_time--; //서비스 시간을 1씩 줄임
        }
        else{
            if(!is_empty(&queue)){  //큐가 비어있지 않은 경우
                element customer = dequeue(&queue); //큐에 쌓인 소비자를 뺸다
                service_customer = customer.id; //service_customer에 고객 id를 넣는다
                service_time = customer.service_time;   //서비스 시간에 랜덤으로 생성된 서비스 소요시간 넣기
                printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;    //마지막에 전체 대기시간을 알아보기위해 대기시간들을 전부 더함
            }
        }
    }
    printf("전체 대기 시간 = %d분\n", total_wait);
    return 0;
}