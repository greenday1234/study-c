#include <iostream>
#include <string>

using namespace std;

class Integer{
    int n;
    public:
    Integer(int n);
    Integer(string n);
    int get();
    void set(int n);
    bool isEven();
};
Integer::Integer(int n){
    this->n = n;
}
Integer::Integer(string n){
    this->n = stoi(n);
}
int Integer::get(){
    return n;
}
void Integer::set(int n){
    this->n = n;
}
bool Integer::isEven(){
    return true;
}

int main(){
    Integer n(30);
    cout << n.get() << ' ';
    n.set(50);
    cout << n.get() << ' ';

    Integer m("300");
    cout << m.get() << ' ';
    cout << m.isEven();
}