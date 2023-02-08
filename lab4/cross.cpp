//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab4 C

//Enter size, returns a cross with the requested size
#include <iostream>
using namespace std;


int gap;
int front;
void draw();
int main(){
    int size;
    int height;
    cout << "Input size: ";
    cin >> size;
    if(size%2==0){
        gap = size-2;
    }else{
        gap = size-1;
    }
    front = 0;
    bool reverse = false;
    for(int i=0;i<size;i++){
        if(reverse){
            gap +=2;
            front -=1;
            for(int x=0;x<front;x++){
                cout << " ";
            }
            cout << "*";
            for(int j=0;j<gap;j++){
                cout << " ";
            }
            cout << "*" << endl;
        }else{
            for(int x=0;x<front;x++){
                cout << " ";
            }
            cout << "*";
            for(int j=0;j<gap;j++){
                cout << " ";
            }
            cout << "*" << endl;
            front +=1;
            gap -=2 ;
        }
        if(gap<0){
            reverse =true;
        }
    }
    return 0;
}
    
void draw(){
    for(int x=0;x<front;x++){
        cout << " ";
    }
    cout << "*";
    for(int j=0;j<gap;j++){
        cout << " ";
    }
}