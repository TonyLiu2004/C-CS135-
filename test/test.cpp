#include <iostream>
#include <string>
using namespace std;

int main(){

    int temp[10];
    int n = ((sizeof(temp)/sizeof(int)));
    std::cout << n << "\n";
    for(int i = 0;i < n;i++){
        std::cout << i << "\n";
        temp[i] = 0;
        temp[i+1] = 1;
        temp[i+2] = 2;
    }
    for(int i : temp){
        std::cout << i;
    }
   return 0;
}