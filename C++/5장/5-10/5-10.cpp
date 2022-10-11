#include <iostream>
#include <string>
using namespace std;

class Buffer{
    string text;    //문자열 변수
    public:
    Buffer(string text){this->text = text;} //생성자
    void add(string next){text += next;}    //문자열 더하는 함수
    void print() {cout << text << endl;}    //문자열 출력 함수
};

Buffer& append(Buffer& buf, string text){   //문자열에 덧붙이는 함수
    buf.add(text);  //buf객체의 add함수를 사용해 문자열을 더함
    return buf; //buf 객체 리턴
}

int main(){
    Buffer buf("Hello");    //Hello텍스트를 가진 객체 생성
    Buffer &temp = append(buf, "Guys"); //buf객체의 텍스트에 Guys를 덧붙인 텍스트를 가진 객체 생성
    temp.print();   //temp객체 출력
    buf.print();    //buf객체 출력
}