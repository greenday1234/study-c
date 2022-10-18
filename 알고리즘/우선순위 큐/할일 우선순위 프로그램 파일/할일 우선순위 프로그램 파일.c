#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_ELEMENT 200

typedef struct{
    char work[30];
    int key;
}element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
}heaptype;

heaptype *create() {
    return (heaptype*)malloc(sizeof(heaptype));
}

void init(heaptype *h) {
    h->heap_size = 0;
}

void insert_max_heap(heaptype *h, element item) {
    int i;
    i = ++(h->heap_size);
    while((i!=1) && (item.key) > h->heap[i/2].key) {
        h->heap[i] = h->heap[i/2];
        i/=2;
    }
    h->heap[i] = item;
}

element delete_max_heap(heaptype *h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while(child <= h->heap_size) {
        if((child < h->heap_size) && (h->heap[child].key < h->heap[child +1].key)) child++;
        if(temp.key >= h->heap[child].key) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main() {
    char w[30];
    int n;
    FILE* fp = fopen("data.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "file open error\n");
        exit(1);
    }

    heaptype *heap;
    heap = create();
    init(heap);

    element m;
    while(!feof(fp)){
        fgets(m.work, 30, fp);
        m.work[strlen(m.work)-1] = '\0';
        fscanf(fp, "%d", &m.key);
        fgetc(fp);
        insert_max_heap(heap, m);
    }
    m = delete_max_heap(heap);
    printf("제일 우선순위가 높은 일은 %s\n", m.work);
    m = delete_max_heap(heap);
    printf("제일 우선순위가 높은 일은 %s\n", m.work);
    m = delete_max_heap(heap);
    printf("제일 우선순위가 높은 일은 %s\n", m.work);
    m = delete_max_heap(heap);
    printf("제일 우선순위가 높은 일은 %s\n", m.work);
    fclose(fp);
    return 0;
}