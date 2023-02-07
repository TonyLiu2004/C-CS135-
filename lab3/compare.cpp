//Author: Tony Liu
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Lab3 C

//Enter starting date and ending date in MM/DD/YYYY format, returns
//the basin that had higher elevation for each date inbetween starting
//and ending date
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

string higher(float east, float west){
    if(east == west){
        return "Equal";
    }else if (east > west){
        return "East";
    }else{
        return "West";
    }
}
int main(){
    string startDate, endDate;
    cout << "Enter start date in MM/DD/YYYY format: ";
    cin >> startDate;
    cout << "Enter end date in MM/DD/YYYY format: ";
    cin >> endDate;
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
    bool comp = false;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if(date == startDate){
            comp = true;
        }
        if(comp){
            cout << date << " " << higher(stof(eastEl),stof(westEl)) << endl;
        }
        if(date == endDate)
        {
            comp = false;
        }
    }
    fin.close();
    return 0;
}