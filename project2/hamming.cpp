/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project2 C

Reads two strings of equal length and returns the hamming distance followed by a yes or no 
depending on if the difference changes the protein structure 
*/
#include <iostream>
#include <fstream>
#include <string>
#include "transcriptase.cpp"

std::string translate(std::string);
std::string Hamming(std::string, std::string);
std::string dictionary_read(std::string);

int main(){
    std::string ret = "";
    std::ifstream fin("mutations.txt");
    std::string strand = "";
    int n = 1;
    std::string temp = "";
    while(std::getline(fin, strand)){
        if(temp == ""){
            temp = strand;
        }else{
            ret+=Hamming(strand,temp);
            if(translate(strand) == translate(temp)){
                ret += " no"; // no change in structure
            }else{
                ret += " yes"; // change in structure
            }
            temp = "";
        }
        ret+="\n";
    }
    std::cout << ret;
    fin.close();
    return 0;
}

std::string Hamming(std::string a, std::string b){
    int ham = 0;
    for(int i=0;i<a.length();i++){
        if(a.substr(i,1) != b.substr(i,1)){
            ham+=1;
        }
    }
    return std::to_string(ham);
}

std::string translate(std::string a){
    std::string ret = "";
    bool start = false;
    int t = 0;
    for(int i = 0;i < a.length()/3;i++){
        std::string transA = a.substr(t,3);
        for (auto & c: transA) c = toupper(c); // converts every letter to uppercase
        std::string codon = dictionary_read(transcriptase(transA));
        if(codon == "Met"){
            start = true;
        }
        if(codon == "Stop"){
            ret = ret.substr(0,ret.length()-1); // removes last "-"
            ret+= "\n";
            start = false;
        }
        if(start){
            ret += codon+"-";
        }
        t+=3;
    }
    return ret;
}

std::string dictionary_read(std::string codon) {
    std::ifstream dict("codons.tsv");
    std::string key, value;
    dict.clear(); // reset error state
    dict.seekg(0); // return file pointer to the beginning
    while (dict >> key >> value) {
        if(codon == key){      
            return value;
        }
    }
}