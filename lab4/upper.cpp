//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab4 E

//Enter side length, returns top-right of a square of the requested length
#include <iostream>
using namespace std;
int main(){
    int side;
    int front = 0;
    cin >> side;
    for(int i=side;i>0;i--){
        for(int x=0;x<front;x++){
                cout << " ";
        }
        for(int j=0;j<i;j++){
            cout << "*";
        }
        front+=1;
        cout << endl;
    }
    return 0;
}