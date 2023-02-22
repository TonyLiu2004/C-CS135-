#include <iostream>

void sort2(int&, int&);
int main(){
    int u = 2;
    int v = 3;
    int w = 4;
    int x = 1;
    
    sort2(u,v);
    std::cout << u << " " << v << "\n";
    sort2(w,x);
    std::cout << w << " " << x << "\n";
    return 0;
}

void sort2(int& a, int& b){
    if(a>b){
        int t = a;
        a = b;
        b = t;
    }
}