//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab3 A

//Enter date in MM/DD/YYYY format, returns the east basin storage for that day.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    string dateInput;
    cout << "Enter date in MM/DD/YYYY format: ";
    cin >> dateInput;
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
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if(date == dateInput){
            cout << "East basin storage: " << eastSt << " billion gallons";
        }
    }
    fin.close();
    return 0;
}