#include <stdio.h>
#include <stdlib.h>
int main(){
    int *n;
    FILE *fp = fopen("data.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "err");
        exit(1);
    }
    int x;
    int i=0;
    while(!feof(fp)){
    fscanf(fp,"%d", &x);
    i++;
    }
    n = (int*)malloc(sizeof(int)*i);
    rewind(fp);

    printf("Input Array : \n");
    for(int j=0;j<i;j++){
        if(j%10 == 0 && j != 0){
            printf("\n");
        }
        fscanf(fp,"%d", &n[j]);
        printf("%d ", n[j]);
    }
    printf("\n\n");
    int temp;
    for(int j=0;j<i;j++){
        for(int k = 0 ; k < i - 1; k++){
            if(n[k]>n[k+1]){
                temp = n[k+1];
                n[k+1] = n[k];
                n[k] = temp;
            }
        }
    }
    printf("Sorted Array : \n");
    for(int j=0; j<i;j++){
        if(j%10 == 0 && j != 0){
            printf("\n");
        }
        printf("%d ", n[j]);
    }
    return 0;
}