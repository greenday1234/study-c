#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

//삽입 정렬
void insertion_sort(int list[], int n){
    int i, j, key;
    for(i=1;i<n;i++){
        key = list[i];  //비교할 인덱스값을 변수로 빼놓기
        for(j=i-1;j>=0 && list[j]>key; j--) //i는 1부터 시작하므로 j=i-1부터 시작한다.
        list[j+1] = list[j];    //배열 인덱스 값이 key의 값보다 크면 배열의 값을 한칸 뒤로 이동시킨다(레코드의 오른쪽 이동)
        list[j+1] = key;    //배열 인덱스 값이 key의 값보다 작으면 해당 인덱스+1의 위치에 key값을 넣는다
    }
}

int main(){
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for(i=0;i<n;i++)
    list[i] = rand() % 100;

    insertion_sort(list, n);
    for(i=0;i<n;i++)
    printf("%d ", list[i]);
    printf("\n");
    return 0;
}