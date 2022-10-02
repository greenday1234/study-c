#include <iostream>
#include <string>
using namespace std;

class Buffer{
    string text;
    public:
    Buffer(string text){this->text = text;}
    void add(string next){this->text += next;}
    void print(){cout << text << "\n";}
};

Buffer& append(Buffer& buf, string text){
    buf.add(text);
    return buf;
}

int main(){
    Buffer buf("Hello");
    Buffer& temp = append(buf, "Guys"); //temp는 buf와 연결된다
    temp.print();
    buf.print();
}