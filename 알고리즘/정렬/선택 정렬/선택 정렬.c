#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) (t=x, x=y, y=t)

int list[MAX_SIZE];
int n;

//선택 정렬
void selection_sort(int list[], int n){
    int i, j, least, temp;
    for(i=0;i<n-1;i++){
        least = i;  //정렬이 안된 배열의 맨 앞의 값
        for(j=i+1;j<n;j++)  //j=i+1인 이유는 정렬이 안된 맨 앞의 값은 비교할 이유가 없음
        if(list[j] < list[least])   //최솟값 찾기
        least = j;
        SWAP(list[i], list[least], temp);   //찾은 최소값을 정렬이 안된 배열의 맨 앞으로 변경
    }
}

int main(){
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for(i=0;i<n;i++)
    list[i] = rand() % 100;

    selection_sort(list, n);
    for(i=0;i<n;i++)
    printf("%d ", list[i]);
    printf("\n");
    return 0;
}