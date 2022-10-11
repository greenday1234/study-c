#include <iostream>
using namespace std;

class Dept{
    int size;   //배열의 크기
    int *scores;    //배열 메모리
    public: 
    Dept(int size){ //생성자
        this->size = size;  //size 초기화
        scores = new int[size]; //배열을 size만큼 동적할당
    }
    ~Dept(){delete [] scores;}  //소멸자 구현
    int getSize(){return size;} //객체의 size리턴
    void read();    //점수 입력받는 함수 선언
    bool isOver60(int index);   //점수가 60점이 넘는지 확인하는 함수 선언
};

void Dept::read(){  //점수 입력받는 함수 구현
    cout << size << "개의 점수 입력 >> "; 
    for(int i=0;i<size;i++){    //전체 배열의 크기만큼 점수 입력 반복
        cin >> scores[i];
    }
}

bool Dept::isOver60(int index){ //점수가 60점이 넘는지 확인하는 함수 구현
    if(scores[index] > 60)  //배열의 값이 60보다 큰 경우 true리턴
    return true;
    else    //아니면 false리턴
    return false;
}

int countPass(Dept &dept){  //인원수 세는 함수 구현 (객체 참조자를 사용해 객체 값을 복사하지 않고 원본값 사용)
    int count = 0;  //개수를 셀 변수를 0으로 초기화
    for(int i=0;i<dept.getSize();i++){  //배열의 크기만큼 반복
        if(dept.isOver60(i))    //isOver60 함수의 리턴값이 true면 count를 1 증가
        count++;
    }
    return count;   //count리턴
}

int main(){
    Dept com(10);   //배열의 크기가 10인 객체 com 생성
    com.read(); // 점수 입력받기
    int n = countPass(com); //60점 이상인 학생 수를 변수에 담기
    cout << "60점 이상은 " << n << "명";   
}