#include <iostream>
using namespace std;

class fruit{
    protected:
        string color;
        string name;
        int calories;
    public:
        fruit();
        fruit(string name, string color, int calories);
        void printFruit();
        int getCalories();
        string getColor();
        string getName();
};

fruit::fruit(){
    calories = 0;
    color = "Undefined";
}

fruit::fruit(string name, string color, int calories){
    this->name = name;
    this->color = color;
    this->calories = calories;
}

void fruit::printFruit(){
    cout << name << ": " << color << ", " << calories << " calories.\n";
}

int fruit::getCalories(){
    return calories;
}

string fruit::getColor(){
    return color;
}

string fruit::getName(){
    return name;
}
//-----------------------banana------------------------------------
class banana : public fruit{
    private:
        int potassium;
    public:
        banana();
        banana(int calories, int potassium);
        int getPotassium();
        void printFruit();
};

banana::banana(){
    potassium = 0;
}

banana::banana(int calories, int potassium){
    this->name = "banana";
    this->color = "yellow";
    this->calories = calories;
    this->potassium = potassium;
}

int banana::getPotassium(){
    return potassium;
}

void banana::printFruit(){
    cout << name << ": " << color << ", " << calories << " calories, " << potassium << " potassium.\n";
}

int main(){
    fruit apple("apple","red",100);
    apple.printFruit();
    
    banana b1(120,69);
    b1.printFruit();
    return 0;
}