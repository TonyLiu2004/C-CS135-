/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E6.8

Input two arrays and their lengths into equals(), returns true if the two
arrays have the same elements in the same order and false otherwise.    
*/
#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size){
    int t = 0;
    bool ret = true;
    if(a_size != b_size){
        return false;
    }
    if(a_size <=b_size){
        t = a_size;
    }else{
        t = b_size;
    }
    for(int i = 0;i<t;i++){
        if(a[i]!=b[i]){
            ret = false;
        }
    }
    return ret;
}

int main(){
    int a[] = {78,4,13,22,35};
    int b[] = {78,4,13,22};
    cout << equals(a,6,b,6);
    return 0;
}