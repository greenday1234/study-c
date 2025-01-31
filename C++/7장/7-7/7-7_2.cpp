#include <iostream>
using namespace std;

class Matrix{
    int num[4];
    public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0){
        num[0] = a;
        num[1] = b;
        num[2] = c;
        num[3] = d;
    }
    void show(){
        cout << "Matrix = { " << num[0] << ' ' << num[1] << ' ' << num[2] << ' ' << num[3] << " }" << endl;
    }
    friend void operator >>(Matrix a, int x[4]);
    friend void operator <<(Matrix& b, int y[4]);
};

void operator >>(Matrix a, int x[4]){
    for(int i=0;i<4;i++){
        x[i] = a.num[i];
    }
}

void operator <<(Matrix& b, int y[4]){
    for(int i=0;i<4;i++){
        b.num[i] = y[i];
    }
}

int main(){
    Matrix a(4,3,2,1), b;
    int x[4], y[4] = {1,2,3,4};
    a >> x;
    b << y;

    for(int i=0;i<4;i++){
        cout << x[i] << ' ';
    }
    cout << endl;
    b.show();
}