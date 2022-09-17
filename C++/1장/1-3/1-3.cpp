#include <iostream>

int main(){

    int n = 0;
    for(int i=1;i<=10;i++)
        n = n+i;
    std::cout << "1에서 10까지 더한 결과는 " << n << "입니다.\n";
    return 0;
}