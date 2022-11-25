#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> v;
    while(true){
        double sum = 0;
        cout << "정수를 입력하세요(0을 입력하면 종료)>>";
        cin >> n;
        if(n == 0)
        break;
        v.push_back(n);
        for(int i=0;i<v.size();i++){
            cout << v[i] << ' ';
            sum += v[i];
        }
        cout << "\n";
        cout << "평균 = " << sum/v.size() << endl;
    }
}