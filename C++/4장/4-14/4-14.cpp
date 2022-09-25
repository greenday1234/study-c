#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player{
    string name;
    public:
    void setPlayer(string name){this->name = name;}
    string getPlayer(){return name;}
};

class GamblingGame{
    Player player[2];
    int card[3];
    public:
    GamblingGame();
    void play();
};

GamblingGame::GamblingGame(){
    string name1;
    string name2;
    cout << "***** 겜블링 게임을 시작합니다. *****" << '\n';
    cout << "첫번째 선수 이름 >> ";
    cin >> name1;
    player[0].setPlayer(name1);
    cout << "두번째 선수 이름 >> ";
    cin >> name2;
    player[1].setPlayer(name2);
}

void GamblingGame::play(){
    int count = 0;
    while(true){
        int suc = 0;
        cout << player[count%2].getPlayer() << ":<Enter> \n";
        getchar();
        for(int i = 0;i<3;i++){
            card[i] = rand() % 3;
            cout << card[i] << '\t';
        }
        for(int i=0;i<2;i++){
            if(card[i] != card[i+1])
                suc++;
        }
        if(suc == 0){
            cout << player[count%2].getPlayer() << "님 승리!!";
            break;
        }
        else{
            cout << "아쉽군요! \n";
            count++;
        }
    }
}

int main(){
    GamblingGame game;
    game.play();
}