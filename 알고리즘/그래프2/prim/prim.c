#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType{
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES]; //선택유무를 나타내는 배열
int distance[MAX_VERTICES]; //거리를 나타내는 배열

//가장 작은 간선값을 가진 정점을 반환하는 함수
int get_min_vertex(int n){
    int v, i;
    for(i = 0; i < n; i++)  //선택되지 않은 정점 뽑기(비교할 값 임의 추출)
    if(!selected[i]){
        v = i;
        break;
    }
    for(i = 0; i < n; i++)  //선택되지 않고, 가장 작은 간선의 길이를 가진 정점 뽑기
    if(!selected[i] && (distance[i] < distance[v])) //distance값을 비교하는 것은 이미 연결이 되어 있다는 의미
        v = i;
        return v;   //가장 작은 간선길이를 가진 정점 리턴
}

void prim(GraphType* g, int s){
    int i, u, v;
    for(u = 0; u < g->n; u++)   //초기화
    distance[u] = INF;
    distance[s] = 0;    //시작 정점 초기화
    for(i = 0; i < g->n; i++){
        u = get_min_vertex(g->n);
        selected[u] = TRUE;
        printf("selected ");            //출력문 시작
		for (int i = 0; i < g->n; i++) 
                {
			printf("%d ", selected[i]);
		}
		printf("\ndist ");
		for(int i=0; i<g->n; i++){
			printf("%d ", distance[i]);
		}
		printf("\n");                   //출력문 끝
        if(distance[u] == INF)  //에러
        return;
        printf("정점 %d 추가\n", u);
        for(v = 0; v < g->n; v++)
        if(g->weight[u][v] != INF)  //인접정점 즉, 현재 가리키고 있는 정점과 연결되어 있는 정점인 경우
        if(!selected[v] && g->weight[u][v] < distance[v])   //해당 정점과 연결된 정점을 찾은 경우
        distance[v] = g->weight[u][v];  //distance배열 업데이트
    }
}

int main(){
    GraphType g = {7,
    {{0, 29, INF, INF ,INF ,10, INF},
    {29, 0, 16, INF, INF, INF, 15},
    {INF, 16, 0, 12, INF, INF, INF},
    {INF, INF, 12, 0, 22, INF, 18},
    {INF, INF, INF, 22, 0, 27, 25},
    {10, INF, INF, INF, 27, 0, INF},
    {INF, 15, INF, 18, 25, INF, 0}}
    };
    prim(&g, 0);
    return 0;
}