#include <iostream>
#include <string>
using namespace std;

string middle(string str){
    if(str.length()%2 ==0){
        return str.substr(str.length()/2 -1,2);
    }else{
        return str.substr(str.length()/2,1);
    }
}
int main(){
    string str;
    cout << "Enter string: ";
    cin >> str;
    cout << middle(str);
}