#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) (t=x, x=y, y=t)

int list[MAX_SIZE];
int n;

int partition(int lise[], int left, int right){
    int pivot, temp;
    int low, high;

    low = left; //왼쪽 인덱스 변수
    high = right + 1;   //오른쪽 인덱스 변수
    pivot = list[left]; //피벗 초기화
    do{
        do  //피벗의 값보다 low가 큰 경우 멈추기
            low++;
        while(list[low]<pivot);
        do  //피벗의 값보다 high가 작은 경우 멈추기
            high--;
        while(list[high]>pivot);
        if(low<high)    //low와 high의 값 교체
        SWAP(list[low], list[high], temp);
    }while(low<high);   //low와 high가 교차되면 멈추기

    SWAP(list[left], list[high], temp); //피벗의 값과 high의 위치 교체
    return high;    //high값 리턴
}

void quick_sort(int list[], int left, int right){
    if(left<right){
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}

int main(){
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for(i=0;i<n;i++)
    list[i] = rand()%100;

    quick_sort(list, 0, n-1);
    for(i=0;i<n;i++)
    printf("%d ", list[i]);
    printf("\n");
    return 0;
}