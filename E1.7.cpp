/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E1.7

Answer three questions, code will print what you answered in 3 seperate lines
*/
#include <iostream>
using namespace std;
int main(){
    string favFood;
    string favMovie;
    string favGame;
    cout << "What is your favorite food?" << endl;
    cin >> favFood;
    cout << "What is your favorite movie?" << endl;
    cin >> favMovie;
    cout << "What is your favorite game?" << endl;
    cin >> favGame;

    cout << favFood << endl;
    cout << favMovie << endl;
    cout << favGame << endl;
    return 0;
}