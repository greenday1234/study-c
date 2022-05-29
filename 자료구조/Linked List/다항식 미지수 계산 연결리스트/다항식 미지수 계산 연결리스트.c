#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode{
    int coef;
    int expon;
    struct ListNode* link;
}ListNode;

typedef struct ListType{
    int size;
    ListNode *head;
    ListNode *tail;
}ListType;

void error(char *message){
    fprintf(stderr,"%s\n", message);
    exit(1);
}

ListType *create(){ //리스트 헤더 생성 함수
    ListType *plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;    //길이 0 초기화
    plist->head = plist->tail = NULL;   //head와 tail을 NULL로 초기화
    return plist;   //초기화 한 리스트를 return
}

void insert_last(ListType *plist, int coef, int expon){ //리스트에 노드 삽입
    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));   //동적 노드 생성
    if(temp == NULL)
    error("메모리 할당 에러");
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;  //맨 뒤에 들어가는 값이기 때문에 link를 NULL로 초기화
    if(plist->tail == NULL){    //리스트에 노드가 없을 경우
        plist->head = plist->tail = temp;   //head와 tail을 노드에 연결
    }
    else{   //리스트에 노드가 있을 경우
        plist->tail->link = temp;   //tail의 link를 temp노드에 연결
        plist->tail = temp; //tail을 tamp노드로 변경
    }
    plist->size++;
}

void poly_print(ListType* plist){   //다항식 출력
    ListNode* p = plist->head;

    printf("polynomial = ");
    for(;p;p = p->link){
        printf("%d^%d + ", p->coef, p->expon);
    }
    printf("\n");
}

int poly_eval(ListType *plist, int x){
    ListNode *p;
    int sum = 0;
    p = plist->head;
    while(p){
        sum = sum + (p->coef * pow(x,p->expon));
        p = p->link;
    }
    return sum;
}

int main(){
    ListType *list1;
    int x;
    list1 = create();

    insert_last(list1, 1, 3);
    insert_last(list1, 2, 1);
    insert_last(list1, 6, 0);
    poly_print(list1);

    printf("미지수를 입력하시오 : ");
    scanf("%d", &x);

    printf("계산된 다항식의 값은 %d입니다.\n",poly_eval(list1, x));

    return 0;
}