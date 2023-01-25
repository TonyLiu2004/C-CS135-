/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab1 Task B

Enter three numbers and it will print the smallest of the three numbers
*/
#include <iostream>
using namespace std;
int main(){
    int num1;
    int num2;
    int num3;
    cout << "Enter the first number: " << endl;
    cin >> num1;
    cout << "Enter the second number: " << endl;
    cin >> num2;
    cout << "Enter the third number: " << endl;
    cin >> num3;

    int smallest;
    if((num1 < num2) && (num1 < num3)){
        smallest = num1;
    }else if ((num2 < num1) && (num2 < num3)){
        smallest = num2;
    }else if ((num3 < num1) && (num3 < num2)){
        smallest = num3;
    }else{
        smallest = num1; // all nums are same
    }

    cout << "The smaller of the three is " << smallest;
    return 0;
}