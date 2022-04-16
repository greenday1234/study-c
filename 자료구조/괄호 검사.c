#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
typedef char element;	//변동의 소지가 있는 부분을 타입선언을 해 typedef char로 선언해줌.(타입 수정 시 이 부분만 수정하면 됨)
typedef struct {
	element data[SIZE];
	int top;
}StackType;

init_stack(StackType *s) {
	s->top = -1;
}
element is_empty(StackType *s) {
	if (s->top == -1) {
		return 1;
	}
	else
		return 0;
}
 element is_full(StackType *s) {
	if (s->top == SIZE - 1)
		return 1;
	else
		return 0;
}
push(StackType *s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	else {
		s->data[++(s->top)] = item;
	}
}
element pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	return (s->data[(s->top)--]);
}
element peek(StackType *s) {
	return s->data[s->top];
}
int check_matching(element * in) {
	StackType s;
	char ch, open_ch;
	int pnumber = 0;
	init_stack(&s);
	int n = strlen(in);	//입력받은 스트링 길이를 구함
	for (int i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(':
		case '{':
		case '[':
			printf("%d ", ++pnumber);
			push(&s, ch);
			break;
		case ')':
		case '}':
		case ']':
			if (is_empty(&s)) {	//닫는 괄호와 매칭되는 여는 괄호가 스택에 없다.
			printf("\n 닫는 괄호가 남음\n");
			return 0;
		}
			else {	//스택에 괄호가 있기 때문에 매칭되는지를 확인한다.
				printf("%d ", pnumber--);
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '{' && ch != '}') || (open_ch == '[' & ch != ']')) {
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) {	//짝이 맞지 않는 여는 괄호가 스택에 남아있다.
		printf("여는 괄호가 남음");
		return 0;
	}
	return 1;
}
int main()
{
	char line[SIZE];	//사용자 입력 스트링(())))담는 스택
	printf("수식 : ");
	gets_s(line, SIZE);	//한줄을 통채로 읽기
	printf("괄호 수 : ");
	check_matching(line);
	return 0;
	
}