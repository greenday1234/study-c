#include <stdio.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

//순환
int search_binary(int key, int low, int high){
    int middle;
    if(low <= high){
        middle = (low + high)/2;    //중간값
        if(key == list[middle]) //키가 중간값이면 해당 인덱스 리턴
        return middle;
        else if(key < list[middle]) //키가 중간값보다 작으면 왼쪽 탐색
        return search_binary(key, low, middle-1);
        else    //키가 중간값보다 크면 오른쪽 탐색
        return search_binary(key, middle+1, high);
    }
    return -1;  //탐색 실패 시 -1리턴
}

//반복
int search_binary2(int key, int low, int high){
    int middle;
    while(low <= high){
        middle = (low+high)/2;
        if(key == list[middle])
        return middle;
        else if(key > list[middle])
        low = middle + 1;
        else
        high = middle-1;
    }
    return -1;
}

int main(){
    int i;
    n = MAX_SIZE;
    for(i=0;i<n;i++)
    list[i] = i;

    for(i=0;i<n;i++)
    printf("%d ", list[i]);
    printf("\n");

    int key = search_binary(5, 0, n);
    if(key == -1){
        printf("찾지 못함\n");
    }
    else{
        printf("%d 인덱스에 있음\n", key);
    }

    key = search_binary2(6, 0, n);
    if(key == -1){
        printf("찾지 못함\n");
    }
    else{
        printf("%d 인덱스에 있음\n", key);
    }

    return 0;
}