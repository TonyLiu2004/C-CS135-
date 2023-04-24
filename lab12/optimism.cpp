//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab12 B
//
//vector<int> goodVibes(const vector<int>& v); 
//given a vector of integers, returns a vector with 
//only the positive integers in the same order.
#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(const vector<int> v){
    vector<int> ret = {};
    for(int i =0;i < v.size();i++){
        if(v[i]>0){
            ret.push_back(v[i]);
        }
    }
    return ret;
}
int main(){
    vector<int> a = {-1,-2,3,4,-5,-6,7};
    vector<int> b = goodVibes(a);
    for(int i =0;i < b.size();i++){
        cout << b[i] << "\n";
    }
}