#include <iostream>

using namespace std;

double biggiest(double a[], int x) {
	double max;
	max = a[0];
	for (int i = 0; i < x; i++) {
		if (max < a[i])
			max = a[i];
	}
	return max;
}

int main() {
	double a[5];
	cout << "5���� �Ǽ��� �Է��϶�>>";
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	cout << "���� ū �� = " << biggiest(a, 5);
	
	return 0;
}