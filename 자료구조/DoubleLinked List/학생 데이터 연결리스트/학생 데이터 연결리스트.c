#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DListNode {

	char name[50];
	int num;
	int scores[3];

	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void addStudent(DListNode* head) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	printf("추가할 학생 번호: ");
	scanf("%d", &newnode->num);
	printf("이름: ");
	scanf("%s", newnode->name);
	printf("국어 성적: ");
	scanf("%d", &newnode->scores[0]);
	printf("영어 성적: ");
	scanf("%d", &newnode->scores[1]);
	printf("수학 성적: ");
	scanf("%d", &newnode->scores[2]);

	newnode->rlink = head;
	newnode->llink = head->llink;
	head->llink->rlink = newnode;
	head->llink = newnode;
}

void deleteStudent(DListNode* head) {
	int num;
	DListNode* p;
	printf("삭제할 학생 번호: ");
	scanf("%d", &num);

	for (p = head->rlink; p != head; p = p->rlink) {
		if (p->num == num) {
			p->llink->rlink = p->rlink;
			p->rlink->llink = p->llink;
			free(p); 
			printf("삭제 완료\n");
			return;
		}
	}
	printf("찾는 학생이 없습니다.\n");
}

void findStudent(DListNode* head) {
	int num;
	DListNode* p;
	printf("검색할 학생 번호: ");
	scanf("%d", &num);

	for (p = head->rlink; p != head; p = p->rlink) {
		if (p->num == num) {
			printf("학생 번호 : %d\n", p->num);
			printf("학생 이름 : %s\n", p->name);
			printf("국어 성적 : %d\n", p->scores[0]);
			printf("영어 성적 : %d\n", p->scores[1]);
			printf("수학 성적 : %d\n", p->scores[2]);

			return;
		}
	}
	printf("찾는 학생이 없습니다.\n");
}

void printStudent(DListNode* head) {
	DListNode* p;
	printf("번호\t이름 국어 영어 수학 성적이 -1인 곳은 미입력\n");
	for (p = head->rlink; p != head; p = p->rlink) {
		printf("%d\t%s %d %d %d\n", p->num, p->name, p->scores[0], p->scores[1], p->scores[2]);
	}
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	int n;
	init(head);

	do {
		printf("성적 관리 프로그램 \n");
		printf("0:종료 1: 학생 데이터 입력 2: 학생 데이터 삭제 3: 학생 검색 4: 목록 보기\n");
		scanf("%d", &n);

		switch (n) {
		case 1:
			addStudent(head);
			break;
		case 2:
			deleteStudent(head);
			break;
		case 3:
			findStudent(head);
			break;
		case 4:
			printStudent(head);
			break;
		default:
			if (n != 0) {
				printf("명령어가 잘못됐습니다.\n");
			}
			break;
		}
	} while (n != 0);
		printf("프로그램 종료");
		free(head);
		return 0;
}