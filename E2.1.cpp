/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E2.10

Enter gallons, fuel efficiency, and price. Returns cost per 100 miles and how many miles the car can go
*/
#include <iostream>
using namespace std;
int main(){
    double gallons;
    double fuelEff;
    double price;

    cout << "Enter gallons of gas in tank: " << endl;
    cin >> gallons;
    cout << "Enter fuel efficiency: " << endl;
    cin >> fuelEff;
    cout << "Enter price per gallon: " << endl;
    cin >> price;

    double total = (100/fuelEff) * price;
    cout << "The cost per 100 miles is $" << total << endl;
    cout << "The car can go " << fuelEff * gallons << " miles" << endl;

    return 0;
}