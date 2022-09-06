#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char op;
	int a, b;
	cout << "? ";
	cin >> a >> op >> b;
	if (op == '+') {
		cout << a << " + " << b << " = " << a + b;
	}
	else if (op == '-') {
		cout << a << " - " << b << " = " << a - b;
	}
	else if (op == '*') {
		cout << a << " * " << b << " = " << a * b;
	}
	else if (op == '/') 
		cout << a << " / " << b << " = " << a / b;
	else if (op == '%')
		cout << a << " % " << b << " = " << a % b;
	else
		cout << "잘못된 연산자!";
	
	return 0;
}