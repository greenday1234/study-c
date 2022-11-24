#include <iostream>
using namespace std;

class AbstractGate { // 추상 클래스
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0; // 순수 가상 함수
};

class ANDGate : public AbstractGate{
	public:
	bool operation(){
		if(x==1 && y==1){
			return true;
		}
		else
		return false;
	}
};

class ORGate : public AbstractGate{
	public:
	bool operation(){
		if(x==1||y==1){
			return true;
		}
		else
		return false;
	}
};

class XORGate : public AbstractGate{
	public:
	bool operation(){
		if((x==1&&y==0 || y==1&&x==0)){
			return true;
		}
		else
		return false;
	}
};

int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);
	cout.setf(ios::boolalpha); // 불린 값을 "true', "false" 문자열로 출력할 것을 지시
	cout << andGate.operation() << endl; // AND 결과는 false
	cout << orGate.operation() << endl; // OR 결과는 true
	cout << xorGate.operation() << endl; // XOR 결과는 true
}