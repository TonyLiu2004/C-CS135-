/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab1 Task D

Enter year and month, returns how many days are in that month. Includes leap years.
*/
#include <iostream>
using namespace std;

bool isLeap(int year);
int main(){
    int year;
    int month;
    cout << "Enter year: " << endl;
    cin >> year;
    cout << "Enter month: " << endl;
    cin >> month;

    if((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)){
        cout << "31 Days";
    }else if(month == 2){
        if(isLeap(year)){
            cout << "29 Days";
        }else{
            cout << "28 Days";
        }
    }else{
        cout << "30 Days";
    }
    return 0;
}

bool isLeap(int year){
    if (year % 4 != 0 ){
        return false;
    } else if(year % 100 != 0){
        return true;  
    } else if(year % 400 != 0){
        return false;
    } else {
        return true;
    }
}