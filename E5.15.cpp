#include <iostream>

void sort2(int&, int&);
void sort3(int&, int&, int&);
int main(){
    int a = 3;
    int b = 2;
    int c = 12;
    sort3(a,b,c);
    std::cout << a << " " << b << " " << c << "\n";
    return 0;
}

void sort2(int& a, int& b){
    if(a>b){
        int t = a;
        a = b;
        b = t;
    }
}

void sort3(int& a, int& b, int& c){
    sort2(a,b);
    sort2(b,c);
    sort2(a,b);
}