//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab4 D

//Enter size length, returns a triangle with the requested side length
#include <iostream>
using namespace std;
int main(){
    int side;
    int num=1;
    cin >> side;
    for(int i=side;i>0;i--){
        for(int j=0;j<num;j++){
            cout << "*";
        }
        num+=1;
        cout << endl;
    }
    return 0;
}