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
	NamedCircle(int a, string str);
	void show();
};

NamedCircle::NamedCircle(int a, string str) {
	setRadius(a);
	this->name = str;
}

void NamedCircle::show() {
	cout << "반지름이 " << getRadius() << "인 " << name << endl;
}

int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();
}