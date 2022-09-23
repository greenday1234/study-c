#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	srand((unsigned)time(0));
	while (true) {
		cout << ">> ";
		getline(cin, text);
		if (text == "exit")
			break;

		int len = text.length();
		int pos = rand()%len;
		int c = rand() % 26;
		char ch = 'a' + c;

		text[pos] = ch;
		cout << text << '\n';
	}
}