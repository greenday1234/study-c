#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {    //구조체 선언
    int row;    //행
    int col;    //열
    int value;  //값
}element;

typedef struct SparseMatrix {   //구조체 선언
    element data[MAX_TERMS];
    int rows;   //행의 개수
    int cols;   //열의 개수
    int terms;  //항의 개수
}SparseMatrix;
SparseMatrix matrix_transpose2(SparseMatrix a)
{
    SparseMatrix b;
    int bindex;
    b.rows = a.cols;    //행과 열을 바꾼 새로운 배열 구조체
    b.cols = a.rows;    //열과 행을 바꾼 새로운 배열 구조체
    b.terms = a.terms;  //전체 길이

    if(a.terms > 0){    //전체 길이가 0보다 크면
        bindex = 0; //현재 저장 위치를 0으로 잡는다.
        for(int c=0;c<a.cols;c++){  //열의 개수만큼 반복
            for(int i=0;i<a.terms;i++){ //항의 개수만큼 반복
                if(a.data[i].col == c){ //i번째 열의 값이 c의 값과 같아질 때
                    b.data[bindex].row = a.data[i].col; //bindex항에 i번째 열값을 넣는다.
                    b.data[bindex].col = a.data[i].row; //bindex항에 i번째 행값을 넣는다.
                    b.data[bindex].value = a.data[i].value; //bindex항에 i번째 값을 넣는다.
                    bindex++;   //bindex항을 다음으로 넘긴다.
                }
            }
        }
    }
    return b;   //값을 바꿔준 b배열 구조체를 리턴한다.
}

matrix_print(SparseMatrix a)    //출력 함수
{
    printf("=======================\n");
    for(int i=0;i<a.terms;i++){
        printf("(%d, %d, %d)\n", a.data[i].row, a.data[i].col,a.data[i].value);
    }
    printf("=======================\n");
}

int main()
{
    SparseMatrix m = {
        {{0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5}, {4,5,1}, {5,2,2}}, 6,6,7
    };
    SparseMatrix result;

    result = matrix_transpose2(m);
    matrix_print(result);
    return 0;
}