//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab4 F

//Enter width and height, returns an upsidedown trapezoid with the requested 
//width and length
#include <iostream>
using namespace std;
int main(){
    int width;
    int height;
    cin >> width >> height;
    if(((height-1)*2) > (width-1)){
        cout << "Impossible shape!";
        return 0;
    }

    int front = 0;
    for(int i=0;i<height;i++){
        for(int l = 0;l<front;l++){
            cout << " ";
        }
        for(int j =0;j<width;j++){
            cout << "*";  
        }
        cout << endl;
        front +=1;
        width -=2;
    }
    return 0;
}