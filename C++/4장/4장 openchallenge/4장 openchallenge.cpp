#include <iostream>
#include <string>
using namespace std;

class Player{
    string name;
    public:
    void setPlayer(string name);
    string getPlayer();
};

void Player::setPlayer(string name){
    this->name = name;
}

string Player::getPlayer(){
    return this->name;
}

class WordGame {
    Player *p;
    int num;
public:
    WordGame(int num);
    ~WordGame() { delete[] p; }
    void game();
};

WordGame::WordGame(int num) {
    this->num = num;
    p = new Player[num];    //동적객체배열선언
}

void WordGame::game() {
    string n;
    for (int i = 0; i <num; ++i) {
        cout << "참가자의 이름을 입력하세요. 빈칸 없이>>";
        cin >> n;
        p[i].setPlayer(n);
    }
    cout << "시작하는 단어는 아버지입니다" << '\n';
    string a = "아버지";
    string b;
    int i = 0;
    while(true) {
        cout << p[i%num].getPlayer() << ">>";
        cin >> b;
        int j = a.size(); //한글을 읽을 때 windows는 2byte, mac은 3byte
        if (a.at(j - 3) == b.at(0) && a.at(j-2) == b.at(1) && a.at(j-1) == b.at(2)) {
            a = b;
        }
        else {
            cout << p[i%num].getPlayer() << "탈락!!"<<endl;
            break;
        }
        i++;
    }
}

int main(){
    cout << "끝말 잇기 게임을 시작합니다" << '\n';
    cout << "게임에 참가하는 인원은 몇명입니까?";
    int num;
    cin >> num;
    WordGame wordgame(num);
    wordgame.game();
}