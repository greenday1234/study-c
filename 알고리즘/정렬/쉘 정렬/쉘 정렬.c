#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8

int list[MAX_SIZE];
int n;

//삽입 정렬
void inc_insertion_sort(int list[], int first, int last, int gap){
    int i, j, key;
    for(i=first+gap;i<=last;i = i+gap){ //비교할 값의 맨 앞에서 두번쨰 값을 i로 설정
        key = list[i];  //해당 값을 key로 뽑는다
        for(j=i-gap;j>=first && key<list[j];j=j-gap)    //맨 앞부터 비교한뒤 key의 값이 앞의 값보다 작으면 앞의 값을 뒤로 미룬다
        list[j+gap] = list[j];
        list[j+gap] = key;  //맨 앞부터 비교한 뒤 key의 값이 앞의 값보다 크면 key값을 넣는다
    }
}

//쉘 정렬
void shell_sort(int list[], int n){
    int i, gap;
    for(gap = n/2;gap>0;gap = gap/2){
        if((gap%2) == 0)    //gap이 짝수인 경우 gap+1
        gap++;
        for(i=0;i<gap;i++)  //부분 리스트의 개수는 gap
        inc_insertion_sort(list, i, n-1, gap);
        for(i=0;i<n;i++)
    printf("%d ", list[i]);
    printf("\n");
    }
}

int main(){
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for(i=0;i<n;i++)
    list[i] = rand() % 100;
    printf("정렬 전 \n");
    for(i=0;i<n;i++)
    printf("%d ", list[i]);
    printf("\n\n");

    shell_sort(list, n);
    printf("정렬 후\n");
    for(i=0;i<n;i++)
    printf("%d ", list[i]);
    printf("\n");
    return 0;
}