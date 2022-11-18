#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char name[20];
	int hak;
	int rank;
}element;

void selection_sort(element list[], int n) {
	int i, j, min;
	element temp;

	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (list[j].rank < list[min].rank)
				min = j;
		}
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}

void insertion_sort(element list[], int n) {
	int i, j;
	element key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j].hak > key.hak; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

void bubble_sort(element list[], int n) {
	int i, j;
	element temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (strcmp(list[j].name, list[j + 1].name) > 0) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
	}
}

void print(element list[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%s %d %d\n", list[i].name, list[i].hak, list[i].rank);
	}
}

int main() {
	int count = 0;
	element tmp;
	element *list;
	FILE* fp = fopen("data01.txt", "r");
	if (fp == NULL) {
		printf("file not found\n");
		return 0;
	}

	while (!feof(fp)) {
		fscanf(fp, "%s %d %d", tmp.name, &tmp.hak, &tmp.rank);
		count++;
	}

	list = (element*)malloc(sizeof(element) * count);
	rewind(fp);
	count = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s %d %d", list[count].name, &list[count].hak, &list[count].rank);
		count++;
	}

	printf("<정렬전>\n");
	print(list, count);

	printf("\n\n<선택정렬-등수순>\n");
	selection_sort(list, count);
	print(list, count);

	printf("\n\n<삽입정렬-학번순>\n");
	insertion_sort(list, count);
	print(list, count);

	printf("\n\n<버블정렬-이름순>\n");
	bubble_sort(list, count);
	print(list, count);

	fclose(fp);

	return 0;
}