/**
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project1 A

Reads a text file with words and moves the word itself, 
the part of speech of the word, and the definition into 
three arrays: WORDS, DEFINITIONS, and POS.
**/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Globals
const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in 
                         `WORDS` global array. Returns 
                          -1 if the word is not found
    @post             :   Find the index of given `word` 
                          in the `WORDS` array. Return -1 
                          if word is not in the array
*/
int getIndex(string word);

/*
    @param            :   The string with a query word
    @return           :   Return the string definition of 
                          the word from  `DEFINITIONS` 
                          global array. Return "NOT_FOUND" 
                          if word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`. 
                          Return "NOT_FOUND" otherwise
*/
string getDefinition(string word);

/*
    @param            :   The string with a query word
    @return           :   Return the string part of speech(POS) 
                          from the `POS` global array. Return 
                          "NOT_FOUND" if the word doesn't exist 
                          in the dictionary.
    @post             :   Find the POS of the given `word`. 
                          Return "NOT_FOUND" otherwise.
*/
string getPOS(string word);

/*
    @param            :   The string prefix of a word (the prefix 
                          can be of any length)
    @return           :   Integer number of words found that starts 
                          with the given `prefix`
    @post             :   Count the words that start with the given 
                          `prefix`
*/
int countPrefix(string prefix);
/*
    @param            :   The string with the `filename`
    @post             :   Reads the words, definitions, 
                          POS into the global arrays, 
                          and set the value of `WORD_COUNT` 
                          to the number of words read
*/
void readWords(string filename);
int getSpace(string a);
string getFirst(string& a);
int countPrefix(string p);
int getIndex(string word);
string lower(string a);

/*
int main(){ 
    readWords("text.txt");
    
    cout << "get word index: " << getIndex("WORD") << "\n";
    cout << "get def: " << getDefinition("grumpy") << "\n";
    cout << "get POS: " << getPOS("gRUMPY") << "\n";
    cout << "Count prefix: " << countPrefix("PRo") << "\n";

    cout << "Word count: " << WORD_COUNT << "\n\n";
    cout << "Stuff in WORDS: "<< "\n";
    for(string x : WORDS){
        if(x !=""){
            cout << x << ",";
        }
    }
    cout << "\n\n";

    cout << "Stuff in POS: "<< "\n";
    for(string x : POS){
        if(x !=""){
            cout << x << ",";
        }
    }
    cout << "\n\n";

    cout << "Stuff in DEFINITIONS: "<< "\n";
    for(string x : DEFINITIONS){
        if(x !=""){
            cout << x << ",";
        }
    }
    
    return 0;
}
*/


void readWords(string filename){
    ifstream fin(filename);
    string a ="";
    int words = 0;
    //get number of lines from file
    while(getline(fin,a)){
        string b = a;
        string word1 = getFirst(b);
        string word2 = getFirst(b);
        g_words[words] = word1.substr(0,word1.length()-1); // removes the space at the end
        g_pos[words] = word2.substr(0,word2.length()-1); // removes the space at the end
        getFirst(b); // removes the : 
        g_definitions[words] = b; 
        words++;
    }
    g_word_count = words;
}

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

int getIndex(string word){
    int n = 0;
    for(int i = 0;i < 51;i++){
    //for(string x : WORDS){
        if(lower(g_words[i]) == lower(word)){
            return n;
        }
        n++;
    }
    return -1;
}

string getDefinition(string word){
    if(getIndex(word) == -1){
        return "NOT_FOUND";
    }
    return g_definitions[getIndex(word)];
}

string lower(string a){
    string ret = "";
    for(auto b : a){
        ret+=tolower(b);
    }
    return ret;
}

string getPOS(string a){
    if(getIndex(a) == -1){
        return "NOT_FOUND";
    }
    return g_pos[getIndex(a)];
}

int countPrefix(string p){
    int ret = 0;
    for(int i = 0;i < 51;i++){
        if(lower(p) == lower(g_words[i].substr(0,p.length()))){
            ret+=1;
        }
    }
    return ret;
}