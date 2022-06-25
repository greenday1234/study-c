#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

typedef struct ListType{
    int size;
    ListNode *tail;
    ListNode *head;
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

void insert_last(ListType *head, int value){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = NULL;
    if(head->tail == NULL){
        head->head = head->tail = p;
    }
    else{
        head->tail->link = p;
        head->tail = p;
    }
    head->size++;
}

int sum_list(ListType *head){
    ListNode *p;
    int sum=0;
    for(p = head->head; p != NULL; p = p->link){
        sum += p->data;
    }
    return sum;
}

int main(){
    ListType *head;
    head = create();
    int n;
    int data;

    printf("노드의 개수 : ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("노드 #%d 데이터 : ", i+1);
        scanf("%d", &data);
        insert_last(head, data);
    }
    printf("연결 리스트의 데이터 합: %d", sum_list(head));
    return 0;
}