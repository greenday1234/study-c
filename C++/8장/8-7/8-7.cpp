#include <iostream>
using namespace std;

class BaseMemory{
    char *mem;
    protected:
    BaseMemory(int size){mem = new char[size];}
    void setData(char *x, int n){
        for(int i=0;i<n;i++)
            mem[i] = x[i];
        }
    void setData(int x, char n){mem[n] = x;}
    char getData(int ind){return mem[ind];}
};

class ROM : public BaseMemory{
    public:
    ROM(int size, char *x, int n);
    char read(int ind){return getData(ind);}
};

ROM::ROM(int size, char *x, int n) : BaseMemory(size){
    setData(x, n);
}

class RAM : public BaseMemory{
    public:
    RAM(int size):BaseMemory(size){}
    void write(int i, char c){setData(c, i);}
    char read(int ind){return getData(ind);}
};

int main(){
    char x[5] = {'h','e','l','l','o'};
    ROM biosROM(1024*10, x, 5);
    RAM mainMemory(1024*1024);

    for(int i=0;i<5;i++)
    mainMemory.write(i, biosROM.read(i));
    for(int i=0;i<5;i++)
    cout << mainMemory.read(i);
}