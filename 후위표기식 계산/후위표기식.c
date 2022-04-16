#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef char element;
typedef struct {
    element data[SIZE];
    int top;
}StackType;

init_Stack(StackType *s){
    s->top = -1;
}
int is_empty(StackType *s){
    if(s->top == -1)
    return 1;
    else
    return 0;
}
int is_full(StackType *s){
    if(s->top == SIZE -1){
        return 1;
    }
    else
    return 0;
}
push(StackType *s, char item){
    if(is_full(s)){
        fprintf(stderr,"스택 포화 에러\n");
        exit(1);
    }
    else
    s->data[++(s->top)] = item;
}
element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
    return s->data[(s->top)--];
}
element peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
    return s->data[s->top];
}
int eval(char exp[]){
    int op1,op2,value,i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;

    init_Stack(&s);
    for(i=0;i<len;i++){
        ch=exp[i];
        if(ch!='+' && ch != '-' && ch != '*' && ch != '/'){ //입력이 연산자가 아닐 경우
            value = ch -'0';    //ch의 아스키코드값 - 0의 아스키코드값을 뺸다.(캐스팅)
            push(&s,value);
        }
        else{
            op2=pop(&s);
            op1=pop(&s);
            switch(ch){
                case '+':
                push(&s, op1+op2);
                break;
                case '-':
                push(&s,op1-op2);
                break;
                case '*':
                push(&s,op1*op2);
                break;
                case '/':
                push(&s,op1/op2);
                break;
            }
        }
    }
    return pop(&s);
}

int main(){
    int result;
    printf("후위 표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d\n", result);
    return 0;
}