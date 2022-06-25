#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode{
    element data;
    struct StackNode *link;
}StackNode;

//beginning of stack method
typedef struct LinkedStackType{
    StackNode *top;
}LinkedStackType;

void initialize(LinkedStackType *s){
    s->top = NULL;
}
int isEmpty(LinkedStackType *s){
    return (s->top == NULL);
}

void push(LinkedStackType *s, element data){
    StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
    if(temp == NULL){
        fprintf(stderr,"fail to push of stack\n");
    }
    else{
        temp->data = data;
        temp->link = s->top;
        s->top = temp;
    }
}

element pop(LinkedStackType *s){
    if(isEmpty(s)){
        fprintf(stderr,"stack empty");
        exit(0);
    }
    else{
        StackNode *temp = s->top;
        int item = temp->data;
        s->top = s->top->link;
        free(temp);
        return item;
    }
}

void printStack(LinkedStackType *s){
    StackNode *temp = s->top;

    for(;temp != NULL; temp = temp->link){
        printf("|   (%3d)   |\n", temp->data);
    }
    printf("-------------\n\n");
}
//원래 없는 함수
void clear(LinkedStackType *s){
    StackNode *temp = s->top;
    StackNode *removed;

    while(temp){
        removed = temp;
        temp = temp->link;
        free(removed);
    }
    s->top = temp;
}
//end of stack method

int main(){
    LinkedStackType s1;
    initialize(&s1);

    push(&s1, 15);
    push(&s1, 62);
    push(&s1, 35);
    push(&s1, 52);
    push(&s1, 37);
    push(&s1, 55);

    printf("--출력--\n");
    printStack(&s1);

    printf("--클리어--\n");
    clear(&s1);
    printStack(&s1);

    return 0;
}