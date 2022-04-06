#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
typedef struct {    //구조체 선언
    float coef; //계수
    int expon;  //차수

}polynomial;    //구조체 이름 선언
polynomial terms[MAX_TERMS] = {{8,3},{7,1},{1,0},{10,3},{3,2},{1,0}};   //배열 선언
int avail = 6;  //빈 배열 자리

char compare(int a, int b){ //a와 b의 크기를 비교하는 함수
    if (a>b) return '>';
    else if (a == b) return '=';
    else return '<';
}

attach(float coef, int expon){  //새로운 항을 다항식에 추가하는 함수
    if (avail>MAX_TERMS){   //빈칸의 수가 배열의 최대수를 넘었을 때
        fprintf(stderr, "항의 개수가 너무 많음\n"); //오류발생
        exit(1);
    }
    terms[avail].coef = coef;   //계수를 놓는 빈칸에 계수를 넣는다.
    terms[avail].expon = expon; //차수를 놓는 빈칸에 차수를 넣는다,
    avail++;    //빈칸을 다음 칸으로 옮긴다.
}
poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce){    //다항식의 덧셈 함수
    float tempcoef;
    *Cs = avail;    //빈칸을 포인터로 선언
    while(As <= Ae && Bs <= Be) //a항과 b항의 범위 내에서 반복문을 실행한다.
    switch (compare(terms[As].expon, terms[Bs].expon)){ //a의 첫번째 차수와 b의 첫번쨰 차수를 비교한다.
        case '>':   
        attach(terms[As].coef, terms[As].expon);    //a항의 차수와 계수를 빈칸에 옮긴다.
        As++;   //첫 번째 항에서 다음 항으로 옮긴다.
        case '=':
        tempcoef = terms[As].coef + terms[Bs].coef; //a항과 b항의 계수를 더한다.
        if(tempcoef)
        attach(tempcoef, terms[As].expon);  //더한 값을 빈칸에 넣고, 차수도 넣어준다.
        As++;Bs++;break;    //a항과 b항을 다음으로 넘긴다.
        case '<':
        attach(terms[Bs].coef, terms[Bs].expon);    //b항을 빈칸에 넣는다.
        Bs++; break;    //b항을 증가시킨다.
    }
    for(;As<=Ae;As++)   //a의 첫째 항 부터 증가시켜 마지막 항까지 반복한다.
    attach(terms[As].coef, terms[As].expon);    //a항을 빈칸에 넣어준다.
    for(;Bs<=Be;Bs++)   //b의 첫째항부터 증가시켜 마지막 항까지 반복한다.
    attach(terms[Bs].coef, terms[Bs].expon);    //b항을 빈칼에 넣어준다.
    *Ce = avail - 1;    //c의 마지막 항을 빈칸-1로 잡아준다.(배열이기 때문)
}
print_poly(int s, int e){   //출력 함수
    for(int i=s;i<e;i++)    //첫 항부터 마지막 항까지 반복
    printf("%3.lfx^%d +", terms[i].coef, terms[i].expon);   //계수와 차수 출력
    printf("%3.lfx^%d\n", terms[e].coef, terms[e].expon);   //줄넘기기며 마지막 항 출력
}
int main(){
    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs,Ce;
    poly_add2(As,Ae,Bs,Be,&Cs,&Ce);
    print_poly(As,Ae);
    print_poly(Bs,Be);
    printf("----------------------------------------------\n");
    print_poly(Cs,Ce);
    return 0;
    }