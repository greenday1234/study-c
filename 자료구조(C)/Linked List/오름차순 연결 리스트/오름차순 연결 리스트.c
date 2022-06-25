#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int size;
	ListNode* tail;
	ListNode* head;
}ListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
 
ListType* create() { //리스트 헤더 생성 함수
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0; //길이 0 초기화
	plist->head = plist->tail = NULL; //head와 tail을 NULL로 초기화
	return plist; //초기화 한 리스트를 return
}

void insert_last(ListType* plist, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    ListNode* pre;
    ListNode* r;
	p->data = value;
    p->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = p;
	}
	else {
            if(p->data < plist->head->data){    //맨 앞에 들어가는 경우
                p->link = plist->head;
                plist->head = p;
            }
            else{   //나머지 경우
                pre = plist->head;  //앞
                r = pre->link;  //뒤
            while(pre != NULL){
                if(p->data < r->data){
                    p->link = pre->link;
                    pre->link = p;
                    break;
                }
                else if(r->link == NULL){   //맨 뒤에 들어가는 경우
                    r->link = p;
                    break;
                }
                else if(p->data == r->data){
                    p->link = pre->link;
                    pre->link = p;
                    break;
                }
                else{
                    r = r->link;
                    pre = pre->link;
                }
            }
        }
    }   
	plist->size++;
} 

void print_list(ListType* head) {
	ListNode* p;
	for (p = head->head; p != NULL; p = p->link) {
		printf("%d->", p->data);
    }
    printf("NULL\n");
}

int main() {
	ListType* plist1;

    plist1 = create();
    
    insert_last(plist1, 20);
    insert_last(plist1, 10);
    insert_last(plist1, 30);

    print_list(plist1);

	return 0;
}