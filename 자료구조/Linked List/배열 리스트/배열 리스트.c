#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct{
    element array[MAX_LIST_SIZE];
    int size;
}ArrayListType;

void error(char *message){
    fprintf(stderr,"%s\n", message);
    exit(1);
}

void init(ArrayListType *L){
    L->size = 0;
}

int is_empty(ArrayListType *L){
    return L->size == 0;
}

int is_full(ArrayListType *L){
    return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType *L, int pos){   //해당 pos의 data값 뽑아오기
    if(pos < 0 || pos >= L->size)   //pos가 정상 범위가 아니면 에러
    error("위치 오류");
    return L->array[pos];   //pos위치의 array값 반환
}

void print_list(ArrayListType *L){
    int i;
    for(i = 0; i<L->size;i++){
        printf("%d->", L->array[i]);
    }
    printf("\n");
}

void insert_last(ArrayListType *L, element item){
    if(L->size >= MAX_LIST_SIZE){
        error("리스트 오버플로우");
    }
    L->array[L->size++] = item;
}

void insert(ArrayListType *L, int pos, element item){
    if(!is_full(L) && (pos >= 0) && (pos <= L->size)){  //배열이 다 차지 않고, pos가 정상범위인 경우
        for(int i=(L->size-1); i>=pos;i--)  //뒤에서부터 pos위치까지 반복
        L->array[i+1] = L->array[i];        //앞의 값을 뒤로 옮긴다
    L->array[pos] = item;   //반복문이 다 돌면 남아있는 마지막 배열에 원하는 값 삽입
    L->size++;  //길이 1 증가
    }
}

element delete(ArrayListType *L, int pos){
    element item;

    if(pos < 0 || pos >= L->size)   
    error("위치 오류");
    item = L->array[pos];   //삭제할 값을 item변수에 먼저 넣는다
    for(int i=pos;i<(L->size-1);i++)    //삭제할 위치부터 뒤로 간다
    L->array[i] = L->array[i + 1];  //뒤의 값을 앞으로 땡긴다
    L->size--;  
    return item;
}  

int main(){
    ArrayListType list;

    init(&list);
    insert(&list,0,10);
    print_list(&list);
    insert(&list,0,20);
    print_list(&list);
    insert(&list,0,30);
    print_list(&list);
    insert_last(&list, 40);
    print_list(&list);
    delete(&list, 0);
    print_list(&list);
    return 0;
}