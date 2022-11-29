#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    cout << setw(15) << left << "Number";
    cout << setw(15) << left << "Square";
    cout << setw(15) << left << "Square Root" << endl;

    for(int i=0;i<=45;i += 5){
        cout << setw(15) << setfill('_') << i;
        cout << setw(15) << setfill('_') << i*i;
        cout << setw(15) << setfill('_') << setprecision(3) << sqrt(i) << endl;
    }
}