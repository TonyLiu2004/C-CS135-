#include <iostream>
using namespace std;


int main(){
    int h =2;
    int w = 2;
    int list[h][w];
    
    int i=0;
    for(int row =0;row < h;row++){
        for(int col = 0;col < w;col++){
            list[row][col] = i;
            i++;
            cout << list[row][col] << " ";
        }
        cout << endl;
    }


    int list2[h*2][w*2];
    for(int row =0;row < h*2;row++){
        for(int col = 0;col < w*2;col++){
            list2[row][col] = list[row/2][col/2];
            cout << list2[row][col] << " ";
        }
        cout << endl;
    }
    
}