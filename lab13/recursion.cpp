/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab13

Recursion lab
*/
#include <iostream>
using namespace std;

//Prints all numbers from range left to right
void printRange(int left, int right){
    if(left <= right){
        cout << left << " ";
        printRange(left+1,right);
    }
}

//computes the sum of all numbers in range
int sumRange(int left, int right){
    if(left > right){ // base case
        return 0;
    }
    return left + sumRange(left+1,right);
}

int sumArray(int *arr, int size){
    if(size<1){
        return 0;
    }
    return arr[size-1] + sumArray(arr,size-1);
}

bool isAlphanumeric(string s){
    if(s.length() > 0){
        if(iswalnum(s[0])){
            if(!isAlphanumeric(s.substr(1,s.length()-1))){
                return false;
            }
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    //Task A
    cout << "Print Range: ";
    printRange(-2,10);
    cout << "\n-----------\n";

    //Task B
    cout << "sum of range: ";
    int x = sumRange(1, 3);
    int y = sumRange(-2, 10);
    cout << x << " " << y;
    cout << "\n------------\n";

    //Task C
    cout << "sum array: \n";
    int *arr = new int[10];
    arr[0] = 12;
    arr[1] = 17;
    arr[2] = -5;
    arr[3] = 3;
    arr[4] = 7;
    arr[5] = -15;
    arr[6] = 27;
    arr[7] = 5;
    arr[8] = 13;
    arr[9] = -21;
    cout << sumArray(arr,10) << "\n"; //43
    cout << sumArray(arr, 5) << "\n"; // sum of first 5, 34
    cout << "-----------------\n";

    //Task D
    cout << "Is alpha: ";
    cout << isAlphanumeric("hello@123") << "\n";
    cout << isAlphanumeric("hello123") << "\n";
    return 0;
}