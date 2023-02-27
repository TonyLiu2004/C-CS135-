#include <iostream>
using namespace std;
int main(){ 
    int n = 21;
    string ret = "";
    int front = 0;
    int colons = 0;
    for(int i = 0;i <= n/2;i++){
        if(i==0){
            colons = n;
            ret+="|";
            for(int x = 0; x <n+2;x++){
                ret+="\"";
            }
            ret+="|\n";
            front++;
        }
        for(int f = 0;f<front;f++){
            ret+=" ";
        }
        ret +="\\";
        for(int j = 0;j <colons;j++){
            ret +=":";
        }
        ret +="/\n";
        colons-=2;
        front+=1;
        if(colons < 2){
            for(int s = 0;s < front;s++){
                ret+=" ";
            }
            if(n%2 ==2){
                ret+="||";
            }else{
                ret+="|||";
            }
            ret+="\n";
            front-=1;
            colons+=2;
            break;
        }
    }

    //second half
    for(int i = 0;i <=n/2;i++){
        if(i==n/2){
            ret+="|";
            for(int x = 0;x<n+2;x++){
                ret+="\"";
            }
            ret+="|";
        }else{
            for(int y = 0;y < front;y++){
                ret+=" ";
            }
            ret+="/";
            for(int z = 0;z < colons;z++){
                ret+=":";
            }
            ret+="\\\n";
        }
        colons+=2;
        front-=1;
    }
    cout << ret;
    return 0;
}