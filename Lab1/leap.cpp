/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab1 Task C

Enter year, returns if the year is a common year or leap year
*/
#include <iostream>
using namespace std;
int main(){
    int year;
    cout << "Enter Year: " << endl;
    cin >> year;
    if (year % 4 != 0 ){
        cout << "Common year";
    } else if(year % 100 != 0){
        cout << "Leap year";    
    } else if(year % 400 != 0){
        cout << "Common year";
    } else {
        cout << "Leap year";
    }
    return 0;
}