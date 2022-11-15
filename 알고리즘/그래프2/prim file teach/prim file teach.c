#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000000

int weight[MAX_VERTICES][MAX_VERTICES];
int selected[MAX_VERTICES];
int dist[MAX_VERTICES];

//	최소 dist[n]값을 갖는 정점을 반환
int get_min_vertex(int n) {
	int v, i;
	for (i = 0; i < n; i++) {
		if (!selected[i]) {
			v = i;
			break;
		}
	}
	for (i = 0; i < n; i++) {
		if (!selected[i] && dist[i] < dist[v])
			v = i;
	}
	return v;
}

void prim(int s, int n) {
	int i, u, v;

	//	초기화
	//	dist[] selected[]
	//	dist[] 시작노드값만 0이고 나머지는 전부 INF
	//	selected[]는 전부 INF
	for (u = 0; u < n; u++) {
		dist[u] = INF;
		selected[u] = FALSE;
	}

	//	시작 정점 설정
	dist[s] = 0;
	for (i = 0; i < n; i++) {
		//	prim의 핵심 알고리즘 반복
		//	최소 정점 얻어오기
		u = get_min_vertex(n);
		//	해당 정점 선택 업데이트 selected[] 업데이트
		selected[u] = TRUE;
		if (dist[u] == INF)
			return;
		printf("%d ", u);
		for (v = 0; v < n; v++) {
			if (weight[u][v] != INF)
				if (!selected[v] && weight[u][v] < dist[v])
					dist[v] = weight[u][v];
		}

	}
}


int main() {
	FILE* fp = fopen("data3.txt", "r");
	int max;	//maximum vertex
	int temp1, temp2, temp3;
	int i, j;

	if (fp == NULL) {
		printf("file not found\n");
		return 0;
	}

	//data파일안에 정점이 최대 몇개인지 먼저 카운트
	max = 0;
	while (!feof(fp)) {
		fscanf(fp, "%d %d %d", &temp1, &temp2, &temp3);
		if (temp2 > max)
			max = temp2;
	}

	max++;
	rewind(fp);
	
	for (i = 0; i < max; i++) {
		for (j = 0; j < max; j++) {
			if (i == j)
				weight[i][j] = 0;
			else
				weight[i][j] = INF;
		}
	}

	while (!feof(fp)) {
		fscanf(fp, "%d %d %d", &temp1, &temp2, &temp3);
		weight[temp1][temp2] = temp3;
		weight[temp2][temp1] = temp3;
	}

	prim(0, max);

	fclose(fp);
	return 0;

}