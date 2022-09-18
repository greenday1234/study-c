#include <iostream>
#include <cstring>
using namespace std;

int main(){
    cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다.\n";
    cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다.\n";
    char str[10000];
    int count=0;
    cin.getline(str,10000, ';');
    int sum = 0;
    for(int i=0;i<strlen(str);i++){
        if(isalpha(str[i])){
            sum++;
        }
        tolower(str[i]);
    }
    cout << "총 알파벳 수 " << sum << "\n";
    for(char i= 'a'; i<='z';i++){
        for(int j=0;j<strlen(str);j++){
            if(str[j] == i){
                count++;
            }
        }
        cout << i << " (" << count << ") : ";
        for(int k=0;k<count;k++){
            cout << "*";
        }
        cout << "\n";
        count = 0;
    }
}