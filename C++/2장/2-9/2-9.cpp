#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char name[100];
    char add[100];
    char age[100];
    cout << "이름은? ";
    cin.getline(name, 100);
    cout << "주소는? ";
    cin.getline(add,100);
    cout << "나이는> ";
    cin.getline(age,100);
    cout << name << ", " << add << ", " << age << "세";
}