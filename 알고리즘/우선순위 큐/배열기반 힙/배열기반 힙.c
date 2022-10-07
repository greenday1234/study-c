#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
	int priority;
	char data;
}element;

typedef struct HeapType{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, char c, int p) {
	int i;
	i = ++(h->heap_size);
	element tmp;
	//루트가 아니고 부모노드보다 작으면 루프 반복
	while ((i != 1) && (p < h->heap[i / 2].priority)) {
		//조건이 맞으면 부모와 자리 교환
		h->heap[i] = h->heap[i / 2];

		//한단계 위로 이동
		i = i / 2;
	}
	//삽입할 위치를 찾았기 때문에 새로운 인자값을 힙에 추가
	tmp.priority = p;
	tmp.data = c;
	h->heap[i] = tmp;
}

element delete_min_heap(HeapType* h) {
	int parent, child;
	//가장 작은 노드(즉, 부모노드 제거)
	element item;
	element temp;
	item = h->heap[1]; //가장 작은값(lowest priority)
	//제일 마지막 노드를 읽어옴
	temp = h->heap[(h->heap_size)--];
	
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		//오른쪽 서브트리와 왼쪽서브트리 값을 비교해서 어느방향으로 내려갈지 결정
		if (child < h->heap_size && h->heap[child].priority > h->heap[child + 1].priority)
			child++;
			//temp노드의 값과 (루트 후보)이 자식노드보다 더 작으면 위치 찾았음
			if (temp.priority < h->heap[child].priority)
				break;
			//한단계 아래로 이동
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
	}
	h->heap[parent] = temp;
	printf("%c\n", item.data);
	return item;
}

int main() {
	HeapType heap;
	init(&heap);
	insert_min_heap(&heap, 'A', 1);
	insert_min_heap(&heap, 'B', 2);
	insert_min_heap(&heap, 'C', 3);
	insert_min_heap(&heap, 'D', 4);
	insert_min_heap(&heap, 'C', 3);
	insert_min_heap(&heap, 'B', 2);

	delete_min_heap(&heap);
	delete_min_heap(&heap);
	delete_min_heap(&heap);
	delete_min_heap(&heap);
	delete_min_heap(&heap);
	delete_min_heap(&heap);

	return 0;
}