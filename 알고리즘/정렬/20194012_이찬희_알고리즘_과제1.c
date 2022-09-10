//////////////////////////////////////////////////////////
//
// �ۼ��� : ������  
// �ۼ��� : 2022�� 9�� 10��
// ���α׷��� : ���Ḯ��Ʈ ���� ���α׷�
// ���α׷����� : ���� ����� �������� ����� ���Ḯ��Ʈ��
//				  �����ϴ� ���α׷��Դϴ�.
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode { // ��� ����ü ����
	int id; // int�� �й�
	char name[20]; // char�迭 �̸�
	double score; // double�� ����
	struct ListNode* link; // link���
}ListNode;

typedef struct ListType { // ListType����ü ����
	int size; // ����Ʈ ��ü ũ��
	ListNode* tail; // �� ������ ���
	ListNode* head; // �� �� ���
}ListType;

ListType* create() { // ListType �����Լ�
	ListType* plist = (ListType*)malloc(sizeof(ListType)); // �����Ҵ����� ListType����
	plist->size = 0; // �� ó�� ũ�� 0
	plist->head = plist->tail = NULL; // head�� tail�� NULL�� �ʱ�ȭ
	return plist; // �ʱ�ȭ�� ListType ����
}

void insert_last(ListType* head, int id, char name[], double avg) { // ����Ʈ �����Լ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // �����Ҵ����� ListNode ����
	p->id = id; // �Ű������� ���� �й� ����ü�� �ֱ�
	strcpy(p->name, name); // �Ű������� ���� �̸� ����ü�� �ֱ�
	p->score = avg; // �Ű������� ���� ���� ����ü�� �ֱ�
	p->link = NULL; // link�� NULL�� �ʱ�ȭ
	if (head->tail == NULL) { // ����Ʈ�� �ƹ��͵� ���� ���
		head->head = head->tail = p; // head�� tail�� p�� �ʱ�ȭ
	}
	else { // ����Ʈ�� ��尡 �ִ� ���
		head->tail->link = p; // ������ ��忡 p��带 ����
		head->tail = p; // tail�� p�� �ʱ�ȭ
	}
	head->size++; // ����Ʈ size�� 1����
}

void print_list(ListType* head) { // ����Ʈ ����Լ�
	ListNode* p; // ��� ����
	for (p = head->head; p != NULL; p = p->link) { // ����Ʈ ��� �ݺ���
		printf("%d %s %.2lf \n", p->id, p->name, p->score); // �й� �̸� ���������� ���
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

void InsertionSort(ListType* head) { // �������� �Լ�
	ListNode* p, * q, * r; // p�� ���� �ռ����� ���, q�� �߰� ���, r�� ���� �ڿ� �ִ� ���
	if (head->size == 1) // ����Ʈ�� ũ�Ⱑ 1�̸� �Լ� ����
		exit(1);
	for (int i = 0; i < head->size - 1; i++) { // ��ü ���� Ƚ���� ����ϴ� �ݺ���
		for (int j = i; j >= 0; j--) { // ���� �ݺ� Ƚ���� ����ϴ� �ݺ���
			p = head->head, q = NULL, r = NULL; // p, q, r�� ���� �ʱ�ȭ ��Ų��
				for (int k = j; k >= 0; k--) { // ����� ��ġ�� �ٲ��ִ� �ݺ���
					r = q; // r�� q�� �ʱ�ȭ
					q = p; // q�� p�� �ʱ�ȭ
					p = p->link; // p�� �������� �ѱ��
				}
				if (p->score > q->score) { // p�� ������ q�� �������� ���� ���
					if (p->link == NULL) { // �� ������ ��带 ��ü�ؾ� �ϴ� ���
						p->link = q; // p->link�� q�� �����Ѵ�
						r->link = p; // r->link�� p�� �����Ѵ�
						q->link = NULL; // q->link�� NULL�� �ʱ�ȭ
					}
					else if (r== NULL) { // �� ���� ��带 ��ü�ؾ� �ϴ� ���
						q->link = p->link; // q->link�� p->link�� �����Ѵ�
						p->link = q; // p->link�� q�� �����Ѵ�
						head->head = p; // head�� p�� �ʱ�ȭ
					}
					else { // �������� ���
						q->link = p->link; // q->link�� p->link�� �����Ѵ�
						p->link = q; // p->link�� q�� �����Ѵ�
						r->link = p; // r->link�� p�� �����Ѵ�
					}
				}
			}
		head->tail = q; // ������ �� ������ tail�� q�� �ʱ�ȭ ��Ų��
	}
}

void delete_list(ListType* head) { // ����Ʈ �����Լ�
	ListNode* p = head->head; // ��� p ���� �� head�� �ʱ�ȭ
	ListNode* pre; // p��带 �ڵ��� ��� pre ����
	while (p != NULL) { // ��� p�� NULL�� �ƴ� ��� �ݺ�
		pre = p; // pre�� p�� �ʱ�ȭ
		p = p->link; // p�� �������� �ѱ�
		free(pre); // pre�� ����
	}
}

int main() {
	FILE* fp; // ���������� fp ����
	int id; // ���ϵ����͸� ���� int�� ����
	char name[20]; // ���ϵ����͸� ���� char�迭
	double avg; // ���� �����͸� ���� double�� ����
	ListType* head; // ListType ����
	head = create(); // ListType �ʱ�ȭ

	fp = fopen("data.txt", "r"); // data.txt���� �б���� ����
	if (fp == NULL) { // ������ ������ ���� ���
		fprintf(stderr, "err"); // ����
		exit(1);
	}

	while (!feof(fp)) { // ������ ������ �б�
		fscanf(fp, "%d %s %lf", &id, name, &avg); // int�� char�迭 double�� ������ �б�
		insert_last(head, id, name, avg); // ����Ʈ �����Լ��� ListType�� ���� ������ �ֱ�
	}

	printf("�⺻ ������\n");
	printf("-----------------------\n");
	print_list(head); // ����Ʈ ���
	printf("-----------------------\n");
	printf("\n");

	printf("���������� ����� �й�����\n");
	printf("-----------------------\n");
	BubbleSort(head); // ��������
	print_list(head); // ����Ʈ ���
	printf("-----------------------\n");
	printf("\n");

	printf("���������� ����� �̸�����\n");
	printf("-----------------------\n");
	SelectSort(head); // ��������
	print_list(head); // ����Ʈ ���
	printf("-----------------------\n");
	printf("\n");

	printf("���������� ����� ��������\n");
	printf("-----------------------\n");
	InsertionSort(head); // ��������
	print_list(head); // ����Ʈ ���
	printf("-----------------------\n");
	printf("\n");

	delete_list(head); // ����Ʈ ����
	free(head); // ListType ����
	return 0;
}