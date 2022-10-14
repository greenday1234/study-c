#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];

void init(GraphType* g){
    g->n = 0;
    for(int r = 0;r<MAX_VERTICES; r++)
    for(int c = 0; c<MAX_VERTICES; c++)
    g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v){
    if((g->n+1) > MAX_VERTICES){
        fprintf(stderr, "그래프 : 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int start, int end){
    if(start >= g->n || end >= g->n){
        fprintf(stderr, "그래프 : 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType* g, int v){  //깊이 우선 탐색 함수
    visited[v] = TRUE;  //현재 인덱스 방문 했음을 나타낸다
    printf("정점 %d -> ", v);   //현재 정점 출력
    for(int w = 0; w<g->n; w++) //정점 수 만큼 반복 (같은 정점을 두번 갈 수 없으므로)
    if(g->adj_mat[v][w] && !visited[w]) //간선이 연결된 정점이고, 방문하지 않은 정점인 경우 w에서 함수 새로 시작
    dfs_mat(g, w);
}

int main(){
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++)
    insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    printf("깊이 우선 탐색\n");
    dfs_mat(g, 0);
    printf("\n");
    free(g);
    return 0;
}