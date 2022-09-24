#include <iostream>
using namespace std;

class Circle{
    int radius;
    public:
    void setRadius(int radius);
    double getArea();
};

void Circle::setRadius(int radius){
    this->radius = radius;
}
double Circle::getArea(){
    return 3.14*radius*radius;
}

int main(){
    int radius;
    int count=0;
    Circle *circle = new Circle[3];
    for(int i=0;i<3;i++){
        cout << "원 " << i+1 << "의 반지름 >> ";
        cin >> radius;
        circle[i].setRadius(radius);
        if(circle[i].getArea() > 100)
        count++;
    }
    
    cout << "면적이 100보다 큰 원은 " << count << "개 입니다.\n";
    delete []circle;
}