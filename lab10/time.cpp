#include <iostream>
#include <cmath>
using namespace std;

class Time { 
public:
    int h;
    int m;
};

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);


int main(){
    int h1;
    int m1;
    int h2;
    int m2;
    cout << "first time: ";
    cin >> h1 >> m1;
    cout << "second time: ";
    cin >> h2 >> m2;
    Time t1 = {h1,m1};
    Time t2 = {h2,m2};
    cout << minutesSinceMidnight(t1) << endl;
    cout << minutesUntil(t1,t2) << endl;
    return 0;
}

int minutesSinceMidnight(Time time){
    return (time.h * 60) + time.m;
}
int minutesUntil(Time earlier, Time later){
    return (abs(earlier.h - later.h) * 60) + abs(earlier.m - later.m);
}