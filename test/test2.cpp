#include <iostream>
using namespace std;
int main(){
    int l[] = {12,16,10,9,8,7};
    int* p = l;
    *p++;
    for(int i =0;i < 10;i++){
        cout << i << endl;
    }
    cout << *p << endl;
}