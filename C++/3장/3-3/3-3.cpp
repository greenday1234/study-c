#include <iostream>
#include <string>

using namespace std;
class Account{
    string name;
    int id;
    int money;
    public:
    Account(string name, int id, int money);
    void deposit(int money);
    string getOwner();
    int inquiry();
    int withdraw(int money);
};
Account::Account(string name, int id, int money){
    this->name = name;
    this->id = id;
    this->money = money;
}
void Account::deposit(int money){
    this->money += money;
}
string Account::getOwner(){
    return name;
}
int Account::inquiry(){
    return money;
}
int Account::withdraw(int money){
    this->money -= money;
    return money;
}

int main(){
    Account a("kitae", 1, 5000);
    a.deposit(50000);
    cout << a.getOwner() << "의 잔액은 " << a.inquiry() << '\n';
    int money = a.withdraw(20000);
    cout << a.getOwner() << "의 잔액은 " << a.inquiry() << '\n';
}