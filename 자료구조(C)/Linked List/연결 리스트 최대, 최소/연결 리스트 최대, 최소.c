#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

void error(char *message){
    fprintf(stderr,"%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head, int value){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode *head, ListNode *pre, element value){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode *dalete_first(ListNode *head){
    ListNode *removed;
    if(head == NULL)
    return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode *head, ListNode *pre){
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode *head){
    for(ListNode *p = head;p != NULL; p = p->link)
    printf("%d->", p->data);
    printf("NULL\n");
}

void search_list(ListNode* head){
    int max, min;
    ListNode* p = head;
    max = p->data;
    min = p->data;
    for(;p != NULL; p = p->link){
        if(max < p->data){
            max = p->data;
        }
        if(min > p->data){
            min = p->data;
        }
    }
    printf("최대값 : %d\n최소값: %d\n", max, min);
}

int main(){
    ListNode *head = NULL;

    head = insert_first(head, 1);
    head = insert_first(head,3);
    head = insert_first(head,2);
    head = insert_first(head,400);
    head = insert_first(head,10);

    print_list(head);

    search_list(head);
    return 0;
}