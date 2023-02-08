//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab4 A

//Enter width and height, returns a box with the requested size
#include <iostream>
using namespace std;
int main(){
    int width;
    int height;
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;
    for(int i=0;i<height;i++){
        for(int i =0;i<width;i++){
            cout << "*";  
        }
        cout << endl;
    }
    return 0;
}