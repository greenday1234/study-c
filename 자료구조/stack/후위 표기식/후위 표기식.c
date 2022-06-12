#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
typedef char element;	//변동의 소지가 있는 부분을 타입선언을 해 typedef char로 선언해줌.(타입 수정 시 이 부분만 수정하면 됨)
typedef struct {
	element data[SIZE];
	int top;
}StackType;

void init_stack(StackType *s) {
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
void push(StackType *s, element item) {
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

int prec(char op){  //연산자 우선순위 반환
    switch(op){
        case '(':
        case ')':
        return 0;
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[]){  //중위 표기식 -> 후위 표기식
    int i=0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);
    for(i=0;i<len;i++){
        ch = exp[i];
        switch(ch){
            case '+':   //연산자인 경우
            case '-':
            case '*':
            case '/':
            while(!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {   //스택에 있는 연산자 우선순위가 더 크거나 같으면 출력
            printf("%c", pop(&s));  //계속 비교해서 스택에 쌓인 연산자 비교
            }
            push(&s, ch);      //연산자 우선순위가 낮으면 push
            break;
            case '(':   //왼쪽 괄호는 무조건 push
            push(&s, ch);
            break;
            case ')':
            top_op = pop(&s);
            while(top_op != '('){   //열린 괄호가 나올 떄 까지 출력 pop 반복
                printf("%c", top_op);
                top_op = pop(&s);
            }
            break;
            default:    //피연산자
            printf("%c", ch);
            break;
        }
    }
    while(!is_empty(&s))    //스택에 저장된 연산자들 출력
    printf("%c", pop(&s));
}

int main(){
    char *s = "5*(1+2)/2";
    printf("중위 표기식 %s \n", s);
    printf("후위 표기식 ");
    infix_to_postfix(s);
    printf("\n");
    return 0;
}