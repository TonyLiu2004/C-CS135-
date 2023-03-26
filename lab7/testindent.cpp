/**
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 7 B 

Reads input from cin and prints each line with proper indents based on curly brackets
**/
#include <iostream>
#include <fstream>
using namespace std;

string removeLeadingSpaces(string);
int countChar(string line, char c);

int main(){
    int open_brackets = 0;
    string a;
    ifstream myfile;
    myfile.open ("test.txt");
    string str;
  int indents = 0;
  while(getline(myfile, str)){ //read cin
    bool close = false;
    string line = removeLeadingSpaces(str); 
    if (line[0] == '}'){ //if its close bracket, then indents -1
      indents--;
      close = true;
    }
    for (int i = 0; i < indents; i++){
      cout << "\t"; //indent how many indents there are
    }
    cout << line << endl;

    indents += countChar(str, '{'); //if its open bracket + 1 prob
    if(!(close)){
      indents -= countChar(str,'}');
    }
        cout  << indents;
  }
  return 0;
}
int countChar(string line, char c){
    int i = 0;
    for(char x : line){
        if(x == c){
            i++;
        }
    }
    return i;
}

string removeLeadingSpaces(string line){
    string ret = "";
    for(int i = 0;i < line.length();i++){
        if(isspace(line[i])){
            continue;
        }
        else{
            ret = line.substr(i,line.length()-i);
            break;
        }
    }
    return ret;
}