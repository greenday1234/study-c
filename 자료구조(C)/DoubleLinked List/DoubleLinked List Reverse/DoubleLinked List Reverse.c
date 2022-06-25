#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode{
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}
void dinsert(DListNode* before, element data) { 
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode)); 
	newnode->data = data;
	newnode->llink = before; 
	newnode->rlink = before->rlink; 
	before->rlink->llink = newnode;
	before->rlink = newnode; 
}
void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head)return; 
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed); 
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-|%d|-> ", p->data);
	}
	printf("\n");
}

void print_redlist(DListNode* phead){
    DListNode *p;
    for(p = phead->llink; p != phead; p = p->llink){
        printf("<-|%d|-> ", p->data);
    }
    printf("\n");
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    int n;
    int data;
	init(head);
	printf("데이터의 개수를 입력하시오: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("노드 #%d의 데이터를 입력하시오: ", i+1);
        scanf("%d", &data);
        dinsert(head, data);
    }
    print_dlist(head);

    printf("데이터를 역순으로 출력\n");

        print_redlist(head);

	return 0;
}