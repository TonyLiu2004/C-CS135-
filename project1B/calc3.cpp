/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1B Task D

Reads equations (including squaring of numbers) from formula.txt and returns the answer to each equation
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
            //if loop encounters ;, print out the answer and reset all variables for further equations
            if(f[i] == ';'){
                if(i == f.length()-1){
                    break;
                }
                if((next == '!') || (next == '+')){
                    ans += stoi(temp);
                }else if(next == '-'){
                    ans -= stoi(temp);
                }
                cout << ans << endl;
                ans = 0;
                next = '!';
                temp = "";
            }
            //squares number
            if(f[i] == '^'){
                temp = to_string(stoi(temp) * stoi(temp));
            }

            //performs + and - operations
            if(next == '+'){
                ans += stoi(temp);
                temp = "";
                next = '/';
            }else if(next == '-'){
                ans -= stoi(temp);
                temp = "";
                next = '/';
            }

            //sets the next operation to + or -, also adds the first number to sum
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
    
    //deals with loop missing the last number
    if(next == '+'){
        ans +=stoi(temp);
    }else if(next == '-'){
        ans -= stoi(temp);
    }
    
    cout << ans;
    return 0;
}