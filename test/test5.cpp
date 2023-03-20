#include <iostream>
using namespace std;

int main(){
    int test[] = {2,45,12,67,89,4,2,0};
    int size = 8;
    for(int i =0;i < size;i++){
        for(int j = i;j < size;j++){
            if(test[i] > test[j]){
                int temp = test[i];
                test[i] = test[j];
                test[j] = temp;
            }
        }
    }
    for(int i =0;i < size;i++){
        cout << test[i] << " ";
    }
    return 0;
}