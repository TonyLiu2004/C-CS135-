#include <iostream>
using namespace std;

void add(int&, int);
int main(){
    int a1 = 1;
    int b1 = 2;
    cout << a1 << " " << b1 << endl;
    add(a1,b1);
    cout << a1 << " " << b1 << endl;
    return 0;
}

void add(int& a, int b){
    a = a + b;
    cout << a << " " << b << endl;
}