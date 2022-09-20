#include <iostream>
using namespace std;

class CoffeeMachine{
    int coffee, water, suger;
    public:
    CoffeeMachine(int coffee, int water, int suger);
    void drinkEspresso();
    void show();
    void drinkAmericano();
    void drinkSugarCoffee();
    void fill();
};

CoffeeMachine::CoffeeMachine(int coffee, int water, int suger){
    this->coffee = coffee;
    this->water = water;
    this->suger = suger;
}
void CoffeeMachine::drinkEspresso(){
    water--;
    coffee--;
}
void CoffeeMachine::show(){
    cout << "커피 머신 상태, 커피 : " << coffee << " 물 : " << water << " 설탕 : " << suger << '\n';
}
void CoffeeMachine::drinkAmericano(){
    coffee--;
    water -= 2;
}
void CoffeeMachine::drinkSugarCoffee(){
    coffee--;
    water -= 2;
    suger--;
}
void CoffeeMachine::fill(){
    coffee = 10;
    water = 10;
    suger = 10;
}

int main(){
    CoffeeMachine java(5,10,3);
    java.drinkEspresso();
    java.show();
    java.drinkAmericano();
    java.show();
    java.drinkSugarCoffee();
    java.show();
    java.fill();
    java.show();
}