#include <iostream>
#include <cstring>

using namespace std;

int main() {
	cout << "���� ���� �� ������ �մϴ�. ����, ����, �� �߿��� �Է��ϼ���.\n";
	char s[5];
	cout << "�ι̿�>>";
	cin >> s;
	char t[5];
	cout << "�ٸ���>>";
	cin >> t;

	if (strcmp(s, "����") == 0 && strcmp(t, "��") == 0)
		cout << "�ι̿��� �̰���ϴ�.";
	else if (strcmp(s, "��") == 0 && strcmp(t, "����") == 0)
		cout << "�ι̿��� �̰���ϴ�.";
	else if (strcmp(s, "����") == 0 && strcmp(t, "����") == 0)
		cout << "�ι̿��� �̰���ϴ�.";
	else if (strcmp(t, "��") == 0 && strcmp(s, "����") == 0)
		cout << "�ٸ����� �̰���ϴ�.";
	else if (strcmp(t, "����") == 0 && strcmp(s, "����") == 0)
		cout << "�ٸ����� �̰���ϴ�.";
	else if (strcmp(t, "����") == 0 && strcmp(s, "��") == 0)
		cout << "�ٸ����� �̰���ϴ�.";
	else
		cout << "�����ϴ�.";

	return 0;
}