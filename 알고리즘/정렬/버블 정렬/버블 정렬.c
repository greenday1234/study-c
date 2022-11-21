#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) (t=x, x=y, y=t)

int list[MAX_SIZE];
int n;

//버블 정렬
void bubble_sort(int list[], int n){
    int i, j, temp;
    for(i=n-1;i>0;i--){ //맨 마지막 노드는 비교하지 않으므로 i=n-1이어야함
        for(j=0;j<i;j++)
        if(list[j] > list[j+1]) //맨 앞에서부터 두개를 비교해 앞의 값이 뒤의 값보다 큰 경우
        SWAP(list[j], list[j+1], temp); //둘의 위치를 변경한다.
    }
}

int main(){
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for(i=0;i<n;i++)
    list[i] = rand() % 100;

    bubble_sort(list, n);
    for(i=0;i<n;i++)
    printf("%d ", list[i]);
    printf("\n");
    return 0;
}