#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int key;
}element;
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType *h){
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size);

    while((i != 1) && (item.key > h->heap[i/2].key)){   //힙트리의 안에 있어야 하고, 부모노드와 비교를 반복한다
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;

    item = h->heap[1];  //데이터 빼놓기
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while(child <= h->heap_size){   //자식노드가 힙의 크기를 넘어가지 않을 때까지 반복
        if((child < h->heap_size) && h->heap[child].key < h->heap[child+1].key) //자식노드가 힙 사이즈 안에 들어가고, 자식노드끼리 비교
        child++;
        if(temp.key >= h->heap[child].key)
        break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(){
    element e1 = {10}, e2 = {5}, e3 = {30};
    element e4, e5, e6;
    HeapType* heap;

    heap = create();
    init(heap);

    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);

    e4 = delete_max_heap(heap);
    printf("< %d > ", e4.key);
    e5 = delete_max_heap(heap);
    printf("< %d > ", e5.key);
    e6 = delete_max_heap(heap);
    printf("< %d > ", e6.key);

    free(heap);
    return 0;
}