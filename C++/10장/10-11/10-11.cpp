#include <iostream>
#include <string>
#include <map>
using namespace std;

class ScoreMan {
	map<string, int> scoreMap;
public:
	void add();
	void view();
};

void ScoreMan::add() {
	string name;
	int score;

	cout << "이름과 점수 >>";
	cin >> name >> score;
	if (scoreMap.find(name) == scoreMap.end()) {
		scoreMap[name] = score;
	}
}

void ScoreMan::view() {
	string name;
	cout << "이름 >> ";
	cin >> name;
	if (scoreMap.find(name) == scoreMap.end())
		cout << name << "은 없는 사람입니다." << endl;
	else
		cout << name << "의 점수는 " << scoreMap[name] << endl;
}

int main() {
	ScoreMan sm;
	cout << "***** 점수관리 프로그램을 시작합니다. *****" << endl;
	int menu;
	while (true) {
		cout << "입력:1, 조회:2, 종료:3 >> ";
		cin >> menu;
		switch (menu) {
		case 1:
			sm.add();
			break;
		case 2:
			sm.view();
			break;
		case 3:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
	}
}