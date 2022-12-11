#include <iostream>
#include <map>
#include <string>
using namespace std;

class ScoreMan{
    map<string, int> score;
    public:
    void add();
    void view();
};

void ScoreMan::add(){
    string name;
    int n;
    cout << "이름과 점수 >> ";
    cin >> name >> n;
    if(score.find(name) == score.end())
    score[name] = n;
}

void ScoreMan::view(){
    string name;
    cout << "이름 >> ";
    cin >> name;
    if(score.find(name) == score.end()){
        cout << "해당 학생은 없습니다." << endl;
    }
    else{
        cout << name << "의 점수는 " << score[name] << endl;
    }
}


int main(){
    ScoreMan s;
    int n;
    cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다 *****" << endl;
    while(true){
        cout << "입력:1, 조회:2, 종료:3 >> ";
        cin >> n;
        if(n == 1){
            s.add();
        }
        else if(n == 2){
            s.view();
        }
        else if(n == 3){
            cout << "프로그램을 종료합니다..." << endl;
            break;
        }
    }
}