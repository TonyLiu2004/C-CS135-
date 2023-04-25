//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab12 A
// 
//vector<int> makeVector(int n) that returns a vector of n integers 
//that range from 0 to n-1.
//
//
#include <iostream>
#include <vector>
using namespace std;

    vector<int> makeVector(int n){
        vector<int> ret = {};
        for(int i = 0;i < n;i++){
            ret.push_back(i);
        }
        return ret;
    }
int main(){
    vector<int> a = makeVector(10);
    for(int i = 0;i < a.size();i++){
        cout << a[i] << endl;
    }
    return 0;
}
