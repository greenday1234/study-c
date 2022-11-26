#include <stdio.h>
#define MAX_SIZE 10
#define INDEX_SIZE 256

typedef struct{
    int key;
    int index;
}itable;

itable index_list[INDEX_SIZE];
int list[MAX_SIZE];
int n;

int seq_search(int key, int low, int high){
    int i;
    for(i=low;i<=high;i++)
    if(list[i] == key)
    return i;
    return -1; 
}

int search_index(int key, int n){
    int i, low, high;
    if(key<list[0] || key>list[n-1])    //키값이 범위 내의 값이 아닌 경우 종료
    return-1;

    for(i=0;i<INDEX_SIZE;i++)   //인덱스 테이블 확인
    if(index_list[i].key <= key && index_list[i+1].key > key)   //키의 구간 확인
    break;

    if(i == INDEX_SIZE){    //키의 구간이 인덱스 테이블의 끝인 경우
        low = index_list[i-1].index;
        high = n;
    }
    else{   //키의 구간이 인덱스 테이블의 끝이 아닌 경우
        low = index_list[i].index;
        high = index_list[i+1].index;
    }
    return seq_search(key, low, high);  //변경된 low와 high의 값으로 순차탐색
}

int main(){
    
}