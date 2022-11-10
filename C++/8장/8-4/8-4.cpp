#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x; this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {
	string color;
public:
	ColorPoint():ColorPoint(1, 1){};
	ColorPoint(int x, int y) : Point(x, y) { this->color = "BLACK"; };
	void show();
	void setPoint(int x, int y);
	void setColor(string str);
};

void ColorPoint::setColor(string str) {
	this->color = str;
}

void ColorPoint::setPoint(int x, int y) {
	move(x, y);
}

void ColorPoint::show() {
	cout << color << "색으로 (" << getX() << ", " << getY() << ")에 위치한 점입니다." << endl;
}


int main() {
	ColorPoint zeroPoint; 
	zeroPoint.show();

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}