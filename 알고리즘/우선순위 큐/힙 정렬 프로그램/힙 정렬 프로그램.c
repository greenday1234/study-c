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

void heap_sort(element a[], int n){
    int i;
    HeapType* h;
    h = create();
    init(h);    //힙 생성 후 초기화
    for(i=0; i<n;i++){
        insert_max_heap(h, a[i]);
    }
    for(i = n-1; i>=0; i--){
        a[i] = delete_max_heap(h);
    }
    free(h);
}

#define SIZE 8

int main(){
    element list[SIZE] = {23, 56, 11, 9 ,56, 99, 27, 34};
    heap_sort(list, SIZE);
    for(int i=0;i<SIZE;i++)
    printf("%d ", list[i].key);
    printf("\n");
    return 0;
}