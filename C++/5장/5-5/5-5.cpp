#include <iostream>
using namespace std;

class Circle{
    int radius;
    public:
    Circle(int r){this->radius = r;}
    int getRadius(){return radius;}
    void setRadius(int r){this->radius = r;}
    void show(){cout << "반지름이 " << radius << "인 원 \n";}
};

void increaseBy(Circle &a, Circle b){
    int r = a.getRadius() + b.getRadius();
    a.setRadius(r);
}

int main(){
    Circle x(10), y(5);
    increaseBy(x, y);
    x.show();
}