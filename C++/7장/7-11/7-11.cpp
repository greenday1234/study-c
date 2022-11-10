#include <iostream>
using namespace std;

class Stack{
    int *num;
    int size;
    public:
    Stack(){num = new int [10]; size = -1;}
    friend Stack& operator <<(Stack& s, int x);
    bool operator !();
    void operator >>(int& x);
};

Stack& operator <<(Stack& s, int x){ //클래스 멤버함수도 가능
    s.num[++s.size] = x;
    return s;
}

bool Stack::operator !(){
    if(size == -1)
    return true;
    else
    return false;
}

void Stack::operator >>(int& x){
    x = num[size--];
}

int main(){
    Stack stack;
    stack << 3 << 5 << 10;
    while(true){
        if(!stack) break;
        int x;
        stack >> x;
        cout << x << ' ';
    }
    cout << endl;
}