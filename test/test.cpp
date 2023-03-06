#include <iostream>
using namespace std;
int main(){
    int list[15] = {1,10,2,20,3,30,4,40,12,120};
    int* p = list;
    cout << *(p+15) << endl;
    cout << *(p+0) << endl;
    *(p+10) = 420;
    cout << "---------------" << endl;
    *p = 0;
    for(int i = 0;i < 16;i++){
        cout << *p << endl;
        p++;
    }
}