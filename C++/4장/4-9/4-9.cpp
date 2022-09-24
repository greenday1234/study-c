#include <iostream>
#include <string>
using namespace std;

class Person{
    string name;
    string tel;
    public:
    Person(){};
    string getName(){return name;};
    string getTel(){return tel;};
    void set(string name, string tel);
};

void Person::set(string name, string tel){
    this->name = name;
    this->tel = tel;
}

int main(){
    cout << "이름과 전화 번호를 입력해 주세요\n";
    Person *p = new Person[3];
    string str;
    string name;
    string tel;
    for(int i=0;i<3;i++){
        cout << "사람 " << i+1 << ">> ";
        getline(cin,str,'\n'); // cin으로 나눠서 사용 가능
        int tmp = str.find(" ");
        int tmp_t = str.length() - tmp;
        name = str.substr(0, tmp);
        tel = str.substr(tmp+1, tmp_t);
        p[i].set(name, tel);
    }
    cout << "모든 사람의 이름은 ";
    for(int i=0;i<3;i++){
      cout << p[i].getName() << " ";
    }
    cout << "\n";
    cout << "전화번호를 검색합니다. 이름을 입력하세요>>";
    cin >> str;
    for(int i=0;i<3;i++){
        if(p[i].getName() == str){
            cout << "전화 번호는 " << p[i].getTel();
        }
    }
    delete [] p;
}