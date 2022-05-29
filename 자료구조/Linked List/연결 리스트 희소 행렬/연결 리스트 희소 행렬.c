#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int row;
    int col;
    int value;
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

void insert_last(ListType* head, int row, int col, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->row = row;
    p->col = col;
    p->value = value;
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
		printf("%d %d %d \n", p->row, p->col, p->value);
    }
    printf("\n");
}

int main() {
	ListType* head;
	head = create();

    insert_last(head, 1, 1, 10);
    insert_last(head, 2, 2, 20);
    insert_last(head, 3, 3, 30);

    print_list(head);

	return 0;
}