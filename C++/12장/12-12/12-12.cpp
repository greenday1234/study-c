#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string line, word;
    vector<string> v;
    ifstream fin("words.txt", ios::in);
    if(!fin){
        cout << "file not found" << endl;
        return 0;
    }

    while(getline(fin, line)){
        v.push_back(line);
    }
    cout << "... words.txt 파일 로딩 완료" << endl;
    fin.close();
    cout << "검색을 시작합니다. 단어를 입력해주세요." << endl;
    while(true){
        cout << "단어 >> ";
        cin >> word;
        if(word == "exit")
        break;

        vector<string> temp;
        for(int i=0;i<v.size();i++){
            int cnt = 0;
            if(v[i].length() != word.length())
            continue;
            for(int j=0;j<word.length();j++){
                if(v[i].at(j) == word[j])
                cnt++;
            }
            if(cnt == word.length() -1)
            temp.push_back(v[i]);
        }
        for(int i=0;i<temp.size();i++){
            cout << temp[i] << endl;
        }
    }
}