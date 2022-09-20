#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SelectableRandom {
	int seed = 0;
public:
	int nextEven();
	int nextOddInRange(int start, int end);
};

int SelectableRandom::nextEven() {
	//srand((unsigned int)time(0));
	int n;
	do {
		n = rand();
	} while (n % 2 != 0);
	return n;
}

int SelectableRandom::nextOddInRange(int start, int end) {
	//srand((unsigned int)time(0));
	int n;
	do {
		n = rand() % (end - start + 1) + start;
	} while (n % 2 != 1);
	return n;
}

int main() {
	SelectableRandom r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextEven();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 9까지의 랜덤 홀수 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextOddInRange(2, 9);
		cout << n << ' ';
	}
	cout << endl;
	return 0;
}