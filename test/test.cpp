#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void sort(int a[],int b);

int main(){
    ifstream fin("text.txt");
    if(fin.fail()){
        cout << "file cannot be opened";
        exit(1);
    }
    string a;
    while(fin >> a){
        cout << a << endl;
    }
    cout << "------------------" << endl;
    int l[] = {12,3,4,6,6,71,3,4,56,7,2,0};
    int track = 0;
    for(auto b : l){
        track++;
    }
    sort(l,track);
    for (int a : l){
        cout << a << endl;
    }
   return 0;
}

void sort(int a[], int b){
    for(int i = 0;i < b;i++){
        for(int x = i;x < b;x++){
            if(a[x] < a[i]){
                int t = a[i];
                a[i] = a[x];
                a[x] = t;
            }
        }
    }
}