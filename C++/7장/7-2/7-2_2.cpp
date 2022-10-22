#include <iostream>
#include <string>
using namespace std;
class Book{
    string title;
    int price, pages;
    public:
    Book(string title = "", int price = 0, int pages = 0){
        this->title = title;
        this->price = price;
        this->pages = pages;
    }
    void show(){
        cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
    }
    string getTitle(){return title;}
    friend bool operator ==(Book b, int price);
    friend bool operator ==(Book b, string title);
    friend bool operator == (Book b, Book op2);
};

bool operator ==(Book b, int price){
    if(b.price == price)
    return true;
    else
    return false;
}

bool operator ==(Book b, string title){
    if(b.title == title)
    return true;
    else
    return false;
}

bool operator ==(Book b, Book op2){
    if(b.title == op2.title && b.price == op2.price && b.pages == op2.pages)
    return true;
    else
    return false;
}

int main(){
    Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
    if(a == 30000) cout <<"정가 30000원" << endl;
    if(a == "명품 C++") cout << "명품 C++ 입니다." << endl;
    if(a == b) cout << "두 책이 같은 책입니다." << endl;
}