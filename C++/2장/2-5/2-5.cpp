#include <iostream>
#include <cstring>
using namespace std;

int main(){
    cout << "문자들을 입력하라(100개 미만).\n";
    char n[100];
    cin.getline(n, 100);
    int x=0;
    for(int i=0;i<strlen(n);i++){
        if(n[i] == 'x'){
            x++;
        }
    }
    cout << "x의 개수는 " <<  x << "\n";
}