#include <iostream>
using namespace std;

class Statistics{
    int *num;
    int count;
    public:
    Statistics(){
        num = new int[8];
        count = 0;
    }
    bool operator !();
    Statistics& operator <<(int x);
    void operator ~();
    void operator >>(int& avg);
};

bool Statistics::operator !(){
    if(count == 0)
    return true;
    else
    return false;
}

Statistics& Statistics::operator <<(int x){
    num[count++] = x;
    return *this;
}

void Statistics::operator ~(){
    for(int i=0;i<count;i++){
        cout << num[i] << ' ';
    }
    cout << endl;
}

void Statistics::operator >>(int& avg){
    int sum = 0;
    for(int i=0;i<count;i++){
        sum += num[i];
    }
    avg = sum/count;
}

int main(){
    Statistics stat;
    if(!stat)
    cout << "현재 통계 데이터가 없습니다." << endl;

    int x[5];
    cout << "5 개의 정수를 입력하시오.>>";
    for(int i=0;i<5;i++)
    cin >> x[i];

    for(int i=0;i<5;i++)
    stat << x[i];

    stat << 100 << 200;
    ~stat;

    int avg;
    stat >> avg;
    cout <<"avg = " << avg << endl;
}