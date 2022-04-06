#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))    //a가 b보다 크면 a리턴 아니면 b리턴
#define MAX_DEGREE 101  //배열의 값을 101로 지정
typedef struct{
    int degree; //차수
    float coef[MAX_DEGREE]; //계수
}polynomial;
polynomial poly_add1(polynomial A, polynomial B)
{
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = A.degree;    //a의 차수
    int degree_b = B.degree;    //b의 차수
    C.degree = MAX(A.degree, B.degree); //크기 비교한 뒤 넣는 배열

    while(Apos <= A.degree && Bpos <= B.degree){
        if(degree_a > degree_b){    //a차수가 b차수보다 클 때
            C.coef[Cpos++] = A.coef[Apos++];    //c의 계수부분에 a의 계수를 넣는다.
            degree_a--; //a의 차수 감소
        }
        else if (degree_a == degree_b){ //a의 차수와 b의 차수가 같을 때
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];   //c의 계수부분에 a와 b의 계수를 더해 넣는다.
            degree_a--; degree_b--; //a와 b의 차수를 내린다.
        }
        else{
            C.coef[Cpos++] = B.coef[Bpos++];    //c의 계수 부분에 b의 계수를 넣는다.
            degree_b--; //b의 차수를 내린다.
        }
    }
    return C;   //다항식의 덧셈을 한 배열을 리턴한다
}
print_poly(polynomial p){   //출력함수
    for(int i=p.degree; i>0;i--)    //매개변수로 온 구조체부터 1씩 감소해 0보다 클때까지 반복한다.
    printf("%3.lfx^%d +", p.coef[p.degree - i], i); 
    printf("%3.lf \n", p.coef[p.degree]);
}
int main(){
    polynomial a = {5,{3,6,0,0,0,10}};
    polynomial b = {5,{3,7,0,5,0,1}};
    polynomial c;
    print_poly(a);  //a구조체 출력
    print_poly(b);  //b구조체 출력
    c = poly_add1(a,b); //
    printf("-------------------------------------------------------\n");
    print_poly(c);
    return 0;
}