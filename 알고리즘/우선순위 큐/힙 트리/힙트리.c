#include <stdio.h>

typedef struct {
	int key;
	char animal[100];
}element;

typedef struct {
	element heap[100];
	int heap_size;
}HeapType;

void insert_max_heap(HeapType* h, element item) {
	int i;
	h->heap_size++;
	i = h->heap_size;

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}

void display(HeapType* h) {
	int i;
	for (i = 1; i <= h->heap_size; i++) {
		printf("%d : %s > ", h->heap[i].key, h->heap[i].animal);
	}
}

int main() {
	element tmp;
	HeapType heap;
	heap.heap_size = 0;
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("file error\n");
		return 0;
	}
	while (!feof(fp)) {
		fscanf(fp, "%d %s", &tmp.key, &tmp.animal);
		printf(">>%d %s\n", tmp.key, tmp.animal);
		insert_max_heap(&heap, tmp);
			display(&heap);
			printf("\n");
	}
	fclose(fp);
}