//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab4 B

//Enter width and height, returns a checkerboard with the requested size
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
        for(int j =0;j<width;j++){
            if(i%2==1){
                if(j%2==0){
                    cout << " ";
                }else{
                    cout << "*";
                }
            }else{
                if(j%2==0){
                    cout << "*";  
                }else{
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}