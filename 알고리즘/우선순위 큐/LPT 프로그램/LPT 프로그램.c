#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int id; //기계 아이디
    int avail;  //실행시간
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

void insert_min_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size);

    while((i != 1) && (item.avail < h->heap[i/2].avail)){   //힙트리의 안에 있어야 하고, 부모노드와 비교를 반복한다
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_min_heap(HeapType* h){
    int parent, child;
    element item, temp;

    item = h->heap[1];  //데이터 빼놓기
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while(child <= h->heap_size){   //자식노드가 힙의 크기를 넘어가지 않을 때까지 반복
        if((child < h->heap_size) && h->heap[child].avail > h->heap[child+1].avail) //자식노드가 힙 사이즈 안에 들어가고, 자식노드끼리 비교
        child++;
        if(temp.avail< h->heap[child].avail)
        break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

#define JOBS 7
#define MACHINES 3

int main(){
    int jobs[JOBS] = {8,7,6,5,3,2,1};
    element m = {0, 0};
    HeapType* h;
    h = create();
    init(h);
    //머신 초기화 
    for(int i=0;i<MACHINES; i++){
        m.id = i+1;
        m.avail = 0;
        insert_min_heap(h, m);
    }

    for(int i=0;i<JOBS;i++){
        m = delete_min_heap(h);
        printf("JOB %d을 시간=%d부터 시간=%d까지 기계 %d번에 할당한다. \n", i, m.avail, m.avail+jobs[i]-1, m.id);
        m.avail += jobs[i];
        insert_min_heap(h, m);
    }
    return 0;
}