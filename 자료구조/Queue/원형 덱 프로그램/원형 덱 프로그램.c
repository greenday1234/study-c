#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;                    //기존 큐 코드
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}DequeType;

void error(char *message){              //기존 큐 코드
    fprintf(stderr,"%s\n", message);
    exit(1);
}

void init_deque(DequeType *q){          //기존 큐 코드
    q->front = q->rear = 0;
}

int is_empty(DequeType *q){             //기존 큐 코드
    return (q->front == q->rear);
}

int is_full(DequeType *q){              //기존 큐 코드
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void deque_print(DequeType *q){                     //기존 큐 코드
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i=q->front;
        do{
            i = (i + 1)%MAX_QUEUE_SIZE;
            printf("%d | ", q->data[i]);
            if(i == q->rear)
            break;
        }while(i != q->front);
    }
    printf("\n");
}

void add_rear(DequeType *q, element item){      //기존 큐 코드(enqueue)
    if(is_full(q))
    error("큐가 포화상태입니다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element delete_front(DequeType *q){             //기존 큐 코드(dequeue)
    if(is_empty(q))
    error("큐가 공백상태입니다.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element get_front(DequeType *q){    //맨 앞(front)의 값을 보이는 함수
    if(is_empty(q))
    error("큐가 공백상태입니다.");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];   //front는 인덱스의 한 칸 앞을 가르키기 때문에 +1을 해준다
}

element get_rear(DequeType *q){ //맨 뒤의 값을 보이는 함수
    if(is_empty(q))
    error("큐가 공백상태입니다.");
    return q->data[q->rear];
}

void add_front(DequeType *q, element val){  //맨 앞(front)에 삽입
    if(is_full(q))
    error("큐가 포화상태입니다.");
    q->data[q->front] = val;    //front는 한 칸 앞을 가르키기 때문에 현재 front의 위치에 값을 넣는다
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;    //front - 1 + M을 해주는데 +M을 해주는 이유는 음수가 될 수 있기 때문임
}

element delete_rear(DequeType *q){  //맨 뒤 삭제
    if(is_empty(q))
    error("큐가 공백상태입니다.");
    int prev = q->rear; //rear의 index값을 미리 받는다
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;  //rear - 1 + M을 해주는데 여기서도 +M을 해주는 이유는 음수가 될 수 있기 때문임
    return q->data[prev];   //아까 위에서 받아준 prev를 뽑는다
}

int main(){
    DequeType queue;

    init_deque(&queue);
    for(int i=0;i<3;i++){
        add_front(&queue, i);
        deque_print(&queue);
    }
    for(int i=0;i<3;i++){
        delete_rear(&queue);
        deque_print(&queue);
    }
    return 0;
}