#include <iostream>

using namespace std;

int main() {
	int x, y;
	cout << "두 수를 입력하라>>";
	cin >> x >> y;
	if (x > y)
		cout << "큰 수 = " << x;
	else
		cout << "큰 수 = " << y;
	return 0;
}