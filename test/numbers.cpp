/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab5

Includes a lot of prime functions
*/
#include <iostream>
using namespace std;

bool isDivisibleBy(int, int);

int main(){
    cout << isDivisibleBy(126,0);
    return 0;
}

bool isDivisibleBy(int n, int d){ //returns true or false based on if n is divisible by d or the other way round
    if(d==0){
        return false;
    }
    if(n%d == 0){
        return true;
    }
    return false;
}
