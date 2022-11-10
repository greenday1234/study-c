#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0; // 스택에 n을 푸시한다. 스택이 full이면 false 리턴
	virtual bool pop(int& n) = 0; // 스택에서 팝한 정수를 n에 리턴한다. 스택이 empty이면 false 리턴
	virtual int size() = 0; // 현재 스택에 저장된 정수의 개수 리턴
};

class IntStack : public AbstractStack {
	int num;
	int* stack;
	int top;
public:
	IntStack(int num) {
		this->num = num;
		this->stack = new int[num];
		top = -1;
	}

	bool push(int n) {
		if (top >= this->num-1)
			return false;
		else {
			stack[++top] = n;
			return true;
		}
	}
	bool pop(int& n) {
		if (top == -1)
			return false;
		else {
			n = stack[top--];
			return true;
		}
	}

	int size() {return top;}
};

int main() {
	IntStack a(5);
	for (int i = 0; i < 10; i++) { // 처음 5 개를 성공적으로 push되고 다음 5 개는 스택 full로 push 실패
		if (a.push(i)) cout << "push 성공" << endl;
		else cout << "스택 full" << endl;
	}

	int n;
	for (int i = 0; i < 10; i++) { // 처음 5 개를 성공적으로 pop되고 다음 5 개는 스택 empty로 pop 실패
		if (a.pop(n)) cout << "pop 성공 " << n << endl;
		else cout << "스택 empty" << endl;
	}
}