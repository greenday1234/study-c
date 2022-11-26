#include <stdio.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

int seq_search(int key, int low, int high){
    int i;
    for(i=low;i<=high;i++)
    if(list[i] == key)
    return i;
    return -1; 
}

int seq_search2(int key, int low, int high){
    int i;
    list[high+1] = key; //리스트의 맨 마지막 값을 key로 둔다
    for(i=low;list[i] != key;i++);
    if(i==(high+1))return -1;
    else return i;
}

int main(){
    int i;
    n = MAX_SIZE;
    for(i=0;i<n;i++)
    list[i] = i;

    
    for(i=0;i<n;i++)
    printf("%d ", list[i]);
    printf("\n");
    int key = seq_search(11, 0, n);
    if(key == -1){
        printf("찾지 못함\n");
    }
    else{
        printf("%d 인덱스에 있음\n", key);
    }
    
    key = seq_search2(3, 0, n);
    if(key == -1){
        printf("찾지 못함\n");
    }
    else{
        printf("%d 인덱스에 있음\n", key);
    }

    return 0;
}