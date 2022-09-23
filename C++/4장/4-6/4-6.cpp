#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;

	while (true) {
		getline(cin, text);
		if (text == "exit")
			break;
		int len = text.length();

		for (int i = 0; i < len / 2; i++) {
			char tmp = text[i];
			text[i] = text[len - i - 1];
			text[len - i - 1] = tmp;
		}
		cout << text << '\n';
	}
}