#include <iostream>
using namespace std;

class Dept{
    int size;
    int * scores;
    public:
    Dept(int size){
        this->size = size;
        scores = new int [size];
    }
    ~Dept();
    int getSize(){return size;}
    void read();
    bool isOver60(int index);
};
Dept::~Dept(){
    delete [] scores;
}
void Dept::read(){
    cout << size << "개 점수 입력 >> ";
    for(int i=0;i<size;i++){
        cin >> scores[i];
    }
}
bool Dept::isOver60(int index){
    if(scores[index] > 60)
    return true;
    else
    return false;
}

int countPass(Dept &dept){  //복사생성이 이루어지기 때문에 주소값을 넘겨 원본 객체 변수 공간을 그대로 사용
    int count = 0;
    for(int i=0;i<dept.getSize();i++){
        if(dept.isOver60(i))
        count++;
    }
    return count;
}

int main(){
    Dept com(10);
    com.read();
    int n = countPass(com); //복사 생성이 이루어짐
    cout << "60점 이상은 " << n << "명입니다.\n";
}