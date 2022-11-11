#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 100000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType* g) {
	int i, j;
	printf("---------------------------------\n");
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF)
				printf("*    ");
			else printf("%-4d ", A[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------------\n");
}

void floyd(GraphType* g) {
	int i, j, k;

	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];
	
	printf("초기 그래프 상태\n");
	printA(g);

	for (k = 0; k < g->n; k++) {
		printf("%d를 경유하는 경우 최단거리\n", k);
		for (i = 0; i < g->n; i++) {
			for (j = 0; j < g->n; j++) {
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
			}
		}
		printA(g);
	}
}

int main() {
	GraphType g;
	int temp1, temp2, temp3;
	FILE* fp = fopen("data1.txt", "r");
	if (fp == NULL) {
		printf("file not found\n");
		return 0;
	}
		//data파일안에 정점이 최대 몇개인지 먼저 카운트
	int max = 0;
	while (!feof(fp)) {
		fscanf(fp, "%d %d %d", &temp1, &temp2, &temp3);
		if (temp2 > max)
			max = temp2;
	}

	max++;
	g.n = max;
	rewind(fp);
	
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			if (i == j)
				g.weight[i][j] = 0;
			else
				g.weight[i][j] = INF;
		}
	}

	while (!feof(fp)) {
		fscanf(fp, "%d %d %d", &temp1, &temp2, &temp3);
		g.weight[temp1][temp2] = temp3;
		g.weight[temp2][temp1] = temp3;
	}
	floyd(&g);
	return 0;
}