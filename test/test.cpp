#include <iostream>
#include <string>
using namespace std;

int main(){
    string f = "10+3-3+3+25";
    int ans = 0;
    string temp = "";
    char next = '!';
    for (int i = 0;i < f.length();i++){
        if(isdigit(f[i]) == false){
            if(next == '+'){
                ans += stoi(temp);
                temp = "";
                next = '/';
            }else if(next == '-'){
                ans -= stoi(temp);
                temp = "";
                next = '/';
            }
            if(f[i] == '+'){
                if(next == '!'){
                    ans += stoi(temp);
                    temp = "";
                }
                next = '+';
            }else if(f[i] == '-'){
                if(next == '!'){
                    ans += stoi(temp);
                    temp = "";
                }
                next = '-';
            }
        }else{
            temp = temp + f[i];
        }
    }
    if(next == '+'){
        ans +=stoi(temp);
    }else if(next == '-'){
        ans -= stoi(temp);
    }
    cout << ans;
    return 0;
}