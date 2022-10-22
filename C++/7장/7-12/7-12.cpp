#include <iostream>
using namespace std;

class SortedArray{
    int size;
    int *p;
    void sort();
    public:
    SortedArray(){p = NULL; size = 0;}
    SortedArray(SortedArray& src);
    SortedArray(int p[], int size);
    ~SortedArray();
    SortedArray operator +(SortedArray& op2);
    SortedArray& operator =(const SortedArray& op2);
    void show();
};

void SortedArray::sort(){
    int tmp;
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(p[i] < p[j] || p[i] == p[j]);
            else{
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }
}

SortedArray::SortedArray(SortedArray& src){
    size = src.size;
    p = new int [size];
    for(int i=0;i<size;i++){
        p[i] = src.p[i];
    }
}

SortedArray::SortedArray(int p[], int size){
    this->size = size;
    this->p = new int [size];
    for(int i=0;i<size;i++){
        this->p[i] = p[i];
    }
}

SortedArray::~SortedArray(){
    delete [] p;
}

void SortedArray::show(){
    sort();
    cout << "배열 출력 : ";
    for(int i=0;i<size;i++){
        cout << p[i] << ' ';
    }
    cout << endl;
}

SortedArray SortedArray::operator +(SortedArray& op2){
    SortedArray s;
    s.size = size + op2.size;
    s.p = new int [s.size];
    for(int i=0;i<size;i++){
        s.p[i] = p[i];
    }
    for(int i=size;i<s.size;i++){
        s.p[i] = op2.p[i];
    }
    return s;
}

SortedArray& SortedArray::operator =(const SortedArray& op2){
    delete [] p;
    size = op2.size;
    p = new int [size];
    for(int i=0;i<size;i++){
        p[i] = op2.p[i];
    }
    return *this;
}

int main(){
    int n[] = {2, 20, 6};
    int m[] = {10, 7, 8, 30};
    SortedArray a(n, 3), b(m, 4), c;
    c = a+b;

    a.show();
    b.show();
    c.show();
}