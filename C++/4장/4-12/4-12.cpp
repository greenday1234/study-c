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

void Circle::setCircle(string name, int radius){
    this->name = name;
    this->radius = radius;
}

class CircleManager{
    Circle *p;
    int size;
    public:
    CircleManager(int size);
    ~CircleManager(){delete [] p;}
    Circle * getCircle(){return p;} // 주소값 리턴
    void searchByname();
    void searchByArea();
};

CircleManager::CircleManager(int size){
    this->size = size;
    p = new Circle[size];
}

void CircleManager::searchByname(){
    string cir;
    cout << "검색하고자 하는 원의 이름 >> ";
    cin >> cir;
    for(int i=0;i<size;i++){
        if(cir == p[i].getName()){
            cout << p[i].getName() << "의 면적은 " << p[i].getArea() << '\n';
        }
    }
}

void CircleManager::searchByArea(){
    int n;
    cout << "최소 면적을 정수로 입력하세요 >> ";
    cin >> n;
    cout << n << "보다 큰 원을 검색합니다.\n";
    for(int i=0;i<size;i++){
        if(n < p[i].getArea()){
            cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
        }
    }
}

int main(){
    int n;
    string str;
    cout << "원의 개수 >> ";
    cin >> n;
    CircleManager c(n);
    string a, b;
    int tmp;
    int f;
    for(int i=0;i<n;i++){
        cout << "원 " << i+1 << "의 이름과 반지름 >> ";
        cin >> a >> b;
        int find = stoi(b);
        c.getCircle()[i].setCircle(a, find);
    }
    c.searchByname();
    c.searchByArea();
}