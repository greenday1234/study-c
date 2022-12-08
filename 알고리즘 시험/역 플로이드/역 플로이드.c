#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 10000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
    char station[12][10];
}GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType* g) {
	int i, j;
    printf("====================================================================================================\n");
    for(i=0;i<g->n;i++){
        printf("\t%2s ", g->station[i]);
    }
    printf("\n====================================================================================================\n");
	for (i = 0; i < g->n; i++) {
        printf("%s :: ", g->station[i]);
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF)
				printf("*       ");
			else printf("%-7d ", A[i][j]);
		}
		printf("\n");
	}
    printf("====================================================================================================\n");
}

void floyd(GraphType* g) {
	int i, j, k;

	for (i = 0; i < g->n; i++){
		for (j = 0; j < g->n; j++){
            if(i == j)
            A[i][j] = 0;
            else
			A[i][j] = g->weight[i][j];
        }
    }

	printA(g);

	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++) {
			for (j = 0; j < g->n; j++) {
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
			}
        }
	}
    printA(g);
}

void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->weight[r][c] = INF;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end, int weight)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->weight[start][end] = weight;
    g->weight[end][start] = weight;
}

int main(void)
{
	GraphType g;
	FILE *fp;

	char temp1[10];
	char temp2[10];

    int weightcount;
	int tmp = 0;
	int check = 0;
	int i, j;

	fp = fopen("data.txt", "r");

	if (fp == NULL) 
	{
		printf("파일 오픈 실패\n");
		return 0;
	}
	
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %d", temp1, temp2, &weightcount);
		for (i = 0; i < 12; i++)
		{
			if (strcmp(g.station[i], temp1) == 0)
			{
				check = 1;
				break;
			}
		}
		if (check == 0)
		{
			strcpy(g.station[tmp++], temp1);
		}
		check = 0;
        for(i=0;i<12;i++)
        {
            if(strcmp(g.station[i], temp2) == 0)
            {
                check = 1;
                break;
            }
        }
        if(check == 0)
        {
            strcpy(g.station[tmp++], temp2);
        }
        check = 0;
	}

	rewind(fp);

	init(&g);
	for (int i = 0; i < tmp; i++)
		insert_vertex(&g, i);

	while (!feof(fp))
	{
		fscanf(fp, "%s %s %d", temp1, temp2, &weightcount);
		for (i = 0; i < tmp; i++)
		{
			if (strcmp(g.station[i], temp1) == 0)
				break;
		}
		for (j = 0; j < tmp; j++)
		{
			if (strcmp(g.station[j], temp2) == 0)
				break;
		}
		insert_edge(&g, i, j, weightcount);
	}
	
	floyd(&g);
	fclose(fp);
	return 0;
}