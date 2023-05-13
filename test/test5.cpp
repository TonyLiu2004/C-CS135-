#include <iostream>
#include <vector>
using namespace std;

void vectorMultiply(vector<double>& v, double factor){
    for(int i = 0;i < v.size();i++){
        v[i] = v[i] * factor;
    }
}

void printVector(vector<double> v){
    for(int i = 0;i < v.size();i++){
        cout << v[i] << "\n";
    }
}
int main(){
    vector <double> stuff = {1,2,3,4,5,6,7,8};
    printVector(stuff);
    
    cout << "------\n";
    vectorMultiply(stuff,2);
    printVector(stuff);
    return 0;
}