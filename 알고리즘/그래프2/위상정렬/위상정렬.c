#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType{
    int n;
    GraphNode *adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType *g){
    int v;
    g->n = 0;
    for(v = 0; v < MAX_VERTICES; v++)
    g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v){
    if(((g->n) + 1) > MAX_VERTICES){
        fprintf(stderr, "graph : over vertex");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v){
    GraphNode *node;
    if(u >= g->n || v >= g->n){
        fprintf(stderr, "graph : error vertex number");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct{
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;

void init(StackType* s){
    s->top = -1;
}

int is_empty(StackType* s){
    return (s->top == -1);
}

int is_full(StackType* s){
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "over stack");
        exit(1);
    }
    else
    s->stack[++(s->top)] = item;
}

element pop(StackType* s){
    if(is_empty(s)){
        fprintf(stderr, "empty stack");
        exit(1);
    }
    else
    return s->stack[(s->top)--];
}

int topo_sort(GraphType *g){
    int i;
    StackType s;
    GraphNode *node;

    int *in_degree = (int*)malloc(sizeof(int) * g->n);  //각 정점의 진입차수를 저장하는 배열
    for(i = 0; i < g->n; i++)   //in_degree 배열 초기화
    in_degree[i] = 0;

    for(i = 0; i < g->n; i++){
        node = g->adj_list[i];  //정점 i에서 나오는 간선들 찾기
        while(node != NULL){
            in_degree[node->vertex]++;  //해당 정점을 가리키는 값을 1증가 시킨다
            node = node->link;  //다음 노드를 가르킨다
        }
    }

    init(&s);
    for(i = 0; i < g->n; i++){
        if(in_degree[i] == 0)   //진입 차수가 0인 정점을 스택에 넣는다
        push(&s, i);
    }

    while(!is_empty(&s)){   //위상 순서를 생성
        int w;  
        w = pop(&s);
        printf("정점 %d ->", w);
        node = g->adj_list[w];
        while(node != NULL){    //각 정점의 진입 차수 변경
            int u = node->vertex;   //정점 추출
            in_degree[u]--; //해당 정점 진입 차수 감수
            if(in_degree[u] == 0)   //진입 차수가 0으로 변경된 경우 스택에 삽입
            push(&s, u);
            node = node->link;  //다음 노드로 이동
        }
    }
    free(in_degree);
    printf("\n");
    return (i == g->n); //반환값이 1이면 성공, 0이면 실패
}

int main(){
    GraphType g;

    graph_init(&g);
    insert_vertex(&g, 0);
    insert_vertex(&g, 1);
    insert_vertex(&g, 2);
    insert_vertex(&g, 3);
    insert_vertex(&g, 4);
    insert_vertex(&g, 5);
    
    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 3);
    insert_edge(&g, 1, 3);
    insert_edge(&g, 1, 4);
    insert_edge(&g, 2, 3);
    insert_edge(&g, 2, 5);
    insert_edge(&g, 3, 5);
    insert_edge(&g, 4, 5);

    topo_sort(&g);

    return 0;
}