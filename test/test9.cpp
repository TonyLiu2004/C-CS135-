#include <iostream>
using namespace std;

void printArr(int* a[], int size){
    for(int i = 0;i<size;i++){
        cout << *(a[i]) << " ";
    }
    cout << "\n";
}

bool larger(int* a, int* b){
    if(*b > *a){
        int* temp = b;
        int* temp2 = a;
        a = temp;
        b = temp2;
        delete temp2;
        delete temp;
        return true;
    }
    return false;
}

int main(){
    int* counts[10];
    for (int i = 0; i < 10; i++)
    {
    counts[i] = new int[i + 1];
    }

    int a = 10;
    int b = 12;
    int* a_ptr = &a;
    int* b_ptr = &b;
    cout << larger(a_ptr,b_ptr) << "\n";
    cout << "a: " << *a_ptr << ", b: " << *b_ptr << "\n";
    cout << "a: " << a << ", b: " << b << "\n";

    int arr[5] = {1,2,3,4,5};
    int barr[4] = {1,2,3,4};

    barr = arr;
    for(int i = 0; i < 4;i++){
        cout << barr[i] << " ";
    }
    return 0;
}