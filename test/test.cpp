#include <iostream>
#include <string>
using namespace std;

int main(){
    string f = "15;10+3+0+25;5+6-7-8+9+10-11;4^+2^;";
    int ans = 0;
    string temp = "";
    char next = '!';
    for (int i = 0;i < f.length();i++){
        if(isdigit(f[i]) == false){
            if(f[i] == ';'){
                if(i == f.length()-1){
                    break;
                }
                if((next == '!') || (next == '+')){
                    ans += stoi(temp);
                }else if(next == '-'){
                    ans -= stoi(temp);
                }
                cout << ans << endl;
                ans = 0;
                next = '!';
                temp = "";
            }
            if(f[i] == '^'){
                temp = to_string(stoi(temp) * stoi(temp));
            }
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