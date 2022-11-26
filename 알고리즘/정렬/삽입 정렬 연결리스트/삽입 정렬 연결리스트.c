#include <stdio.h>

typedef struct list {
	struct list *link;
	int item;
} Node_List;

void insertion_sort(Node_List * n)
{
	int key;
	for (; n->link == NULL; n->link = n->link->link) 
        {
		key = n->item;
		for (; n->item < key; n->link = n->link->link)
			n->link->link->item = n->link->item;
		n->link->link->item = key;
	}
}

int main(){
    
}