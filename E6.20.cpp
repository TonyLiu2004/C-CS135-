/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E6.20

Write a function vector<int> merge_sorted(vector<int> a, vector<int> b)   
that merges two sorted vectors, producing a new sorted vector. Keep an 
index into each vector, indicating how much of it has been processed 
already. Each time, append the smallest unprocessed element from either
vector, then advance the index. For example, if   a   is   1 4 9 16   
and    b   is   4 7 9 9 11   then   merge_sorted   returns the 
vector   1 4 4 7 9 9 9 11 16
*/

#include <iostream>
#include <vector>
using namespace std;
void mergeSort(vector<int>&left, vector<int>& right, vector<int>& v)
{
    int leftSize = left.size();
    int rightSize = right.size();
    int i = 0, j = 0, k = 0;

    while (j < leftSize && k < rightSize) 
    {
        if (left[j] < right[k]) {
            v[i] = left[j];
            j++;
        }
        else {
            v[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < leftSize) {
        v[i] = left[j];
        j++; i++;
    }
    while (k < rightSize) {
        v[i] = right[k];
        k++; i++;
    }
}

void sort(vector<int> & v){
    if(v.size()<=1){
        return;
    }

    int mid = v.size()/2;
    vector<int>l;
    vector<int>r;

    for(int i =0;i < mid;i++){
        l.push_back(v[i]);
    }
    for(int i = mid;i < v.size();i++){
        r.push_back(v[i]);
    }
    sort(l);
    sort(r);
    mergeSort(l,r,v);
}
vector<int> merge_sorted(vector<int> a, vector<int> b){
    vector<int> sorted;
    for(int i =0;i < a.size();i++){
        sorted.push_back(a[i]);
    }
    for(int i =0;i < b.size();i++){
        sorted.push_back(b[i]);
    }
    sort(a);
    sort(b);
    mergeSort(a,b,sorted);
    return sorted;
}

int main(){
    vector<int> a = {1,10,23,3,5,12,9,2,5,1};
    vector<int> b = {44,42,41,43,44,45,49,47,48,46};
    vector<int> sort = merge_sorted(a,b);
    for(int i = 0;i < sort.size();i++){
        cout << sort[i] << endl;
    }
    return 0;
}