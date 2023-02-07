//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab3 D

//Enter earlier date and later date in MM/DD/YYYY format, 
//returns the west basin elevation for all days in the interval
//in reverse order (starting at the later date)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>
using namespace std;

int main(){
    string earlierD;
    string laterD;
    cout << "Enter earlier date in MM/DD/YYYY format: ";
    cin >> earlierD;
    cout << "Entere later date in MM/DD/YYYY format: ";
    cin >> laterD;
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
    vector<string> dates;
    vector<string> elevation;
    bool rec = false;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if(date == earlierD){
            dates.push_back(date);
            elevation.push_back(westEl);
            rec = true;
        }
        if(rec){
            dates.push_back(date);
            elevation.push_back(westEl);
        }
        if(date == laterD){
            rec = false;
        }
    }
    fin.close();
    for(int i = dates.size()-1; i >0; i--){
        cout << dates[i] << " " << elevation[i] << " ft" << endl;
    }
    return 0;
}