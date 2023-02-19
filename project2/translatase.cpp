/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project2 B

Reads the DNA strand text file dna2b.txt and outputs the corresponding amino-acid chain 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "transcriptase.cpp"

std::string dictionary_read(std::string);
int main(){
    std::string ret = "";
    std::ifstream fin("dna2b.txt");
    std::string strand;
    while(std::getline(fin, strand)) {
        int t = 0;
        bool start = false;
        for(int i = 0;i < strand.length()/3;i++){
            std::string trans = strand.substr(t,3);
            for (auto & c: trans) c = toupper(c); // converts every letter to uppercase
            std::string codon = dictionary_read(transcriptase(trans));
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
        ret+= "\n";
    }
    fin.close();
    std::cout << ret;
    return 0;
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