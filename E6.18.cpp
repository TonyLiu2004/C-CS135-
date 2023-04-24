/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E6.18

Write a function vector<int> append(vector<int> a, vector<int> b)   
that appends one vector after another. For example, 
if a is 1 4 9 16 and b is 9 7 4 9 11 then append returns the vector 1 4 9 16 9 7 4 9 11
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b){
    vector<int> ret = a;
    for(int i = 0;i < b.size();i++){
        ret.push_back(b[i]);
    }
    return ret;
}
int main(){
    return 0;
}