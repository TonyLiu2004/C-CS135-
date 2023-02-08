//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab3 B

//Returns the minimin and maximum storage
//in East basin in 2018 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

int main(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string date;
    string eastSt;
    string eastEl;
    string westSt;
    string westEl;
    float min = 0;
    float max = 0;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if(min==0){
            try{
                min = stof(eastSt);
                max = stof(eastSt);
            }
            catch(...){
                continue;
            }
        }
        if(min > stof(eastSt)){
            min = stof(eastSt);
        }else if(max < stof(eastSt)){
            max = stof(eastSt);
        }
    }        
    cout << "minimum storage in East basin: " << min << " billion gallons" << endl;
    cout << "MAXimum storage in East basin: " << max << " billion gallons" << endl;
    fin.close();
    return 0;
}