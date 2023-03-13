#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int h =4;
    int w = 4;
    int list[h][w];
    
    int i=10;
    for(int row =0;row < h;row++){
        for(int col = 0;col < w;col++){
            list[row][col] = i;
            i+=10;
            cout << list[row][col] << " ";
        }
        i+=1;
        i-=40;
        cout << endl;
    }

    int list2[h][w];
    for(int row =0;row < h;row+=2){
        for(int col = 0;col < w;col+=2){
            int rounded = round((list[row][col] + list[row+1][col] + list[row][col+1] + list[row+1][col+1])/4 +0.5);
            list2[row][col] = rounded;
            list2[row+1][col] = rounded;
            list2[row][col+1] = rounded;
            list2[row+1][col+1] = rounded;
        }
    }
    cout << "----------------------" << endl;
    for(int row = 0;row < h;row++){
        for(int col = 0;col < w;col++){
            cout << list2[row][col] << " ";
        }
        cout << endl;
    }

}