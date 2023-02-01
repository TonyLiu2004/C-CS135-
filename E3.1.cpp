/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E3.1

Input a number, code prints whether the number is positive, zero, or negative
*/
#include <iostream>
using namespace std;
int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if(num == 0){
        cout << "zero";
    }else if(num > 0){
        cout << "positive";
    }else{
        cout << "negative";
    }
    return 0;
}