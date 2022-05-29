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

void split_list(ListType *plist1, ListType *plist2, ListType* plist3){
    ListNode *p;
    int count = 1;
    p = plist3->head;

    while(p){
        if(count%2 == 1){
            insert_last(plist1, p->data);
            p = p->link;
            count++;
        }
        else{
            insert_last(plist2, p->data);
            p = p->link;
            count++;
        }
    }
}

int main() {
	ListType* plist1;
    ListType* plist2;
    ListType* plist3;

	plist1 = create();
    plist2 = create();
    plist3 = create();

    insert_last(plist3, 10);
    insert_last(plist3, 20);
    insert_last(plist3, 30);
    insert_last(plist3, 40);
    insert_last(plist3, 50);
    insert_last(plist3, 60);
    insert_last(plist3, 70);
    insert_last(plist3, 80);
    insert_last(plist3, 90);

    print_list(plist3);

    split_list(plist1,plist2,plist3);

    print_list(plist1);
    print_list(plist2);

	
	return 0;
}