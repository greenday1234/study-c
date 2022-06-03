#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct QueueNode{
    element data;
    struct QueueNode *link;
}QueueNode;

typedef struct{
    QueueNode *front;
    QueueNode *rear;
}LinkedQueueType;

void init(LinkedQueueType *q){
    q->front = q->rear = NULL;
}

int isEmpty(LinkedQueueType *q){
    return q->front == NULL;
}

void enqueue(LinkedQueueType *q, element data){
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    if(temp == NULL){
    fprintf(stderr,"fail to enqueue\n");
    exit(1);
    }
    temp->data = data;
    temp->link = NULL;

    if(isEmpty(q)){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(LinkedQueueType *q){
    QueueNode *temp = q->front;
    element data;

    if(isEmpty(q)){
        fprintf(stderr,"nothing to dequeue\n");
        exit(1);
    }
    data = temp->data;
    q->front = q->front->link;

    if(q->front == NULL)    //공백상태
        q->rear = NULL;

    free(temp);
    return data;
}

void printQueue(LinkedQueueType *q){
    QueueNode *temp = q->front;
    for(;temp != NULL;temp = temp->link){
        printf("%d->", temp->data);
    }
    printf("NULL\n");
}

int main(){
    LinkedQueueType queue;

    init(&queue);

    enqueue(&queue, 1);
    printQueue(&queue);
    enqueue(&queue, 2);
    printQueue(&queue);
    enqueue(&queue, 3);
    printQueue(&queue);

    dequeue(&queue);
    printQueue(&queue);
    dequeue(&queue);
    printQueue(&queue);
    dequeue(&queue);
    printQueue(&queue);
    
    return 0;
}