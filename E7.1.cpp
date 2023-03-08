/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E7.1

sort2(double* p, double* q) that receives two pointers 
and sorts the values to which they point. 
If you call sort2(&x, &y) then x <= y after the call.
*/
#include <iostream>
using namespace std;
void sort2(double* x, double* y);
int main(){
    double x = 5.7;
    double y = 3.2;
    double* xp = &x;
    double* yp = &y;
    sort2(xp,yp);
    cout << x <<" " << y;
    return 0;
}

void sort2(double* x, double* y){
    if(*x > *y){
        double temp = *y;
        *y = *x;
        *x = temp;
        
    }
}