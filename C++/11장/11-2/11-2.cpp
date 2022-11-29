#include <iostream>
using namespace std;

int main(){
    char ch;
    int cnt=0;
    while(cin.get(ch)){
        if(ch == '\n')
        break;
        if(ch == ' ')
        cnt++;
    }
    cout << "공백의 개수는 " << cnt << endl;
}