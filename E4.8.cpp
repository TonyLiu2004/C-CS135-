//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: E4.8

//Input a string, prints out every letter in the string

#include <iostream>
#include <string>
using namespace std;
int main(){
    string str = "Hello";
    cout << "Enter input: ";
    getline(cin, str);
    for (int i = 0;i < str.length();i++){
        cout << str.substr(i,1) << endl;
    }
    return 0;
}