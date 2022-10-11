#include <iostream>

int main(){
    int n = 0;
    for(int i=1;i<=10;i++){
        n += i;
    }
    std::cout << "결과는 " << n << "입니다.";
}