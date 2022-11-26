#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP (x, y, z) (t=x, x=y, y=t)
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void swap(int arr[], int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
void threeSort(int arr[], int front, int mid, int rear) {
	if (arr[front]>arr[mid]) swap(arr, front, mid);
	if (arr[mid]>arr[rear]) swap(arr, mid, rear);
	if (arr[front]>arr[mid]) swap(arr, front, mid);
}
void motQsort(int arr[], int front, int rear) {
	int i, j, pivot, mid = front + (rear - front) / 2;

	threeSort(arr, front, mid, rear);

	if (rear - front + 1>3) {
		pivot = arr[mid];
		swap(arr, mid, rear - 1);
		i = front;
		j = rear - 1;

		while (1) {
			while (arr[++i]<pivot && i<rear);
			while (arr[--j]>pivot && front<j);
			if (i >= j) break;
			swap(arr, i, j);
		}
		swap(arr, i, rear - 1);
		motQsort(arr, front, i - 1);
		motQsort(arr, i + 1, rear);
	}
}

int main(){
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for(i=0;i<n;i++)
    list[i] = rand()%100;

    motQsort(list, 0, n-1);
    for(i=0;i<n;i++)
    printf("%d ", list[i]);
    printf("\n");
    return 0;
}