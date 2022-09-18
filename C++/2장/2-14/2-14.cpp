#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int sum=0;
    int sumtmp = 0;
    char coffee[100];
    int n = 0;
    cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다.\n";
    while(sum < 20000){
        cout << "주문>> ";
        cin >> coffee >> n;
        if(strcmp(coffee, "에스프레소")==0){
            sumtmp = 2000*n;
        }
        else if(strcmp(coffee, "아메리카노")==0){
            sumtmp = 2300*n;
        }
        else{
            sumtmp = 2500*n;
        }
        cout << sumtmp << "원입니다. 맛있게 드세요\n";
        sum += sumtmp;
    }
    cout << "오늘 " << sum << "원을 판매하여 카페를 닫습니다, 내일 봐요~~\n";
}