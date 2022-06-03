#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

void print_list(ListNode *head){
    ListNode *p;

    if(head == NULL)
    return;

    p = head->link;
    do{
        printf("%d-> ", p->data);
        p = p->link;
    }while(p != head);
    printf("%d \n", p->data);   //마지막 노드 출력
}

ListNode* insert_first(ListNode* head, element data){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;

    if(head == NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode *head, element data){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if(head == NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

int get_length(ListNode* head){
    ListNode *p;
    int count = 1;

    if(head->link == head){
        return count;
    }
    for(p = head->link; p != head; p = p->link)
    count++;
    return count;
}

ListNode *search(ListNode *head, element data){
    ListNode *p;

    if(head == NULL)
    return NULL;

    p = head->link; //head가 리스트의 끝에 있기 때문에 head->link를 해준다
    do{
        if(p->data == data){
            return p;
        }
        p = p->link;
    }while(p != head);

    return NULL;
}

int main(){
    ListNode *head = NULL;

    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);

    printf("%d",get_length(head));  //길이
    ListNode *p = search(head, 10);
    printf("\n%d", p->data);

    return 0;
}