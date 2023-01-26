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

    cout << "Your favorite food is: " << favFood << endl;
    cout << "Your favorite movie is: " << favMovie << endl;
    cout << "Your favorite game is: " << favGame << endl;
    return 0;
}