#include <iostream>
#include <string>
using namespace std;

class Date{
    int year;
    int month;
    int day;
    public:
    Date(int a, int b, int c);
    Date(string a);
    int getYear();
    int getMonth();
    int getDay();
    void show();
};

Date::Date(int a, int b, int c){
    year = a;
    month = b;
    day = c;
}
Date::Date(string a){
    int date;
    year = stoi(a);

    date = a.find('/');
    month = stoi(a.substr(date+1));

    date = a.find('/', date+1);
    day = stoi(a.substr(date+1));
}
int Date::getYear(){
    return year;
}
int Date::getMonth(){
    return month;
}
int Date::getDay(){
    return day;
}
void Date::show(){
    cout << year << "년" << month << "월" << day << "일" << '\n';
}

int main(){
    Date birth(2014, 3, 20);
    Date independenceDay("1945/8/15");
    independenceDay.show();
    cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << '\n';
}