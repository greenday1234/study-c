#include <iostream>
#include <string>
using namespace std;

class Histogram{
    string str;
    public:
    Histogram(string str){this->str = str;}
    void put(string str){this->str.append(str);}
    void putc(char c){this->str.append(1, c);}
    void print();
};

void Histogram::print(){
    cout << "\n";
    cout << str << '\n';
    cout << '\n';
    int count = 0;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for(int i=0;i<str.length(); i++){
        if(isalpha(str[i])){
            count++;
        }
    }
    cout << "총 알파벳 수 " << count<< '\n';
    cout << '\n';
    for(char c = 'a'; c<='z'; c++){
        int chnum = 0;
        for(int k=0;k<str.length();k++){
            if(str[k] == c)
                chnum++;
        }
        cout << c << " (" << chnum << ")\t : ";
        for(int i=0;i<chnum;i++)
        cout << "*";
        cout << '\n';
    }
}

int main(){
    Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
    elvisHisto.put("falling in love with you");
    elvisHisto.putc('-');
    elvisHisto.put("Elvis Presley");
    elvisHisto.print();
}