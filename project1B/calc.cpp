/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1B Task B

Reads equations from formula.txt and returns the answer
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string f = "";
    string c;
    //writes the equation into a string f
    while (cin >> c){
        f = f + c;
    }

    //loops through the string to perform calculations
    int ans = 0;
    string temp = "";
    char next = '!';
    for (int i = 0;i < f.length();i++){
        if(isdigit(f[i]) == false){
            if(next == '+'){
                ans += stoi(temp);
                temp = "";
                next = '/';
            }else if(next == '-'){
                ans -= stoi(temp);
                temp = "";
                next = '/';
            }
            if(f[i] == '+'){
                if(next == '!'){
                    ans += stoi(temp);
                    temp = "";
                }
                next = '+';
            }else if(f[i] == '-'){
                if(next == '!'){
                    ans += stoi(temp);
                    temp = "";
                }
                next = '-';
            }
        }else{
            temp = temp + f[i];
        }
    }
    if(next == '+'){
        ans +=stoi(temp);
    }else if(next == '-'){
        ans -= stoi(temp);
    }
    
    cout << ans;
    return 0;
}