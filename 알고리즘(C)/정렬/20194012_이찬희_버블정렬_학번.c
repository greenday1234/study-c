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
		return head;
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

	print_list(head);
	printf("----------\n");
	BubbleSort(head);
	print_list(head);
	return 0;
}