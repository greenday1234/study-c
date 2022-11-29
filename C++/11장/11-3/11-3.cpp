#include <iostream>
using namespace std;

int main(){
    int ch;
    cin.ignore(100, ';');   //문자입력중 ;를 만날경우 ;포함해서 지금까지 쓴거 스트림에서 다 지우기
    while(true){
        ch = cin.get();
        if(ch == EOF)
        break;
        cout << (char)ch;
        if(ch=='\n'){ 
        cin.ignore(100, ';');   //개행문자를 포함해 스트림에서 모두 삭제한다
        }
    }
}