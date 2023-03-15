#include <iostream>
#include <cmath>
using namespace std;

int func(int a, int b, int c, int d, int e, int f, int g, int h, int i){
    /**
    if(a > 255){
        a = 255;
    }
    if(b > 255){
        b = 255;
    }
    if(c > 255){
        c = 255;
    }
    if(d > 255){
        d = 255;
    }
    if(e > 255){
        e = 255;
    }
    if(f > 255){
        f = 255;
    }
    if(g > 255){
        g = 255;
    }
    if(h > 255){
        h = 255;
    }
    if(i > 255){
        i = 255;
    }
    **/
    if(a > 255){
        a = 0;
    }
    if(b > 255){
        b = 0;
    }
    if(c > 255){
        c = 0;
    }
    if(d > 255){
        d = 0;
    }
    if(e > 255){
        e = 0;
    }
    if(f > 255){
        f = 0;
    }
    if(g > 255){
        g = 0;
    }
    if(h > 255){
        h = 0;
    }
    if(i > 255){
        i = 0;
    }
    return ((g+(2*h)+i)-(a+(2*b)+c));
}

int main(){
    int r = 3;
    int c = 3;
    int img[r][c] = {{6,12,18},
                   {11,22,33},
                   {15,30,45}};
    for(int row =0;row < r;row++){
        for(int col = 0;col < c;col++){
            int f = func(img[row][col],img[row][col+1],img[row][col+2],img[row+1][col],img[row+1][col+1],img[row+1][col+2],img[row+2][col],img[row+2][col+1],img[row+2][col+2]);
            cout << img[row][col] << endl;
            cout << img[row][col+1] << endl;
            cout << img[row][col+2] << endl;
            cout << img[row+1][col] << endl;
            cout <<endl <<endl;
            /*if(f < 0){
                f = 0;
            }else if(f > 255){
                f = 255;
            }*/
            cout << f << " ";
        }
        cout << endl;
    }
    cout << img[4][5];
    return 0;
}