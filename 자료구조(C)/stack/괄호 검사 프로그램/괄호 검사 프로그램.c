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
    if(s->top == SIZE -1)
    return 1;
    else
    return 0;
}
push(StackType *s, int item){
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
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else
    return s->data[s->top];
}

int check_matching(const char *in){
    StackType s;
    char ch, open_ch;   //스택에 넣는 괄호(열리는 괄호), 스택에 있는 괄호와 비교하는 괄호(닫한 괄호)
    int n = strlen(in);  //문자열의 길이
    init_Stack(&s); //스택 초기화

    for(int i=0;i<n;i++){   //문자열의 길이만큼 반복
        ch = in[i]; //문자열을 char 변수에 넣음. 괄호라면 아래의 스위치문을 실행하고, 괄호가 아니면 다음 문자열로 넘어감
        switch(ch){ //char 변수의 값이 괄호라면 아래의 case문을 실행
            case '(':
            case '{':
            case '[':
            push(&s, ch);   //스택에 해당 괄호 넣기.
            break;
            case ')':
            case '}':
            case ']':
            if(is_empty(&s))    //스택이 비어있다면 오류(처음에는 닫힌 괄호가 나올 수 없음.)
            return 0;
            else{   //스택에 값이 있다면 스택의 맨 위에 있는 괄호와 현재 괄호를 비교
                open_ch = pop(&s);
                if((open_ch == '(' && ch != ')')|| (open_ch == '{' && ch != '}') || (open_ch == '[' && ch != ']')){ //괄호의 쌍 안맞는 오류
                    return 0;
                }
                break;
            }
        }
    }
    if(!is_empty(&s))   //괄호검사가 끝났는데도 스택이 비어있지 않으면 오류
    return 0;
    
    return 1;   //정상적으로 반복이 끝났다면 성공
    }
int main(){
    char *p = "{ A[(i+1)] = 0;}";
    if(check_matching(p) == 1)
    printf("%s 괄호검사성공\n", p);
    else
    printf("%s 괄호검사실패\n", p);
    return 0;
}