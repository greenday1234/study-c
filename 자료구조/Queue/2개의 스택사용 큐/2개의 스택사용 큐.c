#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s){   //스택 초기화(배열을 0으로 초기화 할 필요가 없음)
    s->top = -1;
}
int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        exit(1);
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

void push_stack(StackType *s1, StackType *s2){
    while(s1->top != -1){
    element tmp = pop(s1->data);
    push(s2,tmp);
    }
}

int main(){
    StackType *s1;
    StackType *s2;
    s1 = (StackType *)malloc(sizeof(StackType));
    s2 = (StackType *)malloc(sizeof(StackType));

    init_stack(s1);
    init_stack(s2);

    push(s1,1);
    push(s1,2);
    push(s1,3);
    push_stack(s1,s2);
    printf("%d\n", pop(s2));
    printf("%d\n", pop(s2));
    printf("%d\n", pop(s2));
    free(s1);
    free(s2);

    return 0;
}