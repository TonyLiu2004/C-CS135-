/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LabB Task A

Enter integer between 0 and 100, reruns until condition is met. Returns number squared when a valid input is entered.
*/
#include <iostream>
using namespace std;
int main(){
    int num = -1;
    cout << "Enter an integer between 0 and 100: ";
    cin >> num;
    while( !((num>0) && (num < 100))){
        cout << "Re-enter an integer between 0 and 100: ";
        cin >> num;
    }
    cout << "Number squared is " << num*num << endl;
    return 0;
}