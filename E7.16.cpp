/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E7.16

double distance(Point a, Point b) computes the distance from a to b.
*/
#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    double x;
    double y;
};
double distance(Point a, Point b);
int main(){
    struct Point p1;
    p1.x = 1;
    p1.y = 2;
    struct Point p2;
    p2.x = 12;
    p2.y = 20;
    cout << "Point 1: (" << p1.x << ", " << p1.y << ")\n";
    cout << "Point 2: (" << p2.x << ", " << p2.y << ")\n";
    cout << "Distance between Point 1 and Point 2: " << distance(p1,p2) << "\n";
    return 0;
}

double distance(Point a, Point b){
    return sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2));
}