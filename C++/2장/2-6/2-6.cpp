#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str1[100], str2[100];
	cout << "�� ��ȣ�� �Է��ϼ���>>";
	cin.getline(str1, 100, '\n');
	cout << "�� ��ȣ�� �ٽ� �� �� �Է��ϼ���>>";
	cin.getline(str2, 100, '\n');
	if (strcmp(str1, str2) == 0)
		cout << "�����ϴ�.";
	else
		cout << "�ٸ��ϴ�.";
	return 0;
}