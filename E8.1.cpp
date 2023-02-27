/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E8.1

Opens a file hello.txt with the message “Hello, World!” then closes and 
opens the same file again. It then reads the message into a string variable 
and prints it.  
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream file;
    file.open("hello.txt");
    file << "Hello, World!" << "\n";
    file.close();

    file.open("hello.txt");
    string a;
    getline(file,a);
    
    cout << a << "\n";
    file.close();
    return 0;
}