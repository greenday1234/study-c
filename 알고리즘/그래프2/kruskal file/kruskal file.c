#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

void set_init(int n) {
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

int set_find(int curr) {
	if (parent[curr] == -1)
		return curr;
	while (parent[curr] != -1)
		curr = parent[curr];
	return curr;
}

void set_union(int a, int b) {
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2;
}

typedef struct {
	int key;
	int u;
	int v;
}element;

typedef struct {
	element heap[MAX_VERTICES];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

int is_empty(HeapType* h) {
	if (h->heap_size == 0)
		return 1;
	else
		return 0;
}

void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (temp.key <= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void insert_heap_edge(HeapType* h, int u, int v, int weight) {
	element e;
	e.u = u;
	e.v = v;
	e.key = weight;
	insert_min_heap(h, e);
}

void insert_all_edge(HeapType* h) {
	FILE* fp;
	int temp1, temp2, temp3;

	fp = fopen("data2.txt", "r");

	if (fp == NULL) {
		printf("file not found\n");
		return;
	}

	while (!feof(fp)) {
		fscanf(fp, "%d %d %d", &temp1, &temp2, &temp3);
		insert_heap_edge(h, temp1, temp2, temp3);
	}

	fclose(fp);
}

void kruskal(int n) {
	// n개의 정점인 경우 간선은 반드시 n-1
	int edge_accepted = 0;	//MST에 추가된 간선 카운트
	HeapType h;
	element e;	//from, to, weight
	int uset, vset;
	init(&h);
	insert_all_edge(&h);
	set_init(n);	//union 배열 초기화

	// kruskal begins
	while (edge_accepted < (n - 1)) {
		e = delete_min_heap(&h);
		uset = set_find(e.u);
		vset = set_find(e.v);
		if (uset != vset) {	//cycle이 아닌 경우
			printf("(%d %d) %d\n", e.u, e.v, e.key);
			edge_accepted++;
			set_union(uset, vset);
		}
	}
}

int main() {
	int temp1, temp2, temp3;
	int max;
	FILE* fp;
	fp = fopen("data2.txt", "r");

	if (fp == NULL) {
		printf("file not fount\n");
		return 0;
	}

	max = 0;

	while (!feof(fp)) {
		fscanf(fp, "%d %d %d", &temp1, &temp2, &temp3);
		if (temp2 > max)	//가장 큰 정점값 갱신
			max = temp2;
	}

	kruskal(max + 1);
	
	fclose(fp);
	return 0;
}