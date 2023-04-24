//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab12 C
//
//void gogeta(vector<int> &goku, vector<int> &vegeta) appends 
//elements of the second vector into the first and empties the 
//second vector.
#include <iostream>
#include <vector>
using namespace std; 

void gogeta(vector<int> &goku, vector<int> &vegeta){
    for(int i =0;i < vegeta.size();i++){
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
}
int main(){
    vector<int> a = {1,2,3,20};
    vector<int> b = {4,5,6};
    gogeta(a,b);
    for(int i = 0;i < a.size();i++){
        cout << a[i] << " ";
    }
}