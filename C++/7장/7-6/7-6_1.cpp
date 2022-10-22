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
        cout << "Matrix = {" << num[0] << ' ' << num[1] << ' ' << num[2] << ' ' << num[3] << "}" << endl; 
    }
    Matrix operator +(Matrix b);
    void operator +=(Matrix b);
    bool operator ==(Matrix b);
};

Matrix Matrix::operator +(Matrix b){
    Matrix tmp;
    for(int i=0;i<4;i++){
        tmp.num[i] = this->num[i] + b.num[i];
    }
    return tmp;
}

void Matrix::operator +=(Matrix b){
    for(int i=0;i<4;i++){
        this->num[i] += b.num[i];
    }
}

bool Matrix::operator ==(Matrix b){
    for(int i=0;i<4;i++){
        if(this->num[i] != b.num[i])
        return false;
    }
    return true;
}

int main(){
    Matrix a(1,2,3,4), b(2,3,4,5), c;
    c = a+b;
    a += b;
    a.show();
    b.show();
    c.show();
    if(a == c)
    cout << "a and c are the same" << endl;
}