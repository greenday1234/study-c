#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Nation {
	string nation;
	string capital;
public:
	Nation(string nation, string capital) {
		this->nation = nation;
		this->capital = capital;
	}
	string getNation() { return nation; }
	string getCapital() { return capital; }
};

class NationGame {
	vector<Nation> v;
public:
	NationGame();
	void add();
	void play();
};

NationGame::NationGame() {
	Nation n[] = { Nation("한국", "서울"), Nation("미국", "워싱턴"), Nation("우즈베키스탄", "타슈켄트"), Nation("북한", "평양"), Nation("영국", "런던"), Nation("러시아", "모스크바"), 
	Nation("프랑스", "파리"), Nation("스위스", "베른"), Nation("캐나다", "오타와") };
	for (int i = 0; i < 9; i++) {
		v.push_back(n[i]);
	}
	srand(unsigned(time(NULL)));
}

void NationGame::add() {
	string n, c;
	cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
	cout << "나라와 수도를 입력하세요(no no이면 입력 끝)" << endl;
	while (true) {
		cout << v.size() + 1 << " >>";
		cin >> n >> c;
		if (n == "no" && c == "no")
			break;
		int i;
		for (i = 0; i < v.size(); i++) {
			if (v[i].getNation() == n)
				break;
		}
		if (i < v.size())
			continue;
		Nation na(n, c);
		v.push_back(na);
	}
}

void NationGame::play() {
	while (true) {
		string c;
		int i = rand() % v.size();
		cout << v[i].getNation() << "의 수도는? ";
		cin >> c;
		if (c == "exit")
			return;
		if (v[i].getCapital() == c) {
			cout << "정답" << endl;
		}
		else {
			cout << "오답" << endl;
		}
	}
}

int main() {
	cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****" << endl;
	NationGame ng;
	while (true) {
		int menu;
		cout << "정보 입력 :1, 퀴즈 :2, 종료:3 >>";
		cin >> menu;
		if (menu == 1) {
			ng.add();
		}
		else if (menu == 2) {
			ng.play();
		}
		else {
			return 0;
		}
	}
}