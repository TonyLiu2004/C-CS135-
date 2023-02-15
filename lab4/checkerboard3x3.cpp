//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab4 G

//Enter width and height, returns a 3x3 checkerboard with the requested size
#include <iostream>
using namespace std;
int main(){
    int width;
    int height;
    cin >> width >> height;

    bool alt = false;
    for(int i=1;i<height+1;i++){
        if(alt){ //for alternate rows
            cout << "   ";
        }
        //prints the squares
        bool pSpace = false;
        for(int j =0;j<width;j++){
            if(j%6==0){
                pSpace = false;
            }else if(j%3==0){
                pSpace = true;
            }
            if(pSpace){
                cout << " ";
            }else{
                cout << "*";  
            }
        }

        //checkerboard mechanics
        if(i%6==0){
            alt = false;
            width +=3;
        }else if(i%3==0){
            alt = true;
            width -=3;
        }
        cout << endl;
    }
    return 0;
}