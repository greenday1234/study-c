#include <iostream>
using namespace std;

class MyIntStack{
    int *p; //스택 메모리
    int size;   //스택 사이즈
    int top;    //스택의 탑
    public:
    MyIntStack();   //생성자
    MyIntStack(int size);   //생성자
    MyIntStack(const MyIntStack& s);    //복사생성자
    ~MyIntStack(){delete [] p;} //소멸자
    bool push(int n);   //스택 푸시
    bool pop(int &n);   //스택 팝
};

MyIntStack::MyIntStack():MyIntStack(1){}    //매개변수 없는 생성자를 매개변수 있는 생성자 1의 값으로 생성

MyIntStack::MyIntStack(int size){   //매개변수 있는 생성자의 구현
    this->size = size;  //매개변수로 받은 size를 객체 size로 초기화
    this->top = -1; //top -1로 초기화
    this->p = new int [size];   //스택메모리를 size만큼 동적할당
}

MyIntStack::MyIntStack(const MyIntStack &s){    //복사생성자 구현
    this->size = s.size;    //복사할 객체의 size를 초기화
    this->top = s.top;  //복사할 객체의 top을 초기화
    this->p = new int[s.size];  //복사할 객체의 스택 메모리 동적할당
    for(int i=0;i<s.size;i++){  //복사할 객체의 스택 메모리 데이터 전부 복사
        this->p[i] = s.p[i];
    }
}

bool MyIntStack::push(int n){   //스택 push 구현
    if(top >= size) //더이상 들어갈 공간이 없는 경우
    return false;   //false리턴
    p[++top] = n;   //top+1의 스택 위치에 n값 넣기
    return true;    //true리턴
}

bool MyIntStack::pop(int &n){   //스택 pop구현
    if(top < 0) //더이상 뺄 공간이 없는 경우
    return false;   //false 리턴
    n = p[top--];   //참조로 연결되어 있는 변수 n에 스택의 가장 위의 값을 넣고 top을 1 내린다.
    return true;    //true 리턴
}

int main(){
    MyIntStack a(10);   //사이즈 10의 객체 생성
    a.push(10); //스택에 10 넣기
    a.push(20); //스택에 20 넣기
    MyIntStack b = a;   //깊은 복사(복사생성자 사용)
    b.push(30); //스택에 30넣기

    int n;
    a.pop(n);   //pop함수에서 매갸변수가 참조로 연결되어 있기 때문에 pop의 값이 n으로 들어감
    cout << "스택 a에서 팝한 값 " << n << endl; 
    b.pop(n);
    cout << "스택 b에서 팝한 값 " << n << endl;
}