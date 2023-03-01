/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: lab6 B

encryptCaesar(string plaintext, int rshift) caesar shifts each letter 
in plaintext by rshift and returns the shifted string.
*/
#include <iostream>
using namespace std;

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift);

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift);

int main(){
    cout << shiftChar('W',5) << endl;
    cout << encryptCaesar("Way to Go!", 5) << endl;
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

string encryptCaesar(string plaintext, int rshift){
    string ret = "";
    for(char x : plaintext){
        ret+=shiftChar(x,rshift);
    }
    return ret;
}