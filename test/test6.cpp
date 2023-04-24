#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> a = {1,2,3};
    for(int i =0;i < a.size()+2;i++){
        cout << a[i] << "\n";
    }
}