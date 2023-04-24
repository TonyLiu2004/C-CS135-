//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab12 D
//
//vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2) 
//returns a vector of integers whose elements are the pairwise 
//sum of the elements from the two vectors passed as arguments. 
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2){
    int index = max(v1.size(),v2.size()); //the larger size() of v1 or v2
    vector<int> ret(index,0); //initializes a vector of size "index" with each value set at 0
    for(int i =0;i < index;i++){
        if(v1.size() > i){ //if i > vector.size(), we go over the number  of elements in the vector so don't add
            ret[i] += v1[i];
        }
        if(v2.size() > i){
            ret[i] += v2[i];
        }
    }
    return ret;
}

int main(){
    vector<int> a = {1,2,3,10,11};
    vector<int> b = {3,2,1};
    vector<int> sum = sumPairWise(a,b);
    for(int i = 0;i < sum.size();i++){
        cout << sum[i] << "\n";
    }
    return 0;
}