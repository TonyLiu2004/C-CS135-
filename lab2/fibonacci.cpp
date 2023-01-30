/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab2 Task D

Computes and prints all Fibonacci numbers frm F(0) to F(59)
*/
#include <iostream>
using namespace std;
int main(){
    int fib[60];
    fib[0] = 0;
    fib[1] = 1;
    int len = sizeof(fib)/sizeof(fib[0]);
    for (int i = 2;i < len;i++){
        fib[i] = fib[i-1] + fib[i-2];
        cout << fib[i] << endl; 
    }
    return 0;
}