#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char a[100];
	int count = 0;
	cout << "문자열 입력>> ";
	cin.getline(a, 100, '\n');
	for (int j = 0; j < strlen(a); j++) {
		for (int i = 0; i <= j; i++) {
			cout << a[i];
		}
		cout << "\n";
	}

	return 0;
}