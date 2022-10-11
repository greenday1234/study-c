#include <iostream>
using namespace std;

class ArrayUtility{
    public:
    static int* concat(int s1[], int s2[], int size);
    static int* remove(int s1[], int s2[], int size, int& retsize);
};

int* ArrayUtility::concat(int s1[], int s2[], int size){
    int *s3 = new int[size];
    for(int i=0;i<size;i++){
        s3[i] = s1[i];
    }
    for(int i=size;i<size*2;i++){
        s3[i] = s2[i-size];
    }
    return s3;
}

int* ArrayUtility::remove(int s1[], int s2[], int size, int& retsize){
    int count = 0;
    int *s = new int[size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(s1[i] == s2[j])
            break;
            if(j == size-1)
            s[count++] = s1[i];
        }
    }
    retsize = count;
    return s;
}

int main(){
    int x[5];
    int y[5];
    cout << "정수를 5개 입력하라. 배열 x에 삽입한다>> ";
    for(int i=0;i<5;i++){
        cin >> x[i];
    }
    cout << "정수를 5개 입력하라. 배열 y에 삽입한다>> ";
    for(int i=0;i<5;i++){
        cin >> y[i];
    }
    cout << "합친 정수 배열을 출력한다.\n";
    int *s = ArrayUtility::concat(x, y, 5);
    for(int i=0;i<10;i++){
        cout << s[i] << ' ';
    }
    cout << endl;
    int ret;
    int *t = ArrayUtility::remove(x, y, 5, ret);
    cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << ret << endl;
    for(int i=0;i<ret;i++){
        cout << t[i] << ' ';
    }
    cout << endl;
    
}