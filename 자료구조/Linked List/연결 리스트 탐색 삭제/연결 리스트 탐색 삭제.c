#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
    return head;
} 

void print_list(ListNode* head) {
	ListNode* p;
	for (p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
    }
    printf("\n");
}

ListNode* search_delete(ListNode* head, int num){
    ListNode *p;
    ListNode *pre;

    pre = NULL;
    p = head;
    if(head == NULL)
    return NULL;
    while(p->link != NULL){
        if(p->data == num && pre == NULL){  //맨 앞의 경우
            pre = head;
            head = pre->link;
            free(pre);
        }
        else if(p->data == num){
            pre->link = p->link;
            pre = p;
            p = p->link;
            free(pre);
        }
        else{
        pre = p;
        p = p->link;
        }
    }
    return head;
}

int main() {
	ListNode* head = NULL;
	
	int n;
	int data;
	int num;
	printf("노드의 개수 : ");
	scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("%d번 노드 : ", i+1);
        scanf("%d", &data);
        head = insert_first(head, data);
    }
    print_list(head);

    printf("삭제할 노드 : ");
    scanf("%d", &num);
    head = search_delete(head, num);

    print_list(head);
	
	return 0;
}