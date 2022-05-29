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

void insert_last(ListType* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	if (head->tail == NULL) {
		head->head = head->tail = p;
	}
	else {
		head->tail->link = p;
		head->tail = p;
	}
	head->size++;
} 

void print_list(ListType* head) {
	ListNode* p;
	for (p = head->head; p != NULL; p = p->link) {
		printf("%d->", p->data);
    }
    printf("NULL\n");
}

void add_list(ListType *plist1, ListType *plist2, ListType* plist3){
    ListNode *p1;
    ListNode *p2;

    p1 = plist1->head;
    p2 = plist2->head;
    while(p1 && p2){
        insert_last(plist3, p1->data);
        insert_last(plist3, p2->data);
        p1 = p1->link;
        p2 = p2->link;
    }
    for(;p1 != NULL; p1 = p1->link)
    insert_last(plist3, p1->data);
    for(;p2 != NULL; p2 = p2->link)
    insert_last(plist3, p2->data);
}

int main() {
	ListType* plist1;
    ListType* plist2;
    ListType* plist3;

	plist1 = create();
    plist2 = create();
    plist3 = create();

    insert_last(plist1, 10);
    insert_last(plist1, 20);
    insert_last(plist1, 30);
    print_list(plist1);

    insert_last(plist2, 50);
    insert_last(plist2, 60);
    insert_last(plist2, 70);
    insert_last(plist2, 80);
    insert_last(plist2, 90);

    print_list(plist2);

    add_list(plist1,plist2,plist3);
    print_list(plist3);
	
	return 0;
}