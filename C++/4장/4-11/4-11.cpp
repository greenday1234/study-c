#include <iostream>
using namespace std;

class Container{
    int size;
    public:
    Container(){size = 10;}
    void fill(){size = 10;}
    void consume(){size--;}
    int getSize(){return size;}
};

class CoffeevendingMachine{
    Container tong[3];
    void fill();
    void selectEspresso();
    void selectAmericano();
    void selectSugarCoffee();
    void show();
    public:
    void run();
};

void CoffeevendingMachine::fill(){
    for(int i=0;i<3;i++){
        tong[i].fill();
    }
    show();
}

void CoffeevendingMachine::selectEspresso(){
    tong[0].consume();
    int c = tong[0].getSize();
    tong[1].consume();
    int w = tong[1].getSize();
    if(c < 0 || w < 0){
        cout << "원료가 부족합니다.\n";
    }
    else{
    cout << "에스프레소 드세요\n";
    }
}

void CoffeevendingMachine::selectAmericano(){
    tong[0].consume();
    int c = tong[0].getSize();
    tong[1].consume();
    tong[1].consume();
    int w = tong[1].getSize();
    if(c < 0 || w < 0){
        cout << "원료가 부족합니다.\n";
    }
    else{
    cout << "아메리카노 드세요\n";
    }
}

void CoffeevendingMachine::selectSugarCoffee(){
    tong[0].consume();
    int c = tong[0].getSize();
    tong[1].consume();
    tong[1].consume();
    int w = tong[1].getSize();
    tong[2].consume();
    int s = tong[2].getSize();
    if(c < 0 || w < 0 || s < 0){
        cout << "원료가 부족합니다.\n";
    }
    else{
    cout << "설탕커피 드세요\n";
    }
}

void CoffeevendingMachine::show(){
    cout<< "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << '\n';
}

void CoffeevendingMachine::run(){
    int n;
    cout << "***** 커피자판기를 작동합니다. *****\n";
    while(true){
        cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기) >> ";
        cin >> n;
        switch(n){
            case 1:
            selectEspresso();
            break;
            case 2:
            selectAmericano();
            break;
            case 3:
            selectSugarCoffee();
            break;
            case 4:
            show();
            break;
            case 5:
            fill();
            break;
            default:
            cout << "잘못 입력하셨습니다.프로그램을 종료합니다.\n";
            return;
        }
    }
}

int main(){
    CoffeevendingMachine cfe;
    cfe.run();
}