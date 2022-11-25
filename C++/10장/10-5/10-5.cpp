#include <iostream>
using namespace std;

template <class T>
T *concat(T a[] , int na, T b[], int nb){
    T *c = new T[na+nb];
    for(int i=0;i<na;i++){
        c[i] = a[i];
    }
    for(int i=0;i<nb;i++){
        c[i+na] = b[i];
    }
    return c;
}

int main(){
    int a[] = {1, 10, 100, 5, 4};
    int b[] = {2, 20, 200, 10, 8};
    int *c = concat(a, 5, b, 5);
    for(int i=0;i<10;i++)
    cout << c[i] << ' ';
}