#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("test.txt");
    if(!fin){
        cout << "file not found\n";
        return 0;
    }
    int c;
    while((c = fin.get()) != EOF){
        cout.put(c);
    }
    fin.close();
}