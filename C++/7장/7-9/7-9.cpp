#include <iostream>
using namespace std;

class Circle{
    int radius;
    public:
    Circle(int radius = 0){this->radius = radius;}
    void show(){cout << "radius = " << radius << " 인 원" << endl;}  
    friend Circle operator +(int x, Circle c);
};

Circle operator +(int x, Circle c){
    Circle tmp;
    tmp.radius = x + c.radius;
    return tmp;
}

int main(){
    Circle a(5), b(4);
    b  = 1 + a;
    a.show();
    b.show();
}