#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef char element;
typedef struct{ //큐 타입 구조체
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}DequeType;

void error(char *message){  //에러함수
    fprintf(stderr,"%s\n", message);
    exit(1);
}

void init_queue(DequeType *q){  //큐 초기화
    q->rear = -1;
    q->front = -1;
}

void queue_print(DequeType *q){ //큐 출력 
    for(int i=0;i<MAX_QUEUE_SIZE;i++){
        if(i <= q->front || i > q->rear)
        printf(" | ");
        else
        printf("%c | ", q->data[i]);
    }
    printf("\n");
}
int is_full(DequeType *q){ 
    if(q->rear == MAX_QUEUE_SIZE -1)
    return 1;
    else
    return 0;
}
int is_empty(DequeType *q){
    if(q->front == q->rear)
    return 1;
    else
    return 0;
}
void enqueue(DequeType *q, element item){   //삽입
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        exit(1);
    }
    q->data[++(q->rear)] = item;
}
element dequeue(DequeType *q){  //맨 앞 삭제
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        exit(1);
    }
    char item = q->data[++(q->front)];   //front가 가르키고 있는 값보다 앞을 지워야 함. 따라서 ++(q->front)를 해야함
    return item;
}
element delete_rear(DequeType *q){  //맨 뒤 삭제
    if(is_empty(q))
    error("큐가 공백상태입니다.");
    int prev = q->rear; //rear의 값을 미리 받는다
    q->rear = (q->rear - 1);
    return q->data[prev];   //아까 위에서 받아준 prev를 뽑는다
}  
int main(){
    int item = 0;

    DequeType q;
    init_queue(&q);

    char ch[20];
    printf("문자열을 입력하시오: ");
    scanf("%s", ch);
    char c;
    char front_ch, rear_ch;
    int count=0;
    int len = strlen(ch);
    for(int i=0; i<len;i++){    //덱에 문자열 추가(문자단위)
        c = ch[i];
        enqueue(&q, c);
        count++;
    }
    for(int i=0;i<count/2;i++){ //양 끝에서 꺼내므로 전체 길이의 절반만 반복
        front_ch = dequeue(&q); //front에서 꺼내기
        rear_ch = delete_rear(&q);  //rear에서 꺼내기
        if(front_ch != rear_ch){    //양쪽에서 꺼낸 두 문자가 같지 않을 경우
            printf("회문이 아닙니다.\n");
            exit(1);
        }
    }
    printf("회문입니다.");

    return 0;
}