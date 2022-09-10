//////////////////////////////////////////////////////////
//
// 작성자 : 이찬희  
// 작성일 : 2022년 9월 10일
// 프로그램명 : 연결리스트 정렬 프로그램
// 프로그램설명 : 정렬 방법을 여러가지 사용해 연결리스트를
//				  정렬하는 프로그램입니다.
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode { // 노드 구조체 정의
	int id; // int형 학번
	char name[20]; // char배열 이름
	double score; // double형 총점
	struct ListNode* link; // link노드
}ListNode;

typedef struct ListType { // ListType구조체 정의
	int size; // 리스트 전체 크기
	ListNode* tail; // 맨 마지막 노드
	ListNode* head; // 맨 앞 노드
}ListType;

ListType* create() { // ListType 생성함수
	ListType* plist = (ListType*)malloc(sizeof(ListType)); // 동적할당으로 ListType생성
	plist->size = 0; // 맨 처음 크기 0
	plist->head = plist->tail = NULL; // head와 tail을 NULL로 초기화
	return plist; // 초기화한 ListType 리턴
}

void insert_last(ListType* head, int id, char name[], double avg) { // 리스트 삽입함수
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // 동적할당으로 ListNode 생성
	p->id = id; // 매개변수로 받은 학번 구조체에 넣기
	strcpy(p->name, name); // 매개변수로 받은 이름 구조체에 넣기
	p->score = avg; // 매개변수로 받은 총점 구조체에 넣기
	p->link = NULL; // link를 NULL로 초기화
	if (head->tail == NULL) { // 리스트에 아무것도 없는 경우
		head->head = head->tail = p; // head와 tail을 p로 초기화
	}
	else { // 리스트에 노드가 있는 경우
		head->tail->link = p; // 마지막 노드에 p노드를 연결
		head->tail = p; // tail을 p로 초기화
	}
	head->size++; // 리스트 size를 1증가
}

void print_list(ListType* head) { // 리스트 출력함수
	ListNode* p; // 노드 생성
	for (p = head->head; p != NULL; p = p->link) { // 리스트 출력 반복문
		printf("%d %s %.2lf \n", p->id, p->name, p->score); // 학번 이름 총점순으로 출력
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

void InsertionSort(ListType* head) { // 삽입정렬 함수
	ListNode* p, * q, * r; // p는 가장 앞서가는 노드, q는 중간 노드, r은 가장 뒤에 있는 노드
	if (head->size == 1) // 리스트의 크기가 1이면 함수 종료
		exit(1);
	for (int i = 0; i < head->size - 1; i++) { // 전체 정렬 횟수를 담당하는 반복문
		for (int j = i; j >= 0; j--) { // 정렬 반복 횟수를 담당하는 반복문
			p = head->head, q = NULL, r = NULL; // p, q, r의 값을 초기화 시킨다
				for (int k = j; k >= 0; k--) { // 노드의 위치를 바꿔주는 반복문
					r = q; // r을 q로 초기화
					q = p; // q를 p로 초기화
					p = p->link; // p를 다음으로 넘긴다
				}
				if (p->score > q->score) { // p의 점수가 q의 점수보다 높은 경우
					if (p->link == NULL) { // 맨 마지막 노드를 교체해야 하는 경우
						p->link = q; // p->link를 q에 연결한다
						r->link = p; // r->link를 p에 연결한다
						q->link = NULL; // q->link를 NULL로 초기화
					}
					else if (r== NULL) { // 맨 앞의 노드를 교체해야 하는 경우
						q->link = p->link; // q->link를 p->link에 연결한다
						p->link = q; // p->link를 q에 연결한다
						head->head = p; // head를 p로 초기화
					}
					else { // 나머지의 경우
						q->link = p->link; // q->link를 p->link에 연결한다
						p->link = q; // p->link를 q에 연결한다
						r->link = p; // r->link를 p에 연결한다
					}
				}
			}
		head->tail = q; // 정렬이 다 끝나면 tail을 q로 초기화 시킨다
	}
}

void delete_list(ListType* head) { // 리스트 삭제함수
	ListNode* p = head->head; // 노드 p 생성 후 head로 초기화
	ListNode* pre; // p노드를 뒤따라갈 노드 pre 생성
	while (p != NULL) { // 노드 p가 NULL이 아닌 경우 반복
		pre = p; // pre를 p로 초기화
		p = p->link; // p를 다음으로 넘김
		free(pre); // pre를 삭제
	}
}

int main() {
	FILE* fp; // 파일포인터 fp 생성
	int id; // 파일데이터를 받을 int형 변수
	char name[20]; // 파일데이터를 받을 char배열
	double avg; // 파일 데이터를 받을 double형 변수
	ListType* head; // ListType 생성
	head = create(); // ListType 초기화

	fp = fopen("data.txt", "r"); // data.txt파일 읽기모드로 열기
	if (fp == NULL) { // 데이터 파일이 없는 경우
		fprintf(stderr, "err"); // 에러
		exit(1);
	}

	while (!feof(fp)) { // 파일의 끝까지 읽기
		fscanf(fp, "%d %s %lf", &id, name, &avg); // int형 char배열 double형 순으로 읽기
		insert_last(head, id, name, avg); // 리스트 삽입함수에 ListType과 읽은 데이터 넣기
	}

	printf("기본 데이터\n");
	printf("-----------------------\n");
	print_list(head); // 리스트 출력
	printf("-----------------------\n");
	printf("\n");

	printf("버블정렬을 사용한 학번정렬\n");
	printf("-----------------------\n");
	BubbleSort(head); // 버블정렬
	print_list(head); // 리스트 출력
	printf("-----------------------\n");
	printf("\n");

	printf("선택정렬을 사용한 이름정렬\n");
	printf("-----------------------\n");
	SelectSort(head); // 선택정렬
	print_list(head); // 리스트 출력
	printf("-----------------------\n");
	printf("\n");

	printf("삽입정렬을 사용한 총점정렬\n");
	printf("-----------------------\n");
	InsertionSort(head); // 삽입정렬
	print_list(head); // 리스트 출력
	printf("-----------------------\n");
	printf("\n");

	delete_list(head); // 리스트 삭제
	free(head); // ListType 삭제
	return 0;
}