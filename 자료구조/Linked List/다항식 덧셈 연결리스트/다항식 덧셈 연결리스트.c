#include <stdio.h>
#include <stdlib.h>

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

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3){    //다항식 덧셈함수
    ListNode* a = plist1->head; //리스트1의 head를 가르키는 노드 생성
    ListNode* b = plist2->head; //리스트2의 head를 가르키는 노드 생성
    int sum;

    while(a && b){  //a가 NULL이 아니고, b가 NULL이 아닐때 반복
        if(a->expon == b->expon){   //두 다항식의 계수가 같은 경우
            sum = a->coef + b->coef;    //차수를 더해 변수에 넣는다
            if(sum != 0)    //더한 값이 0이 아닌경우
            insert_last(plist3, sum, a->expon); //리스트에 삽입
            a = a->link;    //다음 노드로 넘어가기
            b = b->link;    //다음 노드로 넘어가기
        }
        else if(a->expon > b->expon){   //다항식a의 계수가 다항식b의 계수보다 큰 경우
            insert_last(plist3, a->coef, a->expon); //다항식a를 리스트에 삽입
            a = a->link;    //다항식a만 다음 노드로 넘어가기
        }
        else{   //다항식b의 계수가 다항식a의 계수보다 큰 경우
            insert_last(plist3, b->coef, b->expon); //다항식b를 리스트에 삽입
            b = b->link;    //다항식b만 다음 노드로 넘어가기
        }
    }  
    //다항식a 또는 다항식b중 하나라도 NULL이 나오면 남은 다항식 삽입
    for(;a != NULL;a = a->link)
    insert_last(plist3, a->coef, a->expon);
    for(;b != NULL;b = b->link)
    insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType* plist){   //다항식 출력
    ListNode* p = plist->head;

    printf("polynomial = ");
    for(;p;p = p->link){
        printf("%d^%d + ", p->coef, p->expon);
    }
    printf("\n");
}

int main(){
    ListType *list1, *list2, *list3;

    list1 = create();
    list2 = create();
    list3 = create();

    insert_last(list1, 3, 6);
    insert_last(list1, 7, 3);
    insert_last(list1, 2, 2);
    insert_last(list1, -9, 0);


    insert_last(list2, -2, 6);
    insert_last(list2, 4, 4);
    insert_last(list2, 6, 2);
    insert_last(list2, 6, 1);
    insert_last(list2, 1, 0);

    poly_print(list1);
    poly_print(list2);

    poly_add(list1, list2, list3);
    poly_print(list3);

    return 0;
}