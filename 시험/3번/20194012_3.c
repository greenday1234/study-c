#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef int element;
typedef struct ListNode {
   element data;
   struct ListNode *link;
}ListNode;

ListNode* insert_first(ListNode *head, element value) {
   ListNode* p = (ListNode *)malloc(sizeof(ListNode));
   p->data = value;
   p->link = head;
   head = p;
   return head;
}

ListNode* insert(ListNode *head, ListNode *pre, element value) {
   ListNode* p = (ListNode *)malloc(sizeof(ListNode));

   while (pre->link != NULL)
      pre = pre->link;

   p->data = value;
   p->link = pre->link;
   pre->link = p;
   return head;
}

void print_list(ListNode *head) {
   ListNode *p = head;
   for (p = head; p->link!= NULL; p = p->link)
      printf("%d->", p->data);
   printf("%d", p->data);
}

ListNode* reverse(ListNode *head)
{
   ListNode *p, *q, *r;

   p = head;
   q = NULL;

   while (p != NULL)
   {
      r = q;
      q = p;
      p = p->link;
      q->link = r;
   }
   return q;
}
void delete(ListNode *head) {
   ListNode *p = head;
   while (p != NULL) {
      ListNode* removed = p;
      p = p->link;
      free(removed);
   }

}
void main()
{
   FILE *fp1, *fp2;
   fp1 = fopen("data03_1.txt", "r");
   
   ListNode *head1=NULL;
   
   if (fp1 == NULL) {
      printf("파일 열기 실패\n");
      return;
   }

   int n;
   while (!feof(fp1))
   {
      fscanf(fp1, "%d ", &n);
      head1=insert_first(head1, n);
   }
   head1=reverse(head1);
   print_list(head1);
   fp2 = fopen("data03_2.txt", "r");

   if (fp2 == NULL) {
      printf("파일 열기 실패\n");
      return;
   }
   ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
   while (!feof(fp2))
   {
      fscanf(fp2, "%d ", &n);
      printf("\n============%d의 위치 검색 결과============\n", n);
      int nCount = 0;
      int empty = 0;
      temp = head1;
      for (temp; temp != NULL; temp = temp->link)
      {
         nCount++;
         if (temp->data == n) {
            printf(">%d의 위치는 %d번째 입니다.\n", n, nCount);
            empty++;
         }
      }
      if (empty == 0)
         printf("입력한 숫자 %d는 리스트에 없습니다.\n",n);
   }
   fclose(fp1);
   fclose(fp2);
   delete(head1);
   return;
}