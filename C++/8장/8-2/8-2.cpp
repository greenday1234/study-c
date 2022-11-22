#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; };
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(){};
	NamedCircle(int a, string str);
	void show();
	void setName(string str);
	string getName();
};

string NamedCircle::getName() {
	return name;
}

void NamedCircle::setName(string str) {
	this->name = str;
}

NamedCircle::NamedCircle(int a, string str) {
	setRadius(a);
	this->name = str;
}

void NamedCircle::show() {
	cout << "반지름이 " << getRadius() << "인 " << name << endl;
}

int main() {
	NamedCircle pizza[5];
	int i = 1;
	string name;
	int n;
	cout << "5개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	for(int i=0;i<5;i++){
		cout << i+1 <<  ">> ";
		cin >> n >> name;
		pizza[i].setName(name);
		pizza[i].setRadius(n);
	}
	int max=pizza[0].getRadius();
	int ind = 0;
	for(int i=1;i<5;i++){
		if(max < pizza[i].getRadius()){
		max = pizza[i].getRadius();
		ind = i;
		}
	}

	cout << "가장 면적이 큰 피자는 " << pizza[ind].getName() << "입니다." << endl; 
}