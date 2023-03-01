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
/*
    @param word       :   The string with a new word
    @param definition :   The string with the definition of the
                          new `word`
    @param pos        :   The string with the pos of the new `word`
    @return           :   return `true` if the word is
                          successfully added to the dictionary
                          return `false` if failed (word already
                          exists or dictionary is full)
    @post             :   Add the given `word`, `definition`, `pos`
                          to the end of the respective
                          global-arrays.
                          The word should not be added to the
                          global-arrays if it already exists 
                          or if the array reached maximum 
                          capacity(`g_MAX_WORDS`).
                          Update `g_word_count` if the word is
                          successfully added
*/
bool addWord(string word, string definition, string pos);
/*
    @param word       :   The string with the word that is to
                          be edited
    @param definition :   The string with the new definition of 
                          the `word`
    @param pos        :   The string with the new pos of the `word`
    @return           :   return `true` if the word is successfully
                          edited, return `false` if the `word`
                          doesn't exist in the dictionary
    @post             :   Replace the given `word`'s  definition
                          and pos with the given `definition` and
                          `pos` (by modifying global-arrays
                          `g_definitions` and `g_pos`).
                          The modification will fail if the word
                          doesn't exist in the dictionary
*/
bool editWord(string word, string definition, string pos);

/*
    @param            :   The string with the word that is to
                          be removed
    @return           :   return `true` if the word is successfully
                          removed from the dictionary return `false`
                          if the word doesn't exist in the dictionary
    @post             :   Remove the given `word`, `word`'s
                          definition and `word`'s pos from the
                          respective global-arrays if the word
                          exists.  
                          Update `g_word_count` if the word is
                          successfully removed
*/
bool removeWord(string word);

int getSpace(string a);
string getFirst(string& a);
int countPrefix(string p);
int getIndex(string word);
string lower(string a);
string removeSpace(string a);
void fixSpaces();

int main(){ 
    readWords("dictionary.txt");
    bool test = false;
    if(test)
    {
        cout << "get word index: " << getIndex("WORD") << "\n";
        cout << "get def: " << getDefinition("grumpy") << "\n";
        cout << "get POS: " << getPOS("gRUMPY") << "\n";
        cout << "Count prefix: " << countPrefix("PRo") << "\n";

        cout << addWord("yeet","joy, to throw","verb") << "\n";
        cout << addWord("cookie","a delicous snack","noun") << "\n";
        cout << addWord("noob","a bad player, a beginner","noun") << "\n";

        cout << editWord("cookie","idk what a cookie is :p","noun") << "\n";
        cout << "Word count: " << g_word_count << "\n\n";
        cout << removeWord("cookie") << "\n";
        cout << "Word count: " << g_word_count << "\n\n";

        cout << addWord("yeet","joy, to throw","verb") << "\n";
        cout << addWord("cookie","a delicous snack","noun") << "\n";
        cout << addWord("noob","a bad player, a beginner","noun") << "\n";

        cout << "Stuff in WORDS: "<< "\n";
        for(string x : g_words){
            if(x !=""){
                cout << x << ",";
            }
        }
        cout << "\n\n";

        cout << "Stuff in POS: "<< "\n";
        for(string x : g_pos){
            if(x !=""){
                cout << x << ",";
            }
        }
        cout << "\n\n";

        cout << "Stuff in DEFINITIONS: "<< "\n";
        for(string x : g_definitions){
            if(x !=""){
                cout << x << ",";
            }
        }
    }
    cout << addWord("test1","test1 def","test1pos") << "\n";
    cout << addWord("yeet","joy, to throw","verb") << "\n";
    cout << addWord("cookie","a delicous snack","noun") << "\n";
    cout << addWord("noob","a bad player, a beginner","noun") << "\n";
    cout << addWord("test2","test2 def","test2pos") << "\n";
    cout << "---------------" << endl;
    for(int i = 0;i < g_word_count+1;i++){
        cout << i << " " << g_words[i] << endl;
        cout << i << " " << g_pos[i] << endl;
        cout << i << " " << g_definitions[i] << endl;
    }
    cout << "------------" << endl;
    removeWord("yeet");
    removeWord("Grumpy");
    for(int i = 0;i < g_word_count+1;i++){
        cout << i << " " << g_words[i] << endl;
        cout << i << " " << g_pos[i] << endl;
        cout << i << " " << g_definitions[i] << endl;
    }
    return 0;
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
        if(removeSpace(lower(g_words[i])) == removeSpace(lower(word))){
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

string removeSpace(string a){
    string ret = "";
    for(auto x:a){
        if(x != ' '){
            ret+=x;
        }
    }
    return ret;
}

void fixSpaces(){
    for(int i = 0;i < g_word_count;i++){
        if(g_words[i] == ""){
            for(int x = i; x < g_word_count+1;x++){
                g_words[x] = g_words[x+1];
                g_pos[x] = g_pos[x+1];
                g_definitions[x] = g_definitions[x+1];
            }
        }
    }
}

bool addWord(string word, string definition, string pos){
    fixSpaces();
    if((getIndex(word) == -1)&&(g_word_count < g_MAX_WORDS)){
        fstream file;
        file.open("dictionary.txt",ios::app); // open and append
        file << word << " " << pos << " : " << definition << "\n";
        file.close();
        g_words[g_word_count] = word; // updates all the arrays
        g_definitions[g_word_count] = definition;
        g_pos[g_word_count] = pos;
        g_word_count++;
        fixSpaces();
        //readWords("dictionary.txt"); //re-reads the dictionary file to update everything
        return true;
    }
    return false;
}

bool editWord(string word, string definition, string pos){
    bool ret = false;
    if(getIndex(word) == -1){ // if word does not exist in dictionary, return false
        return false;
    }
    ifstream fin;
    ofstream temp; //makes a temporary file to append to, later on replaces original file with temp
    temp.open("temp.txt");
    fin.open("dictionary.txt");
    string t;
    while(getline(fin,t)){
        string first = removeSpace(lower(getFirst(t))); //first word of dictionary
        if(first != removeSpace(lower(word))){ // if the line does not include the selected word, append to temp
            temp << first << " " << t << "\n";  
        }else if(first == removeSpace(lower(word))){ // if the line includes the selected word, append the changes instead
            temp << word << " " << pos << " : " << definition << "\n";
            ret = true;
            g_pos[getIndex(word)] = pos;
            g_definitions[getIndex(word)] = definition;
            g_word_count++;
        }
    }
    temp.close();
    fin.close();
    remove("dictionary.txt");//removes original file
    rename("temp.txt","dictionary.txt"); // renames temp to dictionary after the changes have been made
    return ret;
}

bool removeWord(string word){
    bool ret = false;
    if(getIndex(removeSpace(lower(word))) == -1){ // if word does not exist in dictionary, return false
        return false;
    }  
    fixSpaces();
    g_pos[getIndex(word)] = "";
    g_definitions[getIndex(word)] = "";
    g_words[getIndex(word)] ="";

    ifstream fin;
    ofstream temp; //makes a temporary file to append to, later on replaces original file with temp
    temp.open("temp.txt");
    fin.open("dictionary.txt");
    string t;
    while(getline(fin,t)){
        string first = removeSpace(lower(getFirst(t))); //first word of dictionary
        if(first != removeSpace(lower(word))){ // if the line does not have the selected word, append to temp
            temp << first << " " << t << "\n"; 
            ret = true; 
        }
    }
    temp.close();
    fin.close();
    remove("dictionary.txt");//removes original file
    rename("temp.txt","dictionary.txt"); // renames temp to dictionary after the changes have been made
    fixSpaces();
    g_word_count--;
    return ret;
}