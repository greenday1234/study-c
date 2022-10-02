#include <iostream>
using namespace std;

bool bigger(int a, int b, int &big){
    if(a == b)
    return true;
    else{
    if(a > b)
    big = a;
    else
    big = b;
    }
    return false;
}

int main(){
    int a, b;
    int big;
    cout << "정수 두개 입력 >> ";
    cin >> a >> b;
    if(bigger(a, b, big))
    cout << "값이 같습니다." << '\n';
    else
    cout << "값이 다릅니다. 큰 수는 " << big << '\n';
}