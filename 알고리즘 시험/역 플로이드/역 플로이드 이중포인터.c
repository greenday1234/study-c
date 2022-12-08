#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

int k = 0;

typedef struct GraphType
{
    int n;
    int** weight;
    char** station;
} GraphType;

#define MAX_VERTICES 100
#define INF 10000

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

void init(GraphType* g, int n)
{
    g->weight = (int**)malloc(sizeof(int*) * n*2);
    for (int i = 0; i < n*2; i++) {
        g->weight[i] = (int*)malloc(sizeof(int) * n*2);
    }
    g->station = (char**)malloc(sizeof(char*) * n*2);
    for (int i = 0; i < n*2; i++) {
        g->station[i] = (char*)malloc(sizeof(char) * n*2);
    }
 
    int r, c;
    g->n = 0;
    for (r = 0; r < n*2; r++)
        for (c = 0; c < n*2; c++)
            g->weight[r][c] = INF;
}

void insert_vertex(GraphType* g, int v, int s)
{
    if (((g->n) + 1) > s)
    {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int start, int end, int w)
{
    if (start >= g->n || end >= g->n)
    {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g->weight[start][end] = w;
    g->weight[end][start] = w;
}

int main(void)
{
    GraphType* g;
    FILE* fp;

    char temp1[10];
    char temp2[10];

    int w;

    int tmp = 0;
    int check = 0;
    int i, j;

    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("파일 오픈 실패\n");
        return 0;
    }

    while (!feof(fp)) {
        fscanf(fp, "%s %s %d", temp1, temp2, &w);
        tmp++;
    }

    rewind(fp);

    g = (GraphType*)malloc(sizeof(GraphType));
    init(g, tmp);
    for (int i = 0; i < tmp; i++)
        insert_vertex(g, i, tmp);

    while (!feof(fp))
    {
        fscanf(fp, "%s %s %d", temp1, temp2, &w);
        for (i = 0; i < tmp; i++)
        {
            if (strcmp(g->station[i], temp1) == 0)
            {
                check = 1;
                break;
            }
        }

        if (check == 0)
        {
               strcpy(g->station[k], temp1);
            k++;
        }

        check = 0;

        for (i = 0; i < tmp; i++)
        {
            if (strcmp(g->station[i], temp2) == 0)
            {
                check = 1;
                break;
            }
        }

        if (check == 0)
        {
            strcpy(g->station[k], temp2);
             
            k++;
        }
        check = 0;
    }

    rewind(fp);

    while (!feof(fp))
    {
        fscanf(fp, "%s %s %d", temp1, temp2, &w);
        for (i = 0; i < tmp; i++)
        {
            if (strcmp(g->station[i], temp1) == 0)
                break;
        }
        for (j = 0; j < tmp; j++)
        {
            if (strcmp(g->station[j], temp2) == 0)
                break;
        }
        insert_edge(g, i, j, w);
    }
    floyd(g);

    free(g);
    fclose(fp);
    return 0;
}