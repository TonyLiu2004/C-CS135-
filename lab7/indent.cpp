/**
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 7 A 

Reads input from cin and prints each line with proper indents based on curly brackets
**/
#include <iostream>
using namespace std;
int countChar(string line, char c);
int main(){
    cout << countChar("abcdeaa",'a');
    string a;
    while(getline(cin,a)){
        cout << a << endl;
    }
    return 0;
}
int countChar(string line, char c){
    int i = 0;
    for(char x : line){
        if(x == c){
            i++;
        }
    }
    return i;
}