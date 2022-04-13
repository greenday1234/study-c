#include <Stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;    //데이터의 자료형
element stack[MAX_STACK_SIZE];  //1차원 배열
int top = -1;   //top의 값이 없으면 -1이다.

int is_empty(){
    return (top == -1); //top의 값이 -1일때 true반환 
}

int is_full(){
    return (top == (MAX_STACK_SIZE - 1));   //top의 값이 스택의 최대 크기와 같으면 true반환
}

push(element item){ //요소(데이터의 값)을 스택에 넣는다.
    if(is_full()){  //만약 스택이 꽉찼다면(top이 스택의 최대 크기라면 true반환) 에러
        fprintf(stderr, "스택 포화 에러\n");
        exit(1);
    }
    else stack[++top] = item;   //top을 증가시키고, 요소값을 넣는다.
}

element pop(){  //요소값을 꺼내야 하기 때문에 void형이나 int형이 아닌 데이터 자료형을 반환 받아야 한다.
    if(is_empty()){ //top이 -1이면 true반환->에러
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else    
    return stack[top--];    //현재의 top에 있는 요소값을 반환하고, top을 1감소 시킨다.
}
element peek(){ //이것도 마찬가지로 요소값을 꺼내야 하기 때문에 데이터 자료형을 받아야 한다.
    if(is_empty()){ //top == -1이면 true반환 ->에러
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top]; //top의 요소값을 반환한다. **주의할 점은 값을 꺼내기만 할 뿐 top이 증가하거나 감소하지 않는다.
    }
    int main(){
        push(1);
        push(2);
        push(3);
        printf("%d\n", pop());
        printf("%d\n", pop());
        printf("%d\n", pop());
        return 0;
    }