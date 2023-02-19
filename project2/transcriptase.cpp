/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project2 A

Reads the DNA strand text file dna.txt and prints the mRNA counterpart 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "transcriptase.h"

std::string transcriptase(std::string strand){
    std::string ret = "";
    for(char c : strand){
        ret += DNAbase_to_mRNAbase(c);
    }
    return ret;
}

char DNAbase_to_mRNAbase(char c){
    switch(toupper(c)){
        case 'A':
            return 'U';
        case 'T':
            return 'A';
        case 'C':
            return 'G';
        case 'G':
            return 'C';
    }
    return ' ';
}