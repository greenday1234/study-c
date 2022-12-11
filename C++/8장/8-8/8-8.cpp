#include <iostream>
#include <string>
using namespace std;

class Printer{
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;
    public:
    Printer(string model, string manufacturer, int availableCount){
        printedCount = 0;
        this->model = model;
        this->manufacturer = manufacturer;
        this->availableCount = availableCount;
    }
    void print(int pages){
        if(availableCount-pages < 0){
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
        else{
            cout << "프린트 하였습니다." << endl;
            printedCount += pages;
            availableCount -= pages;
        }
    }
    void show();
    string getmodel(){return model;}
    string getmanufacturer(){return manufacturer;}
    int getavailableCount(){return availableCount;}
};

class InkJetPrinter : public Printer{
    int availableink;
    public:
    InkJetPrinter(string model, string manufacturer, int availableCount, int availableink):Printer(model, manufacturer, availableCount){
        this->availableink = availableink;
    }
    void inkjetprint(int pages){
        if(availableink-pages < 0){
            cout << "잉크가 부족해 프린트할 수 없습니다." << endl;
        }
        else{
            if(getavailableCount()-pages > 0){
            print(pages);
            availableink -= pages;
            }
            else{
                cout << "용지가 부족해 프린트할 수 없습니다." << endl;
            }
        }
    }
    void show(){
        cout << "잉크젯 : " << getmodel() << " ," << getmanufacturer() << " ,남은 종이" << getavailableCount() << "장 ,남은 잉크 " << availableink << endl;
    }
};

class LaserPrinter : public Printer{
    int availabletoner;
    public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availabletoner):Printer(model, manufacturer, availableCount){
        this->availabletoner = availabletoner;
    }
    void laserprint(int pages){
        if(availabletoner-pages < 0){
            cout << "토너가 부족해 프린트할 수 없습니다." << endl;
        }
        else{
            if(getavailableCount()-pages > 0){
            print(pages);
            availabletoner -= pages;
            }
            else{
                cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
            }
        }
    }
    void show(){
        cout << "레이저 : " << getmodel() << " ," << getmanufacturer() << " ,남은 종이" << getavailableCount() << "장 ,남은 토너 " << availabletoner << endl;
    }
};

int main(){
    InkJetPrinter inkjet("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);
    cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
    inkjet.show();
    laser.show();
    cout << endl;
    int p, n;
    char c;
    while(true){
        cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
        cin >> p >> n;
        if(p == 1){
            inkjet.inkjetprint(n);
            inkjet.show();
            laser.show();
        }
        else if(p == 2){
            laser.laserprint(n);
            inkjet.show();
            laser.show();
        }
        cout << "계속 프린트 하시겠습니까(y/n)>>";
        cin >> c;
        if(c == 'n')
        break;
        cout << endl;
    }

}