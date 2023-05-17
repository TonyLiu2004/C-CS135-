#include <iostream>
using namespace std;


void pTriangle(int length){
    int spaces = length-1;
    for(int i = 1;i <= length;i++){
        for(int j = 0;j < spaces;j++){
            cout << " ";
        }
        for(int k = 0;k < i;k++){
            cout << "*";
        }
        cout << "\n";
        spaces--;
    }
}

int main(){
    pTriangle(6);
    return 0;
}