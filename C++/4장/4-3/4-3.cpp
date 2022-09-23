#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'a')
			cnt++;
	}
	cout << cnt << "개" << " 있습니다.";
}