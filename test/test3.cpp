#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int r = 3;
    int c = 3;
    int a[r][c] = {{1,2,3},
                   {4,5,6},
                   {7,8,9}};
    for(int row =0;row < r;row+=3){
        for(int col = 0;col < c;col+=3){
            //for {{a,b,c},{d,e,f},{g,h,i}} , f(a,b,c,d,e,f,g,h,i) = (g+2h+i)-(a+2b+c) ==> Edge Detection
            cout << (a[row+2][col] + (2*a[row+2][col+1]) + a[row+2][col+2]) - (a[row][col] + (2 * a[row][col+1] + a[row][col+2]));
        }
        cout << endl;
    }
    return 0;
}