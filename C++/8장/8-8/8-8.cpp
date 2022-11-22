#include <iostream>
#include <string>
using namespace std;

class Printer{
    string name;
    string manufacturer;
    int printedCount;
    int availableCount;
    public:
    Printer(string name, string manufacturer, int availableCount){
        printedCount = 0;
        this->name = name;
        this->manufacturer = manufacturer;
        this->availableCount = availableCount;
    }
    void print(int pages){
        if(availableCount-pages < 0)
        cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        else{
        cout << "프린트하였습니다." << endl;
        availableCount -= pages;
        printedCount += pages;
        }
    }
    string getName(){return name;}
    string getManu(){return manufacturer;}
    int getCount(){return availableCount;}
};

class InkJetPrinter : public Printer{
    int availableInk;
    public:
    InkJetPrinter(string name, string manufacturer, int availableCount, int availableInk):Printer(name, manufacturer, availableCount){
        this->availableInk = availableInk;
    }
    void printInkJet(int pages){
        if(availableInk-pages < 0)
            cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
        else{
            if(getCount() - pages > 0){
            print(pages);
            availableInk -= pages;
            }
        }
    }
    int getInk(){return availableInk;}
};

class LaserPrinter : public Printer{
    int availableToner;
    public:
    LaserPrinter(string name, string manufacturer, int availableCount, int availableToner):Printer(name, manufacturer, availableCount){
        this->availableToner = availableToner;
    }
    void printLaser(int pages){
        if(availableToner-pages < 0)
        cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
        else{
            if(getCount()-pages > 0){
            print(pages);
            availableToner -= pages;
            }
        }
    }
    int getTonner(){return availableToner;}
};

int main(){
    InkJetPrinter ink("Officejet V40", "HP", 5, 10);
    LaserPrinter las("SCX-6x45", "삼성전자", 3, 20);
    int n, count;
    char c;
    cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
    cout << "잉크젯 : ";
    cout << ink.getName() << ", " << ink.getManu() << ", " << "남은 종이 " << ink.getCount() << "장, 남은 잉크 " << ink.getInk() << endl;
    cout << "레이저 : ";
    cout << las.getName() << ", " << las.getManu() << ", " << "남은 종이 " << las.getCount() << "장, 남은 토너 " << las.getTonner() << endl;
    cout << "\n";
    do{
    cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
    cin >> n >> count;
    if(n == 1){
        ink.printInkJet(count);
        cout << ink.getName() << ", " << ink.getManu() << ", " << "남은 종이 " << ink.getCount() << "장, 남은 잉크 " << ink.getInk() << endl;
        cout << las.getName() << ", " << las.getManu() << ", " << "남은 종이 " << las.getCount() << "장, 남은 토너 " << las.getTonner() << endl;

    }
    else{
        las.printLaser(count);
        cout << ink.getName() << ", " << ink.getManu() << ", " << "남은 종이 " << ink.getCount() << "장, 남은 잉크 " << ink.getInk() << endl;    
        cout << las.getName() << ", " << las.getManu() << ", " << "남은 종이 " << las.getCount() << "장, 남은 토너 " << las.getTonner() << endl;
    }
    cout << "계속 프린트 하시겠습니까(y/n)>>";
    cin >> c;
    cout << "\n";
    }while(c != 'n');
}