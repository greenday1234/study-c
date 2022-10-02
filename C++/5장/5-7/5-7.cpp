#include <iostream>
using namespace std;

class MyInStack{
    int p[10];
    int tos;
    public:
    MyInStack();
    bool push(int n);
    bool pop(int &n);
};

MyInStack::MyInStack(){
    this->tos = -1;
}
bool MyInStack::push(int n){
    if(tos >= 9)
    return false;
    p[++tos] = n;
    return true;
}
bool MyInStack::pop(int &n){
    if(tos<0)
    return false;
    n = p[tos--];
    return true;
}

int main(){
    MyInStack a;
    for(int i=0;i<11;i++){
        if(a.push(i))
        cout << i << " ";
        else
        cout << '\n' << i+1 << " 번째 stack full \n";
    }
    int n;
    for(int i=0; i<11; i++){
        if(a.pop(n))
        cout << n << " ";
        else
        cout << '\n' << i+1 << " 번째 stack empty";
    }
    cout << '\n';
}