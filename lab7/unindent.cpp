/**
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 7 A 

Reads input from cin and prints each line with leading spaces removed
**/
#include <iostream>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string);

int main(){
    string a;
    while(getline(cin,a)){
        cout << removeLeadingSpaces(a) << endl;
    }
    return 0;
}

string removeLeadingSpaces(string line){
    string ret = "";
    for(int i = 0;i < line.length();i++){
        if(isspace(line[i])){
            continue;
        }
        else{
            ret = line.substr(i,line.length()-i);
            break;
        }
    }
    return ret;
}