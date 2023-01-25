/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab1 Task A

Enter two numbers and it will print the smallest of the two numbers
*/
#include <iostream>
using namespace std;

int main(){
    int num1;
    int num2;
    cout << "Enter the first number: " << endl;
    cin >> num1;
    cout << "Enter the second number: " << endl;
    cin >> num2;

    if(num1 < num2){
        cout << "The smaller of the two is " << num1;
    }
    else if(num2 < num1){
        cout << "The smaller of the two is " << num2;
    }
    else{
        cout << "The numbers are the same";
    }
    return 0;
}