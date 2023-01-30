/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1B Task A

Reads numbers fron numbers.txt and returns the sum of all numbers
*/
#include <iostream>
using namespace std;
int main(){
    int num;
    int sum = 0;
    while (cin >> num){
        sum += num;
    }
    cout << sum;
    return 0;
}