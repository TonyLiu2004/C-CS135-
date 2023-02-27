#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAX_WORDS = 1000;
int WORD_COUNT = 0;

string WORDS[MAX_WORDS];
string DEFINITIONS[MAX_WORDS];
string POS[MAX_WORDS];

int getSpace(string a){
    return (a.find(" ", 0)+1);
}

string getFirst(string& a){
    if(a == " "){
        return " ";
    }
    string b = a.substr(0,getSpace(a));
    a = a.substr(getSpace(a),a.length());
    return b;
}

void readWords(string filename){
    ifstream fin(filename);
    string a ="";
    int words = 0;
    //get number of lines from file
    while(getline(fin,a)){
        string b = a;
        string word1 = getFirst(b);
        string word2 = getFirst(b);
        WORDS[words] = word1.substr(0,word1.length()-1); // removes the space at the end
        POS[words] = word2.substr(0,word2.length()-1); // removes the space at the end
        getFirst(b); // removes the : 
        DEFINITIONS[words] = b; 
        words++;
    }
    WORD_COUNT = words;
}
int main(){
    return 0;
}