<<<<<<< HEAD
//better
=======
//decrypt
>>>>>>> ce06b2c4b5d1085fcc5b6afbf90b9b8b8428cf28
#include <iostream>
using namespace std;

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
string decryptCaesar(string ciphertext, int rshift);
string decryptVigenere(string ciphertext, string rshift);
int main(){
    string input = "Hello, World!";
    int shift = 10;
    /*
    cout << "Enter plaintext: ";
    getline(cin,input);
    cout << "= Caesar =" << endl;
    cout << "Enter shift: ";
    cin >> shift;
    */
    cout << "Ciphertext: " << encryptCaesar(input,shift) << endl;
    cout << "Decrypted: " << decryptCaesar(input,shift) << endl;

    return 0;
}

string decryptCaesar(string input, int shift){
    string ret = "";
    for(char x : input){
        if(!isalpha(x)){
            ret+=x;
        }else{
            //shift reverse
        }
    }
    return ret;
}