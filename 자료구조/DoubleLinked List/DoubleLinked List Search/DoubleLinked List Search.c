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

DListNode* search(DListNode *L, element data){
    DListNode* p;
    if(L == NULL)
        return NULL;

    for(p = L->rlink; p != L; p = p->rlink){
        if(p->data == data){
            return p;
        }
    }
    return NULL;
}

int main() {
	DListNode *head = (DListNode*)malloc(sizeof(DListNode));

    init(head);

    dinsert(head, 10);
    dinsert(head, 20);
    dinsert(head, 30);
    dinsert(head, 40);
    dinsert(head, 50);

    print_dlist(head);
    
    DListNode *p = search(head, 30);
    printf("\n%d", p->data);

    
	return 0;
}