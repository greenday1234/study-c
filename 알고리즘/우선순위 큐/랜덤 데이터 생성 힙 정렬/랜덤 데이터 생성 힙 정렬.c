#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 200



typedef struct HeapType{
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, int p) {
	int i;
	i = ++(h->heap_size);
	int tmp;
	//루트가 아니고 부모노드보다 작으면 루프 반복
	while ((i != 1) && (p < h->heap[i / 2])) {
		//조건이 맞으면 부모와 자리 교환
		h->heap[i] = h->heap[i / 2];

		//한단계 위로 이동
		i = i / 2;
	}
	//삽입할 위치를 찾았기 때문에 새로운 인자값을 힙에 추가
	tmp = p;
	h->heap[i] = tmp;
}

int delete_min_heap(HeapType* h) {
	int parent, child;
	//가장 작은 노드(즉, 부모노드 제거)
	int item;
	int temp;
	item = h->heap[1]; //가장 작은값(lowest priority)
	//제일 마지막 노드를 읽어옴
	temp = h->heap[(h->heap_size)--];
	
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		//오른쪽 서브트리와 왼쪽서브트리 값을 비교해서 어느방향으로 내려갈지 결정
		if (child < h->heap_size && h->heap[child] > h->heap[child + 1])
			child++;
			//temp노드의 값과 (루트 후보)이 자식노드보다 더 작으면 위치 찾았음
			if (temp < h->heap[child])
				break;
			//한단계 아래로 이동
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_min_sort(int a[], int n) {
	HeapType h;
	init(&h);
	for (int i = 0; i < n; i++) {
		insert_min_heap(&h, a[i]);
	}
	for (int i = 0; i < n; i++) {
		a[i] = delete_min_heap(&h);
	}
}

void heap_max_sort(int a[], int n) {
	HeapType h;
	init(&h);
	for (int i = 0; i < n; i++) {
		insert_min_heap(&h, a[i]);
	}
	for (int i = n-1; i >= 0; i--) {
		a[i] = delete_min_heap(&h);
	}
}

int main() {
	srand((int)time(NULL));
	HeapType heap;
	init(&heap);
	int data[100];
	
	for (int i = 0; i < 100; i++) {
			data[i] = rand() % 100 + 1;
			for (int j = 0; j < i; j++) {
				if (data[i] == data[j]) {
					i--;
					break;
				}
			}
	}
	printf("<정렬할 데이터 초기화>\n");
	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0 && i != 0)
			printf("\n");
		printf("%d\t", data[i]);
		insert_min_heap(&heap, data[i]);
	}
	heap_min_sort(data, 100);
	printf("\n<오름차순 정렬 후 데이터>\n");
	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0 && i != 0)
			printf("\n");
		printf("%d\t", data[i]);
	}
	heap_max_sort(data, 100);
	printf("\n<내림차순 정렬 후 데이터>\n");
	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0 && i != 0)
			printf("\n");
		printf("%d\t", data[i]);
	}

	return 0;
}