////////////////////////////////////////////////////////////////
//
// �ۼ��� : ������
// �ۼ��� : 2022�� 5�� 24��
// ���α׷��� : ���� ���� ���α׷�
// ���α׷����� : ���Ḯ��Ʈ�� �̿��Ͽ� 2���� ���׽��� ���ϴ� ���� ���� ���α׷� �Դϴ�.
//				   
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct ListNode {	//���
	int coef;	//����� ���
	int expon;	//����� ����
	struct ListNode* link;	//����� ������ ��ũ
}ListNode;

typedef struct ListType {	//���Ḯ��Ʈ�� ���¸� �����ص� ����ü
	int size;	//���Ḯ��Ʈ�� ����(��ü ����� ����)
	ListNode* head;	//���Ḯ��Ʈ�� �� ��
	ListNode* tail;	//���Ḯ��Ʈ�� �� ��
}ListType;

void error(char* message) {	//������ ��Ÿ���� �Լ�
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {	//����ü �����Լ�
	ListType* plist = (ListType*)malloc(sizeof(ListType));	//������ ����ü�� �����Ҵ� �Ѵ�
	plist->size = 0;	//�� ó�� ������� �ƹ��͵� ���� ������ 0
	plist->head = plist->tail = NULL;	//����Ʈ�ȿ��� �ƹ��͵� ���� ������ head�� tail�� NULL�̴�
	return plist;	//������ ���� ����Ʈ�� ����
}

void insert(ListType* plist, int coef, int expon) {	//����Ʈ ���� �Լ�
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));	//�Ű������� ���� ���� ���ο� ��忡 �����ؾ��ϱ� ������ ��带 �����Ҵ����� �����
	
	if (temp == NULL)	//����� ���� NULL�̸� ����
		error("�޸� �Ҵ� ����");

	temp->coef = coef;	//���θ��� ����� ����� ���� ������ �ʱ�ȭ���ش�
	temp->expon = expon;	//���θ��� ����� ������ ���� ������ �ʱ�ȭ���ش�
	temp->link = NULL;	//���θ��� ����̱� ������ link�� ���� NULL�̴�

		if (plist->head == NULL) {				//����Ʈ�� �ƹ��͵� ������� ���� ���
			plist->head = plist->tail = temp;	//������ ����� ���� ����Ʈ�� �־��ְ�, head�� tail�� ���� �ش� ���� �����Ѵ�
		}										//�� �ڵ�� ����Ʈ�� ���� ó�� �������� ����Ǿ���Ѵ�

		else {									//����Ʈ�� ��尡 ����ִ� ���
				if (plist->head->expon < temp->expon) {	//����Ʈ�� �� �տ� ���� ���(�� ���� �������� ���ο� ����� ������ ���� ���)
					temp->link = plist->head;	//����� ��ũ�� ��忡 �ɾ��ش�
					plist->head = temp;			//��带 ��忡 �Ǵ�
				}
				else if (plist->tail->expon > temp->expon) {	//����Ʈ�� �� �ڿ� ���� ���(�� ���� �������� ���ο� ����� ������ ���� ���)
					plist->tail->link = temp;	//tail�� ��ũ�� ��忡 �ɾ��ش�
					plist->tail = temp;			//tail�� ��忡 �Ǵ�
				}
				else{	//����Ʈ�� ���̿� ���� ���
					ListNode* q = plist->head;	//���� ����Ű�� ������
					ListNode* p = q->link;	//�ڸ� ����Ű�� ������
				while (p != NULL) {	//����Ʈ ���� ���� ���ؾ��ϱ� ������ �ݺ��� ���
					if (p->expon < temp->expon && q->expon > temp->expon) {	//���� ������ ����� �������� �۰�, ���� ������ ����� �������� ū ���(���� ��� ���̿� ���ο� ��尡 ���� ���)
						temp->link = p;	//��ũ�� ���� ����Ű�� �����Ϳ� �ɾ��ش�
						q->link = temp;	//�ڸ� ����Ű�� �������� ��ũ�� ���ο� ��带 �ɾ��ش�
						q = q->link;	//���� �����͸� ��ĭ �ڷ� ������
						p = p->link;	//���� �����͸� ��ĭ �ڷ� ������
					}
					else if(p->expon == temp->expon){	//������ ���� �� ������ ������ ���
						p->coef = p->coef + temp->coef;		//p�� ����� ���ο� ����� ����� ���Ѵ�
						q = q->link;	//���� �����͸� ��ĭ �ڷ� ������
						p = p->link;	//���� �����͸� ��ĭ �ڷ� ������
					}
					else {	//����� ���̿� ���� �ʴ� ���
						q = q->link;	//���� �����͸� ��ĭ �ڷ� ������
						p = p->link;	//���� �����͸� ��ĭ �ڷ� ������
						}
					}
				}
			}
	plist->size++;	//����Ʈ�� ��带 �߰��ϸ� size�� 1����
}

void poly_mul(ListType* plist1, ListType* plist2, ListType* plist3) {	//���׽� ���� �Լ�
	ListNode* a = plist1->head;	//���׽�1�� ���ۺκ��� ����Ű�� ��� a����
	ListNode* b = plist2->head;	//���׽�2�� ���ۺκ��� ����Ű�� ��� b����

	int mulcoef, mulexpon;	//����� ������ ���� ���� �����ϴ� �������� �����Ѵ�

	for (; a != NULL;a = a->link) {	//���׽�1�� �ݺ��ϴ� �ݺ���
		b = plist2->head;	//���׽�1�� �� �κ��� ���׽�2�� ��ü�� �� ����ϸ� ���׽�2�� �ٽ� �ʱ�ȭ�Ǿ���ϱ� ������ b�� �ٽ� �� ������ �����ش�
		for (; b != NULL;b = b->link) {	//���׽�2�� �ݺ��ϴ� �ݺ���
			mulcoef = a->coef * b->coef;	//���׽�1�� 2�� ����� ���� ���� mulcoef�� �ִ´�
			mulexpon = a->expon + b->expon;	//���׽�1�� 2�� ������ ���� ���� mulexpon�� �ִ´�
			insert(plist3, mulcoef, mulexpon);	//���� �Լ��� ����� ���� �ִ´�
		}
	}
}

void poly_print(ListType* plist) {	//���׽� ����Լ�
	ListNode* p = plist->head;	//����Ʈ�� ��带 ����Ű�� ���p ����

	printf("polynomial = ");	
	for (; p; p = p->link) {	//����Ʈ�� ó������ �ݺ��ؾ��ϱ� ������ �ݺ��� ���
		printf("%d^%d + ", p->coef, p->expon);	//����� ������ ���
	}
	printf("\n");	//����� ������ �ٹٲ�
}

ListNode* delete(ListType* head) {	//��� �����Լ�
	ListNode* removed;	//��带 ������ ������ ����

	if (head == NULL)	//����Ʈ�� �ƹ��͵� ������� ���� ���
		return NULL;	//NULL���� ����
	for (int i = 0; i <= head->size; i++) {	//����Ʈ�� ���̸�ŭ �ݺ��ؼ� ���ʷ� ����
	removed = head->head;	//��尡 �� ���� ����Ű���Ѵ�
	head = removed->link;	//����Ʈ�� ������ ����Ű���Ѵ�
	free(removed);	//�� ���� ����Ű�� ��带 ����(free)�Ѵ�
	}
	free(head);	//����Ʈ ����(ListType)
}

int main() {
	ListType* list1, * list2, * list3;	//���׽�1, ���׽�2, ���׽��� ���� ��Ÿ�� ���׽�3�� ����

	list1 = create();	//���׽�1 ����
	list2 = create();	//���׽�2 ����
	list3 = create();	//���׽�3 ����
	char ch[10];	//������ ���� �� ���׽��� ������ ���� char�迭 ��������
	int coef1, expon1;	//������ ����� ��Ÿ���� ���� �ΰ� ����
	int count = 0;	//���׽�1�� ���̸� �����ϴ� ���� ����

	FILE* fp = fopen("data.txt", "r");	//data.txt������ �б��������� ����
	if (fp == NULL) {	//������ ����� ������ ���� ���
		fprintf(stderr, "err");	//����
		exit(1);
	}

	fscanf(fp, "%s", &ch);	//������ ó�� ���ڿ��� �д´�(poly1)
	while (!feof(fp)) {	//������ ������ �ݺ�
		fscanf(fp, "%s", &ch);	//���ڿ����·� �д´�
		if (isalpha(ch[0]))	//���ڿ� ���ڰ� �ƴ� ���ĺ��� �� ���
			break;	//������
		count++;	//���̸� �ϳ��� ������Ų��
	}
	count /= 2;	//fscanf�� ����� �� ������ ����� �ѹ��� ���� ���̹Ƿ� ��ü ���̸� ������ �����ش�

	rewind(fp);	//���� �����͸� �� ������ �����ش�

	fscanf(fp, "%s", &ch);	//������ ó�� ���ڿ��� �д´�(poly1)
	for (int i = 0; i < count; i++) {	//���׽�1�� ������ ���ݸ�ŭ �ݺ�
		fscanf(fp, "%d %d", &coef1, &expon1);	//������ ����� �о�´�
		insert(list1, coef1, expon1);	//���� �Լ��� ����Ʈ(���׽�)�� ������ ����� �ִ´�
	}

	fscanf(fp, "%s", &ch);	//������ ó�� ���ڿ��� �д´�(poly2)
	while (!feof(fp)) {	//������ ������ �ݺ�
		fscanf(fp, "%d %d", &coef1, &expon1);	//������ ����� �о�´�
		insert(list2, coef1, expon1);	//���� �Լ��� ����Ʈ(���׽�)�� ������ ����� �ִ´�
	}

	poly_print(list1);	//���׽�1 ���
	poly_print(list2);	//���׽�2 ���

	poly_mul(list1, list2, list3);	//���׽�1�� ���׽�2�� ���� ���׽�3�� ����

	poly_print(list3);	//���׽�3 ���

	delete(list1);	//���׽�1 ����
	delete(list2);	//���׽�2 ����
	delete(list3);	//���׽�3 ����

	fclose(fp);	//���� �ݱ�
	return 0;
}