#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "graph : over vertex\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "graph : error vertex number\n");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "stack error\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "empty stack\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

int topo_sort(GraphType* g) {
	int i;
	StackType s;
	GraphNode* node;

	int* in_degree = (int*)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++)
		in_degree[i] = 0;
	for (i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	init(&s);
	for (i = 0; i < g->n; i++) {
		if (in_degree[i] == 0)
			push(&s, i);
	}

	while (!is_empty(&s)) {
		int w;
		w = pop(&s);
		printf("정점 %d -> ", w);
		node = g->adj_list[w];
		while (node != NULL) {
			int u = node->vertex;
			in_degree[u]--;
			if (in_degree[u] == 0)
				push(&s, u);
			node = node->link;
		}
	}
	free(in_degree);
	printf("\n");
	return (i == g->n);
}

int main() {
	char c;
	int num, temp1, temp2;
	GraphType g;
	graph_init(&g);
	FILE* fp = fopen("data02.txt", "r");
	if (fp == NULL) {
		printf("file not found\n");
		return 0;
	}
	while (!feof(fp)) {
		fscanf(fp, "%c", &c);
		if (c == 'v') {
			fscanf(fp, "%d", &num);
			insert_vertex(&g, num);
			fgetc(fp);
		}
		else if (c == 'e') {
			fscanf(fp, "%d %d", &temp1, &temp2);
			insert_edge(&g, temp1, temp2);
		}
	}
	topo_sort(&g);
	return 0;
}