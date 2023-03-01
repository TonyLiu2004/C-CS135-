#include <iostream>
#include <string>
using namespace std;

int main(){
    string g_words[10] = {"sw","wq","","w","wes"};
    for(string x : g_words){
        cout << x << endl;
    }
    cout << "--------------" << endl;
    for(int i = 0;i < 5;i++){
        if(g_words[i] == ""){
            for(int x = i; x < 5;x++){
                g_words[x] = g_words[x+1];
            }
        }
    }
    for(string x : g_words){
        cout << x << endl;
    }
    return 0;
}