#include <iostream>
using namespace std;

int Rsum(int a, int b){
    if(a==b){
        return a;
    }
    return a + Rsum(a+1,b);
}

void pTri(int a){
    if(a==0){
        return;
    }
    for(int i = 0;i < a;i++){
        cout << "[]";
    }
    cout <<"\n";
    pTri(a-1);
}

void pTri2(int a){
    if(a==0){
        return;
    }
    pTri2(a-1);
    for(int i = 0;i < a;i++){
        cout << "[]";
    }
    cout << "\n";
}

int main(){
    cout << Rsum(1,3) << "\n";
    pTri(4);
    cout << "\n";
    pTri2(4);
}