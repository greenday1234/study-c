#include <iostream>

using namespace std;

class Oval{
int width, height;
public:
Oval(int width, int height);
Oval();
~Oval();
int getWidth();
int getHeight();
void set(int w, int h);
void show();
};
Oval::Oval(int width, int height){
    this->width = width;
    this->height = height;
}
Oval::Oval(){
    this->width = 1;
    this->height = 1;
}
Oval::~Oval(){
    cout << "Oval 소멸 : width = " << width << ", height = " << height << '\n';
}
int Oval::getWidth(){
    return width;
}
int Oval::getHeight(){
    return height;
}
void Oval::set(int w, int h){
    width = w;
    height = h;
}
void Oval::show(){
    cout << "width = " << width << ", height = " << height << '\n';
}

int main(){
    Oval a, b(3,4);
    a.set(10,20);
    a.show();
    cout << b.getWidth() << "," << b.getHeight() << '\n';
}