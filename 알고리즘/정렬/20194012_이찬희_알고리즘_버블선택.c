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

void BubbleSort(ListType* head) { // 버블정렬 함수
	ListNode* p, * q, * r; // p는 가장 앞서가는 노드, q는 중간 노드, r은 가장 마지막에 있는 노드
	if (head->size == 1) // 리스트의 크기가 1이면 함수 종료
		exit(1);
	for (int i = 0; i < head->size; i++) { // 전체 정렬 횟수를 담당하는 반복문
		p = head->head, q = head->head, r = NULL; // p, q, r 초기화
		for (p = p->link; p != NULL; p = p->link) { // 값을 비교해 정렬하는 반복문
			if (q->id > p->id) { // q의 학번이 p의 학번보다 큰 경우
				if (r == NULL) { // 맨 앞의 경우
					head->head = p; // head를 p로 초기화
					q->link = p->link; // q->link 가 p->link 를 가리킨다
					p->link = q; // p->link 가 q를 가리킨다

					q = p; // q를 p로 옮긴다
					p = p->link; // p를 다음 노드로 이동시킨다

					r = q; // r을 q로 옮긴다
					q = q->link; // q를 다음 노드로 이동시킨다
				}
				else { // 맨 앞이 아닌 경우
					q->link = p->link; // q->link 가 p->link 를 가리킨다
					p->link = q; // p->link 가 q를 가리킨다
					r->link = p; // r->link 가 p를 가리킨다

					q = p; // q를 p로 옮긴다
					p = p->link; // p를 다음 노드로 이동시킨다

					q = q->link; // q를 다음 노드로 이동시킨다
					r = r->link; // r을 다음 노드로 이동시킨다
				}
			}
			else { // 나머지의 경우
				r = q; // r을 q로 옮긴다
				q = q->link; // q를 다음 노드로 이동시킨다(p는 반복문의 조건에서 이동시키기 때문에 선언x)
			}
		}
	}
	head->tail = q; // 정렬이 다 끝나면 tail을 q로 초기화 시킨다
}

void SelectSort(ListType* head) { // 선택정렬 함수
	ListNode* p, * q, * r, * s; // p는 가장 앞서가는 노드, q는 p의 앞에 오는 노드, r은 교체할 자리에 오는 노드, s는 r의 앞에 오는 노드
	int count = 0; // 헤드를 설정하기 위한 임의의 변수
	char name[20]; // 이름을 담을 변수
	if (head->size == 1) { //전체 크기가 1이면 함수종료
		exit(1); 
	}
	p = head->head, q = head->head, r = head->head, s = NULL; //p, q, r, s의 초기값 설정
	for (int i = 0; i < head->size - 1; i++) { //이중포문의 바깥 포문으로 선택정렬의 반복을 담당
		p = r; // p를 r로 초기화
		q = r; // q를 r로 초기화
		strcpy(name, r->name); //r의 이름값을 name변수에 복사해두기
		for (int j = head->size - 1; j > i; j--) { // 이름의 최솟값 찾는 반복문
			q = p; //q를 p로 초기화
			p = p->link; // p의 위치를 다음으로 옮기기

			if (strcmp(name, p->name) > 0) { //복사해둔 name의 값이 p의 name의 값보다 큰 경우 name에 p의 name값 옮기기
				strcpy(name, p->name);
			}
		}
		p = r; // p를 r로 초기화
		for (q = r, p = p->link; p != NULL; p = p->link) { //q를 r로 초기화, p의 위치를 다음으로 옮기기 / 이름의 최솟값과 맨 앞(r)의 위치를 바꾸는 반복문
			if (strcmp(name, p->name) == 0) { // 같은 이름을 발견한 경우
				if (p->link == NULL) { //바꿔야 할 이름이 연결리스트의 마지막에 있는 경우
					if (s == NULL) { //교체해야할 이름이 맨 앞에 있는 경우
						p->link = r->link; // p->link가 r->link를 가리킨다
						q->link = r; //	q->link가 r을 가리킨다
						r->link = NULL; // r->link가 NULL이 된다
						r = p; // r을 p로 초기화 시킨다
					}
					else if (r == q) { // 변경해야 할 이름을 바로 찾은 경우
						p->link = q; // p->link 가 q를 가리킨다
						s->link = p; // s->link 가 p를 가리킨다 
						q->link = NULL; // q->link 가 NULL이 된다
						r = p; // r을 p로 초기화 시킨다
					}
					else { // 나머지의 경우
						p->link = r->link; // p->link 가 r->link를 가리킨다
						q->link = r; // q->link 가 r을 가리킨다
						r->link = NULL; // r->link가 NULL이 된다
						s->link = p; // s->link 가 p를 가리킨다
						r = p; // r을 p로 초기화 시킨다
					}
				}
				else { // 바꿔야 할 이름이 연결리스트의 마지막에 있지 않은 경우
					if (s == NULL) { // 교체해야 할 이름이 맨 앞에 있는 경우
						q->link = p->link; // q->link 가 p->link 를 가리킨다
						p->link = r->link; // p->link가 r->link 를 가리킨다
						r->link = q->link; // r->link가 q->link를 가리킨다
						q->link = r; // q->link가 r을 가리킨다
						r = p; // r을 p로 초기화 시킨다
					}
					else if (r == q) { // 변경해야 할 이름을 바로 찾은 경우
						q->link = p->link; // q->link 가 p->link 를 가리킨다
						p->link = q; // p->link가 q를 가리킨다
						s->link = p; // s->link가 p를 가리킨다
						r = p;  // r을 p로 초기화 시킨다
					}
					else { // 나머지의 경우
						q->link = p->link; // q->link 가 p->link 를 가리킨다
						p->link = r->link; // p->link가 r->link 를 가리킨다
						r->link = q->link; // r->link가 q->link를 가리킨다
						q->link = r; // q->link가 r을 가리킨다
						s->link = p; // s->link가 p를 가리킨다
						r = p; // r을 p로 초기화 시킨다
					}
				}
				if (count == 0) { // 처음 교체하는 경우(head의 재설정)
					head->head = r; // head를 r로 변경한다
					count++; // 임의의 변수인 count를 1증가시킨다
				}
				break; // 위치 바꾸는 반복문 멈추기
			}
			q = q->link; // 같은 이름을 찾지 못한 경우 다음 노드로 이동(p는 반복문에서 옮겨주기 때문에 여기선 q만 이동)
		}
		s = r; // s를 r로 초기화 시킨다
		r = r->link; // r을 다음 노드로 이동
	}
	head->tail = r; // 모든 정렬이 끝나면 마지막으로 tail을 r로 초기화 시킨다
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