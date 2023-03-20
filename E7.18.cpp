/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E7.16

double distance(Point a, Point b) computes the distance from a to b.

The structure Triangle contains three Point members. 
perimeter() calculates the perimeter of a Triangle. 
*/
#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    double x;
    double y;
};

struct Triangle{
    struct Point p1;
    struct Point p2;
    struct Point p3;
};

double distance(Point a, Point b);
double perimeter(Triangle a);
int main(){
    struct Point p1 ={0,2};
    struct Point p2 = {12,9};
    struct Point p3 = {12,0};
    struct Triangle t1 = {p1,p2,p3};
    cout << perimeter(t1);
    return 0;
}


double distance(Point a, Point b){
    return sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2));
}

double perimeter(Triangle a){
    return distance(a.p1,a.p2) + distance(a.p2,a.p3) + distance(a.p1,a.p3);
}
