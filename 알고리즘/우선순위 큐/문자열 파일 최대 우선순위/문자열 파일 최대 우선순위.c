#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_ELEMENT 200

typedef struct{
    char work[30];
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
    while((i!=1) && strcmp(item.work, h->heap[i/2].work) > 0) {
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
        if((child < h->heap_size) && (strcmp(h->heap[child].work, h->heap[child +1].work) < 0)) child++;
        if(strcmp(temp.work , h->heap[child].work) >= 0) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main() {
    char ch;
    char str[30];
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
        fscanf(fp, "%c", &ch);
        fgetc(fp);
        if(ch == 'i'){
            fscanf(fp, "%s", str);
            fgetc(fp);
            strcpy(m.work, str);
            insert_max_heap(heap, m);
        }
        if(ch == 'o'){
            m = delete_max_heap(heap);
            printf("%s \n", m.work);
        }
    }
    fclose(fp);
    return 0;
}