#include <iostream>
//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab4 C

//Enter size, returns a cross with the requested size
#include <string>
using namespace std;
int main(){
    int size;
    cin >> size;
    if(size == 1){
        cout << "*";
        return 0;
    }
    for(int x = 0;x < size;x++){
        for(int y = 0;y<size;y++){
            if(x==y || y ==(size-1-x)){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}