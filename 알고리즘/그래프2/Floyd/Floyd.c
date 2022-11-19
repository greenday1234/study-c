#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType{
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int A[MAX_VERTICES][MAX_VERTICES];  //가장 작은 경로 값으로 업데이트 하는 배열

void printA(GraphType *g){
    int i, j;
    printf("============================\n");
    for(i = 0;i< g->n; i++){
        for(j = 0; j<g->n;j++){
            if(A[i][j] == INF)
            printf(" * ");
            else
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("============================\n");
}

void floyd(GraphType *g){
    int i, j, k;
    for(i = 0; i< g->n; i++)
    for(j = 0; j<g->n; j++)
    A[i][j] = g->weight[i][j];  //업데이트 배열 A 초기화
    printA(g);  //초기 배열 출력

    for(k = 0;k<g->n;k++){
        for(i=0;i<g->n;i++)
        for(j=0;j<g->n;j++)
        if(A[i][k] + A[k][j] < A[i][j]) //새로 찾은 경로가 원래의 경로보다 작은 경우
        A[i][j] = A[i][k] + A[k][j];    //경로 업데이트
        printA(g);  //업데이트 한 배열 출력
    }
}

int main(){
    GraphType g = { 7,
		{{0, 7, INF, INF ,3, 10, INF},
		{7, 0, 4, 10, 2, 6, INF},
		{INF, 4, 0 ,2 , INF, INF, INF},
		{INF, 10, 2, 0 ,11, 9, 4},
		{3, 2, INF, 11, 0, INF, 5},
		{10, 6, INF, 9, INF, 0 ,INF},
		{INF, INF, INF, 4, 5, INF, 0}}
	};
    floyd(&g);
    return 0;
}