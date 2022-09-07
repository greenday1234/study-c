//////////////////////////////////////////////////////////
//
// 작성자 : 이찬희  
// 작성일 : 2022년 9월 7일
// 프로그램명 : 연결리스트 정렬 프로그램
// 프로그램설명 : 정렬 방법을 여러가지 사용해 연결리스트를
//				  정렬하는 프로그램입니다.
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	int id;
	char name[20];
	double avg;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int size;
	ListNode* tail;
	ListNode* head;
}ListType;

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* head, int id, char name[], double avg) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->id = id;
	strcpy(p->name, name);
	p->avg = avg;
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
			printf("%d %s %.2lf \n", p->id, p->name, p->avg);
	}
}

void BubbleSort(ListType* head) {
	ListNode* p, * q, * r;
	if (head->size == 1)
		exit(1);
	for (int i=0; i<head->size; i++) {
		p = head->head, q = head->head, r = NULL;
		for (p = p->link; p != NULL; p = p->link) {
			if (q->id > p->id) {
				if (r == NULL) {
					head->head = p;
					q->link = p->link;
					p->link = q;

					q = p;
					p = p->link;

					r = q;
					q = q->link;
				}
				else{
					q->link = p->link;
					p->link = q;
					r->link = p;

					q = p;
					p = p->link;

					q = q->link;
					r = r->link;
				}
			}
			else {
				r = q;
				q = q->link;
			}
		}
	}
	head->tail = q;
}

void SelectSort(ListType* head) {
	ListNode* p, * q, * r, *s;
	int count = 0;
	char name[20];
	if (head->size == 1) {
		exit(1);
	}
	p = head->head, q = head->head, r = head->head, s = NULL;
	for (int i = 0; i < head->size-1; i++) {
		p = r;
		q = r;
		strcpy(name, r->name);
		for (int j = head->size - 1; j > i; j--) {
			q = p;
			p = p->link;
			
			if (strcmp(name, p->name) > 0) {
				strcpy(name, p->name);
			}
		}
		p = r;
		for (q = r,p = p->link; p != NULL; p = p->link) {
			if (strcmp(name, q->name) == 0) { //시작부분에 name이 있는 경우
				break;
			}
			if (strcmp(name, p->name) == 0) {
				if (p->link == NULL) { //마지막인 경우
					if (s == NULL) { //처음인 경우
						p->link = r->link;
						q->link = r;
						r->link = NULL;
						r = p;
						if (count == 0) {
							head->head = r;
							count++;
						}
					}
					else {
						p->link = r->link;
						q->link = r;
						r->link = NULL;
						s->link = p;
						r = p;
						if (count == 0) {
							head->head = r;
							count++;
						}
					}
				}
				else {
					if (s == NULL) {
						q->link = p->link;
						p->link = r->link;
						r->link = q->link;
						q->link = r;
						r = p;
						if (count == 0) {
							head->head = r;
							count++;
						}
					}
					else {
						q->link = p->link;
						p->link = r->link;
						r->link = q->link;
						q->link = r;
						s->link = p;
						r = p;
						if (count == 0) {
							head->head = r;
							count++;
						}
					}
				}
				break;
			}
			q = q->link;
		}
		s = r;
		r = r->link;
	}
}

/*void InsertionSort(ListType* head) {

}*/

void delete_list(ListType * head) {
	ListNode* p = head->head;
	ListNode* pre;
	while (p != NULL) {
		pre = p;
		p = p->link;
		free(pre);
	}
}

int main() {
	FILE* fp;
	int count = 0;;
	int id;
	char name[20];
	double avg;
	ListType* head;
	head = create();

	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "err");
		exit(1);
	}
	
	while (!feof(fp)) {
		fscanf(fp, "%d %s %lf", &id, name, &avg);
		insert_last(head, id, name, avg);
	}
	
	printf("기본 데이터\n");
	printf("-----------------------\n");
	print_list(head);
	printf("-----------------------\n");
	printf("\n");

	printf("버블정렬을 사용한 학번정렬\n");
	printf("-----------------------\n");
	BubbleSort(head);
	print_list(head);
	printf("-----------------------\n");
	printf("\n");

	printf("선택정렬을 사용한 이름정렬\n");
	printf("-----------------------\n");
	SelectSort(head);
	print_list(head);
	printf("-----------------------\n");
	printf("\n");

	printf("삽입정렬을 사용한 총점정렬\n");
	printf("-----------------------\n");
	//InsertionSort(head);
	//print_list(head);
	printf("-----------------------\n");
	printf("\n");


	delete_list(head);
	free(head);
	return 0;
}