#include <iostream>
#include <string>
using namespace std;

class Person{
    string name;
    public:
    Person(){}
    Person(string name){this->name = name;}
    string getName(){return name;}
    void setName(string name){this->name = name;}
};

class Family{
    Person *p;
    int size;
    string familyname;
    public:
    Family(string name, int size);
    void show();
    ~Family(){delete []p;}
    void setName(int id, string name);
};

Family::Family(string name, int size){
    this->familyname = name;
    this->size = size;
    p = new Person[size];
}

void Family::show(){
    cout << familyname << "가족은 다음과 같이 " << size << "명 입니다.\n";
    for(int i=0;i<size;i++){
        cout << p[i].getName() << "\t";
    }
    cout << "\n";
}

void Family::setName(int id, string name){
    p[id].setName(name);
}

int main(){
    Family *simpson = new Family("Simpson", 3);
    simpson->setName(0, "Mr. simpson");
    simpson->setName(1, "Mrs. Simpson");
    simpson->setName(2, "Bart simpson");
    simpson->show();
}