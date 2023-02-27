/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E5.14

The function middle() takes a string as an input and returns the middle 
letters.
*/
#include <iostream>
#include <string>
using namespace std;

string middle(string str){
    if(str.length()%2 ==0){
        return str.substr(str.length()/2 -1,2);
    }else{
        return str.substr(str.length()/2,1);
    }
    return "";
}
int main(){
    string str;
    cout << "Enter string: ";
    cin >> str;
    cout << middle(str);
    return 0;
}