#include <Stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    int nAr[SIZE][SIZE];
    int TransAr[SIZE][SIZE];

    int nTemp;
    char chTemp = '0';
    int nCount = 0; 
    int nRow = 0;
    FILE *fp = fopen("data.txt", "r");

    if(fp == NULL){
        printf("파일이 열리지 않습니다.");
        return 0;
    }
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            nAr[i][j] = -1;
            TransAr[i][j] = -1;
        }
    }

    while(!feof(fp)){   //행의 개수를 구한다.
        if(chTemp == '\n'){
            break;
        }
        fscanf(fp, "%d%c", &nTemp, &chTemp);
        nCount++;
    }
    rewind(fp);
    
    while(!feof(fp)){   //원본 행렬 2차원 배열에 파일 데이터 입력
        for(int i=0;i<nCount;i++){
            fscanf(fp,"%d", &nAr[nRow][i]);
        }
        nRow++;
    }
    printf("원본 행렬 출력\n");
      for(int i=0;i<nRow;i++){
        for(int j=0;j<nCount;j++){
           printf("%d \t", nAr[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<nRow;i++){    //전치행렬 변환
        for(int j=0;j<nCount;j++){
            TransAr[j][i] = nAr[i][j];
        }
    }
    printf("\n전치 행렬 출력\n");
    for(int i=0;i<nCount;i++){
        for(int j=0;j<nRow;j++){
           printf("%d \t", TransAr[i][j]);
        }
        printf("\n");
    }
    return 0;
}