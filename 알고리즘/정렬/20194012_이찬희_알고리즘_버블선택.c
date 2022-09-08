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

void BubbleSort(ListType* head) { // �������� �Լ�
	ListNode* p, * q, * r; // p�� ���� �ռ����� ���, q�� �߰� ���, r�� ���� �������� �ִ� ���
	if (head->size == 1) // ����Ʈ�� ũ�Ⱑ 1�̸� �Լ� ����
		exit(1);
	for (int i = 0; i < head->size; i++) { // ��ü ���� Ƚ���� ����ϴ� �ݺ���
		p = head->head, q = head->head, r = NULL; // p, q, r �ʱ�ȭ
		for (p = p->link; p != NULL; p = p->link) { // ���� ���� �����ϴ� �ݺ���
			if (q->id > p->id) { // q�� �й��� p�� �й����� ū ���
				if (r == NULL) { // �� ���� ���
					head->head = p; // head�� p�� �ʱ�ȭ
					q->link = p->link; // q->link �� p->link �� ����Ų��
					p->link = q; // p->link �� q�� ����Ų��

					q = p; // q�� p�� �ű��
					p = p->link; // p�� ���� ���� �̵���Ų��

					r = q; // r�� q�� �ű��
					q = q->link; // q�� ���� ���� �̵���Ų��
				}
				else { // �� ���� �ƴ� ���
					q->link = p->link; // q->link �� p->link �� ����Ų��
					p->link = q; // p->link �� q�� ����Ų��
					r->link = p; // r->link �� p�� ����Ų��

					q = p; // q�� p�� �ű��
					p = p->link; // p�� ���� ���� �̵���Ų��

					q = q->link; // q�� ���� ���� �̵���Ų��
					r = r->link; // r�� ���� ���� �̵���Ų��
				}
			}
			else { // �������� ���
				r = q; // r�� q�� �ű��
				q = q->link; // q�� ���� ���� �̵���Ų��(p�� �ݺ����� ���ǿ��� �̵���Ű�� ������ ����x)
			}
		}
	}
	head->tail = q; // ������ �� ������ tail�� q�� �ʱ�ȭ ��Ų��
}

void SelectSort(ListType* head) { // �������� �Լ�
	ListNode* p, * q, * r, * s; // p�� ���� �ռ����� ���, q�� p�� �տ� ���� ���, r�� ��ü�� �ڸ��� ���� ���, s�� r�� �տ� ���� ���
	int count = 0; // ��带 �����ϱ� ���� ������ ����
	char name[20]; // �̸��� ���� ����
	if (head->size == 1) { //��ü ũ�Ⱑ 1�̸� �Լ�����
		exit(1); 
	}
	p = head->head, q = head->head, r = head->head, s = NULL; //p, q, r, s�� �ʱⰪ ����
	for (int i = 0; i < head->size - 1; i++) { //���������� �ٱ� �������� ���������� �ݺ��� ���
		p = r; // p�� r�� �ʱ�ȭ
		q = r; // q�� r�� �ʱ�ȭ
		strcpy(name, r->name); //r�� �̸����� name������ �����صα�
		for (int j = head->size - 1; j > i; j--) { // �̸��� �ּڰ� ã�� �ݺ���
			q = p; //q�� p�� �ʱ�ȭ
			p = p->link; // p�� ��ġ�� �������� �ű��

			if (strcmp(name, p->name) > 0) { //�����ص� name�� ���� p�� name�� ������ ū ��� name�� p�� name�� �ű��
				strcpy(name, p->name);
			}
		}
		p = r; // p�� r�� �ʱ�ȭ
		for (q = r, p = p->link; p != NULL; p = p->link) { //q�� r�� �ʱ�ȭ, p�� ��ġ�� �������� �ű�� / �̸��� �ּڰ��� �� ��(r)�� ��ġ�� �ٲٴ� �ݺ���
			if (strcmp(name, p->name) == 0) { // ���� �̸��� �߰��� ���
				if (p->link == NULL) { //�ٲ�� �� �̸��� ���Ḯ��Ʈ�� �������� �ִ� ���
					if (s == NULL) { //��ü�ؾ��� �̸��� �� �տ� �ִ� ���
						p->link = r->link; // p->link�� r->link�� ����Ų��
						q->link = r; //	q->link�� r�� ����Ų��
						r->link = NULL; // r->link�� NULL�� �ȴ�
						r = p; // r�� p�� �ʱ�ȭ ��Ų��
					}
					else if (r == q) { // �����ؾ� �� �̸��� �ٷ� ã�� ���
						p->link = q; // p->link �� q�� ����Ų��
						s->link = p; // s->link �� p�� ����Ų�� 
						q->link = NULL; // q->link �� NULL�� �ȴ�
						r = p; // r�� p�� �ʱ�ȭ ��Ų��
					}
					else { // �������� ���
						p->link = r->link; // p->link �� r->link�� ����Ų��
						q->link = r; // q->link �� r�� ����Ų��
						r->link = NULL; // r->link�� NULL�� �ȴ�
						s->link = p; // s->link �� p�� ����Ų��
						r = p; // r�� p�� �ʱ�ȭ ��Ų��
					}
				}
				else { // �ٲ�� �� �̸��� ���Ḯ��Ʈ�� �������� ���� ���� ���
					if (s == NULL) { // ��ü�ؾ� �� �̸��� �� �տ� �ִ� ���
						q->link = p->link; // q->link �� p->link �� ����Ų��
						p->link = r->link; // p->link�� r->link �� ����Ų��
						r->link = q->link; // r->link�� q->link�� ����Ų��
						q->link = r; // q->link�� r�� ����Ų��
						r = p; // r�� p�� �ʱ�ȭ ��Ų��
					}
					else if (r == q) { // �����ؾ� �� �̸��� �ٷ� ã�� ���
						q->link = p->link; // q->link �� p->link �� ����Ų��
						p->link = q; // p->link�� q�� ����Ų��
						s->link = p; // s->link�� p�� ����Ų��
						r = p;  // r�� p�� �ʱ�ȭ ��Ų��
					}
					else { // �������� ���
						q->link = p->link; // q->link �� p->link �� ����Ų��
						p->link = r->link; // p->link�� r->link �� ����Ų��
						r->link = q->link; // r->link�� q->link�� ����Ų��
						q->link = r; // q->link�� r�� ����Ų��
						s->link = p; // s->link�� p�� ����Ų��
						r = p; // r�� p�� �ʱ�ȭ ��Ų��
					}
				}
				if (count == 0) { // ó�� ��ü�ϴ� ���(head�� �缳��)
					head->head = r; // head�� r�� �����Ѵ�
					count++; // ������ ������ count�� 1������Ų��
				}
				break; // ��ġ �ٲٴ� �ݺ��� ���߱�
			}
			q = q->link; // ���� �̸��� ã�� ���� ��� ���� ���� �̵�(p�� �ݺ������� �Ű��ֱ� ������ ���⼱ q�� �̵�)
		}
		s = r; // s�� r�� �ʱ�ȭ ��Ų��
		r = r->link; // r�� ���� ���� �̵�
	}
	head->tail = r; // ��� ������ ������ ���������� tail�� r�� �ʱ�ȭ ��Ų��
}

/*void InsertionSort(ListType* head) {
}*/

void delete_list(ListType* head) {
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

	printf("�⺻ ������\n");
	printf("-----------------------\n");
	print_list(head);
	printf("-----------------------\n");
	printf("\n");

	printf("���������� ����� �й�����\n");
	printf("-----------------------\n");
	BubbleSort(head);
	print_list(head);
	printf("-----------------------\n");
	printf("\n");

	printf("���������� ����� �̸�����\n");
	printf("-----------------------\n");
	SelectSort(head);
	print_list(head);
	printf("-----------------------\n");
	printf("\n");

	printf("���������� ����� ��������\n");
	printf("-----------------------\n");
	//InsertionSort(head);
	//print_list(head);
	printf("-----------------------\n");
	printf("\n");


	delete_list(head);
	free(head);
	return 0;
}