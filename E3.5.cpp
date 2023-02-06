/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E3.5

Input three numbers, returns increasing if the number is in 
increasing order and decreasing if the numbers are in decreasing order. 
returns neither if otherwise
*/
#include <iostream>
using namespace std;
int main(){
    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    if((num3 > num2) && (num2 > num1)){
        cout << "increasing";
    }else if((num3 < num2) && (num2 < num1)){
        cout << "decreasing";
    }else{
        cout << "neither";
    }
    return 0;
}