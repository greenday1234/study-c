#include <iostream>
using namespace std;

class Box{
int width, height;
char fill;
public:
Box(int w, int h){
    setSize(w,h);
    fill = '*';
}
void setFill(char f){
    fill = f;
}
void setSize(int w, int h){
    width = w;
    height = h;
}
void draw();
};
void Box::draw(){
    for(int i=0;i<height;i++){
        for(int j=0; j<width;j++)
        cout << fill;
        cout << '\n';
    }
}
int main(){
    Box b(10,2);
    b.draw();
    cout << '\n';
    b.setSize(7,4);
    b.setFill('^');
    b.draw();
}