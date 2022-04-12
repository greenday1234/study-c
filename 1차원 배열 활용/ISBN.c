#include <stdio.h>
#include <stdlib.h>

int Is_ISBN(int ar[]){
    int nSum = 0;

    for(int i=0;i<13;i++){
       if(i%2 == 1)
            nSum += ar[i] *3;
        else
        nSum += ar[i];
    }
    if(nSum %10 == 0)
    return 1;
    else
    return -1;
}
int main(){
    int nISBN[13];
    int nCount = 0;
    int nResult = 0;
    FILE *fp = fopen("data.txt","r");

    if(fp == NULL){
        printf("파일 열기 안됨\n");
        return 0;
    }
    while(!feof(fp)){
        if(nCount>13){
            printf("ISBN코드는 13자리입니다.\n");
            return 0;
        }
        fscanf(fp,"%d", &nISBN[nCount]); 
        nCount++;
    }
    nResult = Is_ISBN(nISBN);
    for(int i=0;i<13;i++){
        printf("%d", nISBN[i]);
    }
    if(nResult == -1){
        printf("은 유효하지 않은 ISBN입니다.\n");
        }
        else if(nResult == 1){
            printf("은 유효한 ISBN입니다.\n");
        }
    return 0;
}