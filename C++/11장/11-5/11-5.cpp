#include <iostream>
#include <string>
using namespace std;

int main(){
     string cmd;
     cout << "getline(cin, string)로 문자열을 읽습니다." << endl;
     while(true){
        cout << "종료하려면 exit를 입력하세요 >> ";
        getline(cin, cmd);
        if(cmd == "exit"){
            cout << "프로그램을 종료합니다...";
            return 0;
        }
     }
}