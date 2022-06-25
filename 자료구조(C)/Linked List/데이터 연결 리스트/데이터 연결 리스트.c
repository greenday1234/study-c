#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    char name[20];
    int age;
    double height;
}element;

typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

void error(char *message){
    fprintf(stderr,"%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head, element value){
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
    printf("name : %s Age : %d Heigh : %.3lf ->", p->data.name, p->data.age, p->data.height);
    printf("NULL\n");
}

int main(){
    ListNode *head = NULL;

    element data1 = {"kim", 34, 1.7};
    head = insert_first(head, data1);
    element data2 = {"park", 27, 1.2};
    head = insert_first(head, data2);
    element data3 = {"lee", 48, 1.4};
    head = insert_first(head, data3);
    element data4 = {"choi", 30, 1.3};
    head = insert_first(head, data4);

    print_list(head);
    
    return 0;
}