/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: lab6 A

Input string, returns the ascii eqivalent of each letter in the string
*/
#include <iostream>
using namespace std;
int main(){
    string s;
    cout << "Input: ";
    getline(cin, s);
    for(char a : s){
        cout << a << " " << (int)a << endl;
    }
}