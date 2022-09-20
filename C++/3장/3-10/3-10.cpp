#include <iostream>
#include <string>

using namespace std;

class Add{
int a, b;
public:
void setValue(int x, int y);
int calculate();
};
void Add::setValue(int x, int y){
    a = x;
    b = y;
}
int Add::calculate(){
    return a+b;
}
class Sub{
int a, b;
public:
void setValue(int x, int y);
int calculate();
};
void Sub::setValue(int x, int y){
    a = x;
    b = y;
}
int Sub::calculate(){
    return a-b;
}
class Mul{
int a, b;
public:
void setValue(int x, int y);
int calculate();
};
void Mul::setValue(int x, int y){
    a = x;
    b = y;
}
int Mul::calculate(){
    return a*b;
}
class Div{
int a, b;
public:
void setValue(int x, int y);
int calculate();
};
void Div::setValue(int x, int y){
    a = x;
    b = y;
}
int Div::calculate(){
    return a/b;
}

int main(){
    int x, y;
    char op;
    Add a;
    Sub s;
    Mul m;
    Div d;
    for(int i=0;i<3;i++){
        cout << "두 정수와 연산자를 입력하세요>>";
        cin >> x >> y >> op;
        if(op == '+'){
            a.setValue(x,y);
            cout << a.calculate() << '\n';
        }
        else if (op == '-'){
            s.setValue(x,y);
            cout << s.calculate() << '\n'; 
        }
        else if(op == '*'){
            m.setValue(x,y);
            cout << m.calculate() << '\n';
        }
        else {
            d.setValue(x,y);
            cout << d.calculate() << '\n';
        }
    }
}