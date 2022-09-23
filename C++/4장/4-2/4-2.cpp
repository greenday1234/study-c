#include <iostream>
using namespace std;

int main() {
	cout << "정수 5개 입력 >> ";
	int *n = new int[5];
	double avg = 0;
	for (int i = 0; i < 5; i++) {
		cin >> n[i];
		avg += n[i];
	}
	cout << "평균 " << avg/5;
	delete []n;
}