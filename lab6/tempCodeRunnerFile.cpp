#include <iostream>
using namespace std;

char shiftChar(char c, int rshift);
string encryptVigenere(string plaintext, string keyword);

int main(){
    cout << encryptVigenere("Hello, World!","CaKe") << endl;
    return 0;
}

char shiftChar(char c, int rshift){
    char ret = c;
    if(!isalpha(c)){
        return c;
    }
    for(int i = 0;i < rshift;i++){
        if(ret == 'z'){
            ret = 'a';
        }else if(ret == 'Z'){
            ret = 'A';
        }else{
            ret+=1;
        }
    }
    return ret;
}

string encryptVigenere(string plaintext, string keyword){
    string ret = "";
    int z = 0;
    for(int i = 0;i < plaintext.length();i++){
        if(!isalpha(plaintext[i])){ // if not a letter, append to ret and skip the rest so keyword index doesn't update
            ret+=plaintext[i];
            continue;
        }
        if(z > keyword.length()-1){ //resets the indexing for keyword
            z = 0;
        }
        int position = tolower(keyword[z]) - 'a'; // position in alphabet
        z++;
        ret+=shiftChar(plaintext[i],position);
    }
    return ret;
}