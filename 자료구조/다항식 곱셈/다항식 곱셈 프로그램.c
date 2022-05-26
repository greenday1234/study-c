////////////////////////////////////////////////////////////////
//
// 작성자 : 이찬희
// 작성일 : 2022년 5월 24일
// 프로그램명 : 곱셈 연산 프로그램
// 프로그램설명 : 연결리스트를 이용하여 2개의 다항식을 곱하는 곱셈 연산 프로그램 입니다.
//				   
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct ListNode {	//노드
	int coef;	//노드의 계수
	int expon;	//노드의 차수
	struct ListNode* link;	//노드의 포인터 링크
}ListNode;

typedef struct ListType {	//연결리스트의 상태를 저장해둔 구조체
	int size;	//연결리스트의 길이(전체 노드의 개수)
	ListNode* head;	//연결리스트의 맨 앞
	ListNode* tail;	//연결리스트의 맨 뒤
}ListType;

void error(char* message) {	//에러를 나타내는 함수
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {	//구조체 생성함수
	ListType* plist = (ListType*)malloc(sizeof(ListType));	//생성한 구조체를 동적할당 한다
	plist->size = 0;	//맨 처음 사이즈는 아무것도 없기 때문에 0
	plist->head = plist->tail = NULL;	//리스트안에는 아무것도 없기 때문에 head와 tail이 NULL이다
	return plist;	//위에서 만든 리스트를 리턴
}

void insert(ListType* plist, int coef, int expon) {	//리스트 삽입 함수
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));	//매개변수로 받은 값을 새로운 노드에 저장해야하기 때문에 노드를 동적할당으로 만든다
	
	if (temp == NULL)	//노드의 값이 NULL이면 오류
		error("메모리 할당 에러");

	temp->coef = coef;	//새로만든 노드의 계수를 받은 값으로 초기화해준다
	temp->expon = expon;	//새로만든 노드의 차수를 받은 값으로 초기화해준다
	temp->link = NULL;	//새로만든 노드이기 때문에 link의 값은 NULL이다

		if (plist->head == NULL) {				//리스트에 아무것도 들어있지 않은 경우
			plist->head = plist->tail = temp;	//생성한 노드의 값을 리스트에 넣어주고, head와 tail의 값을 해당 노드로 지정한다
		}										//이 코드는 리스트의 값을 처음 넣을때만 실행되어야한다

		else {									//리스트에 노드가 들어있는 경우
				if (plist->head->expon < temp->expon) {	//리스트의 맨 앞에 들어가는 경우(맨 앞의 차수보다 새로운 노드의 차수가 높은 경우)
					temp->link = plist->head;	//노드의 링크를 헤드에 걸어준다
					plist->head = temp;			//헤드를 노드에 건다
				}
				else if (plist->tail->expon > temp->expon) {	//리스트의 맨 뒤에 들어가는 경우(맨 뒤의 차수보다 새로운 노드의 차수가 낮은 경우)
					plist->tail->link = temp;	//tail의 링크를 노드에 걸어준다
					plist->tail = temp;			//tail을 노드에 건다
				}
				else{	//리스트의 사이에 들어가는 경우
					ListNode* q = plist->head;	//앞을 가리키는 포인터
					ListNode* p = q->link;	//뒤를 가리키는 포인터
				while (p != NULL) {	//리스트 안의 값을 비교해야하기 때문에 반복문 사용
					if (p->expon < temp->expon && q->expon > temp->expon) {	//뒤의 차수가 노드의 차수보다 작고, 앞의 차수가 노드의 차수보다 큰 경우(노드와 노드 사이에 새로운 노드가 들어가는 경우)
						temp->link = p;	//링크를 앞을 가리키는 포인터에 걸어준다
						q->link = temp;	//뒤를 가리키는 포인터의 링크에 새로운 노드를 걸어준다
						q = q->link;	//앞쪽 포인터를 한칸 뒤로 보낸다
						p = p->link;	//뒤쪽 포인터를 한칸 뒤로 보낸다
					}
					else if(p->expon == temp->expon){	//곱셈을 했을 때 차수가 같아진 경우
						p->coef = p->coef + temp->coef;		//p의 계수에 새로운 노드의 계수를 더한다
						q = q->link;	//앞쪽 포인터를 한칸 뒤로 보낸다
						p = p->link;	//뒤쪽 포인터를 한칸 뒤로 보낸다
					}
					else {	//노드의 사이에 들어가지 않는 경우
						q = q->link;	//앞쪽 포인터를 한칸 뒤로 보낸다
						p = p->link;	//뒤쪽 포인터를 한칸 뒤로 보낸다
						}
					}
				}
			}
	plist->size++;	//리스트에 노드를 추가하면 size를 1증가
}

void poly_mul(ListType* plist1, ListType* plist2, ListType* plist3) {	//다항식 곱셈 함수
	ListNode* a = plist1->head;	//다항식1의 시작부분을 가리키는 노드 a생성
	ListNode* b = plist2->head;	//다항식2의 시작부분을 가리키는 노드 b생성

	int mulcoef, mulexpon;	//계수와 차수를 곱한 값을 저장하는 변수들을 선언한다

	for (; a != NULL;a = a->link) {	//다항식1을 반복하는 반복문
		b = plist2->head;	//다항식1의 한 부분이 다항식2의 전체를 다 계산하면 다항식2가 다시 초기화되어야하기 때문에 b를 다시 맨 앞으로 보내준다
		for (; b != NULL;b = b->link) {	//다항식2를 반복하는 반복문
			mulcoef = a->coef * b->coef;	//다항식1과 2의 계수를 곱한 값을 mulcoef에 넣는다
			mulexpon = a->expon + b->expon;	//다항식1과 2의 차수를 더한 값을 mulexpon에 넣는다
			insert(plist3, mulcoef, mulexpon);	//삽입 함수에 계산한 값을 넣는다
		}
	}
}

void poly_print(ListType* plist) {	//다항식 출력함수
	ListNode* p = plist->head;	//리스트의 헤드를 가리키는 노드p 생성

	printf("polynomial = ");	
	for (; p; p = p->link) {	//리스트의 처음부터 반복해야하기 때문에 반복문 사용
		printf("%d^%d + ", p->coef, p->expon);	//계수와 차수를 출력
	}
	printf("\n");	//출력이 끝나면 줄바꿈
}

ListNode* delete(ListType* head) {	//노드 삭제함수
	ListNode* removed;	//노드를 삭제할 포인터 선언

	if (head == NULL)	//리스트에 아무것도 들어있지 않을 경우
		return NULL;	//NULL값을 리턴
	for (int i = 0; i <= head->size; i++) {	//리스트의 길이만큼 반복해서 차례로 삭제
	removed = head->head;	//노드가 맨 앞을 가리키게한다
	head = removed->link;	//리스트가 다음을 가리키게한다
	free(removed);	//맨 앞을 가리키는 노드를 삭제(free)한다
	}
	free(head);	//리스트 삭제(ListType)
}

int main() {
	ListType* list1, * list2, * list3;	//다항식1, 다항식2, 다항식의 곱을 나타낸 다항식3을 선언

	list1 = create();	//다항식1 생성
	list2 = create();	//다항식2 생성
	list3 = create();	//다항식3 생성
	char ch[10];	//파일을 읽을 때 다항식을 나누기 위해 char배열 변수선언
	int coef1, expon1;	//차수와 계수를 나타내는 변수 두개 선언
	int count = 0;	//다항식1의 길이를 측정하는 변수 선언

	FILE* fp = fopen("data.txt", "r");	//data.txt파일을 읽기형식으로 연다
	if (fp == NULL) {	//파일이 제대로 열리지 않은 경우
		fprintf(stderr, "err");	//에러
		exit(1);
	}

	fscanf(fp, "%s", &ch);	//파일의 처음 문자열을 읽는다(poly1)
	while (!feof(fp)) {	//파일의 끝까지 반복
		fscanf(fp, "%s", &ch);	//문자열형태로 읽는다
		if (isalpha(ch[0]))	//문자에 숫자가 아닌 알파벳이 들어간 경우
			break;	//나가기
		count++;	//길이를 하나씩 증가시킨다
	}
	count /= 2;	//fscanf를 사용할 때 차수와 계수를 한번에 읽을 것이므로 전체 길이를 반으로 나눠준다

	rewind(fp);	//파일 포인터를 맨 앞으로 보내준다

	fscanf(fp, "%s", &ch);	//파일의 처음 문자열을 읽는다(poly1)
	for (int i = 0; i < count; i++) {	//다항식1의 길이의 절반만큼 반복
		fscanf(fp, "%d %d", &coef1, &expon1);	//차수와 계수를 읽어온다
		insert(list1, coef1, expon1);	//삽입 함수에 리스트(다항식)과 차수와 계수를 넣는다
	}

	fscanf(fp, "%s", &ch);	//파일의 처음 문자열을 읽는다(poly2)
	while (!feof(fp)) {	//파일의 끝까지 반복
		fscanf(fp, "%d %d", &coef1, &expon1);	//차수와 계수를 읽어온다
		insert(list2, coef1, expon1);	//삽입 함수에 리스트(다항식)과 차수와 계수를 넣는다
	}

	poly_print(list1);	//다항식1 출력
	poly_print(list2);	//다항식2 출력

	poly_mul(list1, list2, list3);	//다항식1과 다항식2를 곱해 다항식3에 저장

	poly_print(list3);	//다항식3 출력

	delete(list1);	//다항식1 삭제
	delete(list2);	//다항식2 삭제
	delete(list3);	//다항식3 삭제

	fclose(fp);	//파일 닫기
	return 0;
}