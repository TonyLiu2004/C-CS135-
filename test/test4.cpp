#include <iostream>
using namespace std;
int main(){
    int *counts[10];
    for(int i =0;i < 10;i++){
        counts[i] = new int[i];

    }
    cout << *counts[1] << " " << *counts[0];
}