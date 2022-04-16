#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
typedef char element;	//������ ������ �ִ� �κ��� Ÿ�Լ����� �� typedef char�� ��������.(Ÿ�� ���� �� �� �κи� �����ϸ� ��)
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
		fprintf(stderr, "���� ��ȭ ����\n");
		exit(1);
	}
	else {
		s->data[++(s->top)] = item;
	}
}
element pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
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
	int n = strlen(in);	//�Է¹��� ��Ʈ�� ���̸� ����
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
			if (is_empty(&s)) {	//�ݴ� ��ȣ�� ��Ī�Ǵ� ���� ��ȣ�� ���ÿ� ����.
			printf("\n �ݴ� ��ȣ�� ����\n");
			return 0;
		}
			else {	//���ÿ� ��ȣ�� �ֱ� ������ ��Ī�Ǵ����� Ȯ���Ѵ�.
				printf("%d ", pnumber--);
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '{' && ch != '}') || (open_ch == '[' & ch != ']')) {
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) {	//¦�� ���� �ʴ� ���� ��ȣ�� ���ÿ� �����ִ�.
		printf("���� ��ȣ�� ����");
		return 0;
	}
	return 1;
}
int main()
{
	char line[SIZE];	//����� �Է� ��Ʈ��(())))��� ����
	printf("���� : ");
	gets_s(line, SIZE);	//������ ��ä�� �б�
	printf("��ȣ �� : ");
	check_matching(line);
	return 0;
	
}