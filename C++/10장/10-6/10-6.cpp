#include <iostream>
using namespace std;

template <class T>
T *remove(T src[], int sizesrc, T minus[], int sizeminus, T& retsize){
    T a;
    T *c = new T[sizesrc + sizeminus];
    for(int i=0;i<sizesrc;i++){
        a = src[i];
        for(int j=0;j<sizeminus;j++){
            if(a == minus[j])
            break; 
            if(j == sizeminus-1)
            c[retsize++] = src[i];
        }
    }
    return c;
}

int main(){
    int src[] = {1, 10, 100, 5, 4};
    int minus[] = {1, 4, 2, 3, 6};
    int retsize=0;
    int *c = remove(src, 5, minus, 5, retsize);
    for(int i=0;i<retsize;i++)
    cout << c[i] << ' ';
}