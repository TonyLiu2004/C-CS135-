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
int main(){
    std::ifstream fin("dna.txt");
    if (fin.fail()) {
        std::cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }
    std::string strand;
    while(std::getline(fin, strand)) {
        for(char c : strand){
            switch(c){
                case 'A':
                    std::cout << "U";
                    break;
                case 'T':
                    std::cout << "A";
                    break;
                case 'C':
                    std::cout << "G";
                    break;
                case 'G':
                    std::cout << "C";
                    break;
                default:
                    std::cout << " ";
                    break;
            }
        }
        std::cout << "\n";
    }
    fin.close();
    return 0;
}