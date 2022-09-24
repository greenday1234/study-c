#include <iostream>
#include <string>
using namespace std;

class Circle{
    int radius;
    string name;
    public:
    void setCircle(string name, int radius);
    double getArea(){return radius*radius*3.14;}
    string getName(){return name;}
};

class CircleManager{
    Circle *p;
    int size;
    public:
    CircleManager(int size);
    ~CircleManager();
    void searchByname();
    void searchByArea();
};

int main(){

}