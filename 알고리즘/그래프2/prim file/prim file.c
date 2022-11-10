#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int get_min_vertex(int n) {
	int v, i;
	for(i = 0; i<n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && distance[i] < distance[v])
			v = i;
	return v;
}

void prim(GraphType* g, int s) {
	int i, u, v;
	
	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF)
			return;
		printf("%d ", u);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
	}
}

int main() {
	int temp1, temp2, temp3, n = 0;
	GraphType g1;
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("file not found\n");
		return 0;
	}
	
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			g1.weight[i][j] = INF;
		}
	}
	while (!feof(fp)) {
		fscanf(fp, "%d %d %d", &temp1, &temp2, &temp3);
		fgetc(fp);
		g1.weight[temp1][temp2] = temp3;
		g1.weight[temp2][temp1] = temp3;
		n++;
	}
	g1.n = n;

	prim(&g1, 0);
	return 0;
}