#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];	//부모노드를 나타내는 배열

//부모노드 배열 초기화
void set_init(int n) {
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

//정점을 반환하는 함수
int set_find(int curr) {
	if (parent[curr] == -1)	//만약 루트노드이거나 최종노드인 경우
		return curr;	//해당 정점 반환
	while (parent[curr] != -1)	//간선이 연결되어 있는 경우
		curr = parent[curr];	//연결이 안된 정점까지 계속 들어간다
	return curr;	//최종노드 리턴
}

//두개의 정점을 합치는 함수
void set_union(int a, int b) {
	int root1 = set_find(a);	//정점 a의 루트를 찾는다
	int root2 = set_find(b);	//정점 b의 루트를 찾는다
	if (root1 != root2)	//두 루트가 같지 않으면 즉, 사이클이 아닌 경우
		parent[root1] = root2;	//정점a의 연결노드를 정점 b의 연결노드로 변경(합친다)
}

//간선을 나타내는 구조체
struct Edge {
	int start, end, weight;
};

typedef struct GraphType {
	int n;
	struct Edge edges[2 * MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

void insert_edge(GraphType* g, int start, int end, int w) {
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}

//qsort에서 사용하는 함수
int compare(const void* a, const void* b) {
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

void kruskal(GraphType* g) {
	int edge_accepted = 0;	//현재까지 선택된 간선의 수
	int uset, vset;
	struct Edge e;

	set_init(g->n);
	//1. 정렬 하고자 하는 배열, 2. 배열의 총 수, 3. 배열의 원소 하나의 크기, 4. 비교함수
	qsort(g->edges, g->n, sizeof(struct Edge), compare);	//edges배열이 오름차순으로 정렬 됨

	printf("크루스칼 최소 신장 트리 알고리즘\n");
	int i = 0;
	while (edge_accepted < (g->n - 1)) {	//현재까지 선택된 간선의 수 < 전체 간선의 수-1 반복
		e = g->edges[i];	//선택이 안된 가장 작은 값 고르기
		uset = set_find(e.start);	//시작정점
		vset = set_find(e.end);	//끝나는 정점
		if (uset != vset) {	//싸이클이 아닌 경우
			printf("간선 (%d, %d) %d 선택\n", e.start, e.end, e.weight);
			edge_accepted++;	//선택된 간선 수 +1
			set_union(uset, vset);	//두개의 정점 합치기
		}
		i++;
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);

	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);

	kruskal(g);
	free(g);
	return 0;
}