#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
	char name[20];
	int hak;
	char phone_num[30];
}element;

void inc_insertion_sort(element list[], int first, int last, int gap) {
	int i, j;
	element key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key.hak < list[j].hak; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void shell_sort(element list[], int n) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0)
			gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}
}

void print(element list[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%s %d %s\n", list[i].name, list[i].hak, list[i].phone_num);
	}
}

int main() {
	int count = 0;
	element *list;
    element temp;
    FILE *fp = fopen("data03.txt", "r");
    if(fp == NULL){
        printf("file not found\n");
        return 0;
    }

    while(!feof(fp)){
        fscanf(fp, "%s %d %s", temp.name, &temp.hak, temp.phone_num);
        count++;
    }

    rewind(fp);
    list = (element *)malloc(sizeof(element)*count);
    count = 0;

    while(!feof(fp)){
        fscanf(fp, "%s %d %s", list[count].name, &list[count].hak, list[count].phone_num);
        count++;
    }
    
    printf("<쉘정렬-학번순>\n");
	shell_sort(list, count);
    print(list, count);

    fclose(fp);
	return 0;
}