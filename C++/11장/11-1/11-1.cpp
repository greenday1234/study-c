#include <iostream>
using namespace std;

int main(){
    int ch;
    int cnt=0;
    while((ch=cin.get()) != EOF){
        if(ch == '\n')
        break;
        if(ch == 'a')
        cnt++;
    }
    cout << "a의 개수는 " << cnt << endl;
}