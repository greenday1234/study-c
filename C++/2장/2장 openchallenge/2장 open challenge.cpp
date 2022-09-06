#include <iostream>
#include <cstring>

using namespace std;

int main() {
	cout << "가위 바위 보 게임을 합니다. 가위, 바위, 보 중에서 입력하세요.\n";
	char s[5];
	cout << "로미오>>";
	cin >> s;
	char t[5];
	cout << "줄리엣>>";
	cin >> t;

	if (strcmp(s, "가위") == 0 && strcmp(t, "보") == 0)
		cout << "로미오가 이겼습니다.";
	else if (strcmp(s, "보") == 0 && strcmp(t, "바위") == 0)
		cout << "로미오가 이겼습니다.";
	else if (strcmp(s, "바위") == 0 && strcmp(t, "가위") == 0)
		cout << "로미오가 이겼습니다.";
	else if (strcmp(t, "보") == 0 && strcmp(s, "바위") == 0)
		cout << "줄리엣이 이겼습니다.";
	else if (strcmp(t, "바위") == 0 && strcmp(s, "가위") == 0)
		cout << "줄리엣이 이겼습니다.";
	else if (strcmp(t, "가위") == 0 && strcmp(s, "보") == 0)
		cout << "줄리엣이 이겼습니다.";
	else
		cout << "비겼습니다.";

	return 0;
}