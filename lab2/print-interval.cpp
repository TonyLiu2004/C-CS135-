/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab2 Task B

Enter L and U, returns all integers from L to U
*/
#include <iostream>
using namespace std;
int main(){
    int l;
    int u;
    cout << "Please enter L: ";
    cin >> l;
    cout << "Please enter U: ";
    cin >> u;

    for(int i = l; i<u;i++){
        cout << i << " ";
    }
    return 0;
}