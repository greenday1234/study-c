#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAX_HEAP 100

typedef struct {
   int num;
   char name[10];
   int math;
   int eng;
   int lan;
   int tot;
   double ave;
}element;

typedef struct{
   element heap[MAX_HEAP];
   int heap_size;
}HeapType;

HeapType *create()
{
   return (HeapType *)malloc(sizeof(HeapType));
}

void init(HeapType *h)
{
   h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element item)
{
   int i;
   i = ++(h->heap_size);
   while ((i != 1) && (item.tot > h->heap[i / 2].tot)) {
      h->heap[i] = h->heap[i / 2];
      i /= 2;
   }
   h->heap[i] = item;
}

element delete_max_heap(HeapType *h)
{
   element item, temp;
   int parent = 1, child = 2;

   item = h->heap[1];
   temp = h->heap[(h->heap_size)--];

   while (child <= h->heap_size) {
      if ((child < h->heap_size) && (h->heap[child].tot < h->heap[child + 1].tot))
         child++;
      if (temp.tot >= h->heap[child].tot) break;
      h->heap[parent] = h->heap[child];
      parent = child;
      child *= 2;
   }
   h->heap[parent] = temp;
   return item;
}

void heap_sort(element a[], int n)
{
   int i;
   HeapType *h;

   h = create();
   init(h);

   for (i = 0; i < n; i++)
      insert_max_heap(h, a[i]);

   for (i = (n - 1); i >= 0; i--)
      a[i] = delete_max_heap(h);
   free(h);
}

int main()
{
   FILE *fp;
   element temp[MAX_HEAP];
   element tmp;
   HeapType *root = NULL;
   int count = 0;
   int i = 0;

   fp = fopen("data.txt", "r");
   if (fp == NULL) {
      printf("파일 오픈 실패\n");
      exit(1);
   }

   while (!feof(fp)) {
      fscanf(fp, "%d %s %d %d %d", &tmp.num, tmp.name, &tmp.math, &tmp.eng, &tmp.lan);
      count++;
   }
   rewind(fp);

   while (!feof(fp)) {
      for (i = 0; i < count; i++) {
         fscanf(fp, "%d %s %d %d %d", &temp[i].num, temp[i].name, &temp[i].math, &temp[i].eng, &temp[i].lan);
         temp[i].tot = temp[i].math + temp[i].eng + temp[i].lan;
         temp[i].ave = (double)temp[i].tot / 3;
      }
   }
   
   printf("정렬 전\n");
   printf("| 학    번 |  이름  | 수학 | 영어 | 국어 | 총점 | 평 균 |\n");
   printf("--------------------------------------------------------\n");
         
   for (i = 0; i < count; i++)
      printf("| %d | %s | %4d | %4d | %4d | %4d | %.2lf |\n", temp[i].num, temp[i].name, temp[i].math, temp[i].eng, temp[i].lan, temp[i].tot, temp[i].ave);

   heap_sort(temp, count);
   
   printf("\n\n정렬 후 데이터\n");
   printf("| 학    번 |  이름  | 수학 | 영어 | 국어 | 총점 | 평 균 |\n");
   printf("--------------------------------------------------------\n");
   for (i = 0; i < count; i++)
      printf("| %d | %s | %4d | %4d | %4d | %4d | %.2lf |\n", temp[i].num, temp[i].name, temp[i].math, temp[i].eng, temp[i].lan, temp[i].tot, temp[i].ave);
   return 0;
}