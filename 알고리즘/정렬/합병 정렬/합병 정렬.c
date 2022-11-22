#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];
int sorted[MAX_SIZE];
int n;

//분할된 리스트 합병
void marge(int list[], int left, int mid, int right){
    int i, j, k, l;
    i = left; j=mid+1; k=left;  //i는 정렬된 왼쪽 리스트에 대한 인덱스, j는 정렬된 오른쪽 리스트에 대한 인덱스, k는 정렬된 리스트에 대한 인덱스

    //분할 정렬된 list의 합병
    while(i <= mid && j <= right){  //왼쪽과 오른쪽 리스트 정렬
        if(list[i] <= list[j])  //왼쪽 리스트의 값이 오른쪽 리스트의 값보다 작은 경우
        sorted[k++] = list[i++];    //sorted배열에 왼쪽리스트의 값을 넣고 다음으로 각각의 인덱스 값을 다음으로 증가시킨다
        else    //오른쪽 리스트의 값이 왼쪽 리스트의 값보다 작은 경우
        sorted[k++] = list[j++];    //sorted배열에 오른쪽리스트의 값을 넣고 다음으로 각각의 인덱스 값을 다음으로 증가시킨다
    }

    //남아있는 리스트 넣기
    if(i > mid) //오른쪽 리스트가 남아있는 경우
    for(l=j;l <= right;l++) //오른쪽에 남아있는 레코드 일괄 복사
    sorted[k++] = list[l];
    else    //왼쪽 리스트가 남아있는 경우
    for(l=i;l <= mid;l++)   //왼쪽에 남아있는 레코드 일괄 복사
    sorted[k++] = list[l];
    for(l = left;l <= right;l++)    //sorted배열의 값을 list배열에 재복사
    list[l] = sorted[l];
}

//합병 정렬
void marge_sort(int list[], int left, int right){
    int mid;
    if(left < right){   // 분할이 1까지 되도록 한다
        mid = (left + right)/2; //리스트의 균등 분할
        marge_sort(list, left, mid);    //왼쪽 리스트 분할
        marge_sort(list, mid+1, right); //오른쪽 리스트 분할
        marge(list, left, mid, right);  //합병
    }
}

int main(){
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for(i=0;i<n;i++)
    list[i] = rand() % 100;

    marge_sort(list, 0, MAX_SIZE-1);
    for(i=0;i<n;i++)
    printf("%d ", list[i]);
    printf("\n");
    return 0;
}