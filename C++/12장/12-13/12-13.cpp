#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    string line, word;
    vector<string> v;
    ifstream fin("words.txt");
    if(!fin){
        cout << "file not found" << endl;
        return 0;
    }
    while(getline(fin, line)){
        v.push_back(line);
    }
    cout << "... words.txt 파일 로딩 완료" << endl;
    cout << "검색을 시작합니다. 단어를 입력해 주세요." << endl;
    while(true){
        cout << "단어 >> ";
        cin >> word;
        if(word == "exit")
        break;
        vector<string> temp;
        for(int i=0;i<v.size();i++){
            if (word == v[i].substr(0,word.length()))
                temp.push_back(v[i]);
        }
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << endl;
        }
        if (temp.size() == 0) 
            cout << "발견할 수 없음" << endl;
        
    }
}