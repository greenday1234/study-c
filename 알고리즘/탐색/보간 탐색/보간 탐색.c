#include <stdio.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

int interpol_search(int key, int n){
    int low, high, j;
    low = 0;
    high = n-1;
    while((list[high] >= key) && (key > list[low])){    //키값이 리스트안에 있을 경우
        j = ((float)(key-list[low])/(list[high]-list[low])*(high-low))+low; //중간인덱스 계산
        if(key > list[j])
        low = j+1;
        else if(key < list[j])
        high = j-1;
        else
        low = j;
    }
    if(list[low]==key)
    return low;
    else
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

    int key = interpol_search(5, n);
    if(key == -1){
        printf("찾지 못함\n");
    }
    else{
        printf("%d 인덱스에 있음\n", key);
    }

    return 0;
}