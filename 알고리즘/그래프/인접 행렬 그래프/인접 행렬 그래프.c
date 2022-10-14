#include <stdio.h>
#include <stdlib.h>
#define MAX_VRETICES 50

typedef struct GraphType{
    int n;  //정점의 개수   
    int adj_mat[MAX_VRETICES][MAX_VRETICES];    //그래프 표현 0 또는 1
}GraphType;

void init(GraphType* g){
    int r, c;
    g->n = 0;
    for(r = 0; r<MAX_VRETICES; r++)
    for(c = 0; c<MAX_VRETICES; c++)
    g->adj_mat[r][c] = 0;   //그래프 0을 초기화
}

void insert_vertex(GraphType* g, int v){
    if((g->n + 1) > MAX_VRETICES){  //정점의 개수를 1증가 시켰을 때 지정된 값을 넘으면 에러
        fprintf(stderr, "그래프 : 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int start, int end){
    if(start >= g->n || end >= g->n){   //배열이기 때문에 음수는 올 수 없으니 정점의 인덱스보다 큰 경우 에러
        fprintf(stderr, "그래프 : 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1; //무방향 그래프이기 때문에 대칭구조를 이룸. 따라서 행과 열을 바꾼 값도 1로 변환
    g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType* g){
    for(int i=0;i<g->n;i++){        //2차원 배열을 출력해야 하므로 2중포문 사용
        for(int j=0;j<g->n;j++){
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++)
    insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    print_adj_mat(g);
    free(g);
    return 0;
}