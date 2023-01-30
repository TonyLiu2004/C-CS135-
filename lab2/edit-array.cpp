/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab2 Task C

Enter index and value to update an array of length 10. If index is out of range, exit.
*/
#include <iostream>
using namespace std;
int main(){
    int myData[10];
    int len = sizeof(myData)/sizeof(myData[0]);
    for(int i = 0; i < len;i++){
        myData[i] = 1;
        cout << myData[i] << " ";
    }
    cout << endl;
    int i = -1;
    int v;
    while (true){
        cout << "Input index: ";
        cin >> i;
        if((i < 0) || (i > 9)){
            cout << "Index out of range. Exit.";
            exit(1);
        }
        cout << "Input value: ";
        cin >> v;
        myData[i] = v;
        for(int i = 0; i < len;i++){
            cout << myData[i] << " ";
        }
        cout << endl;
    }
    return 0;
}