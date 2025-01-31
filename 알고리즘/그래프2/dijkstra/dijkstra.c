#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int distance[MAX_VERTICES];	//최단 경로를 나타내는 배열
int found[MAX_VERTICES];	//방문한 정점 배열

//가장 작은 경로를 가진 정점 찾는 함수
int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {	//방문집합에 포함되지 않은 정점이고, distance가 min보다 작은 값인 경우
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;	//가장 작은 정점 리턴
}

void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf(" found: ");
	for (int i = 0; i < g->n; i++) {
		printf("%2d ", found[i]);
	}
	printf("\n\n");
}

void shortest_path(GraphType* g, int start) {
	int i, u, w;
	for (i = 0; i < g->n; i++) {
		distance[i] = g->weight[start][i];	//시작정점과 연결된 정점들 distance배열 업데이트(초기화)
		found[i] = FALSE;
	}
	found[start] = TRUE;	//시작 정점 방문으로 업데이트
	distance[start] = 0;	//시작 정점 distance 0으로 업데이트
	for (i = 0; i < g->n - 1; i++) {	//n-1까지인 이유는 시작 정점을 제외하기 떄문임
		print_status(g);	//현재 distance와 found배열 출력
		u = choose(distance, g->n, found);	//distance의 값이 가장 작은 경로 찾기
		found[u] = TRUE;	//가장 distance값이 작은 경로를 집합에 삽입
		for (w = 0; w < g->n; w++)
			if (!found[w])	//방문하지 않은 경우
				if (distance[u] + g->weight[u][w] < distance[w])	//원래의 distance값보다 새로 찾은 distance값이 작은 경우
					distance[w] = distance[u] + g->weight[u][w];	//해당 정점 distance값 업데이트
	}
}

int main() {
	GraphType g = { 7,
		{{0, 7, INF, INF ,3, 10, INF},
		{7, 0, 4, 10, 2, 6, INF},
		{INF, 4, 0 ,2 , INF, INF, INF},
		{INF, 10, 2, 0 ,11, 9, 4},
		{3, 2, INF, 11, 0, INF, 5},
		{10, 6, INF, 9, INF, 0 ,INF},
		{INF, INF, INF, 4, 5, INF, 0}}
	};
	shortest_path(&g, 0);
	return 0;
}