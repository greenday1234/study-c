#include <iostream>
using namespace std;

class Stack{
    int *num;
    int size;
    public:
    Stack(){num = new int [10]; size = -1;}
    Stack& operator <<(int x);
    bool operator !();
    void operator >>(int& x);
};

Stack& Stack::operator <<(int x){
    num[++size] = x;
    return *this;
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