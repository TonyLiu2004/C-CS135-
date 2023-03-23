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
Time addMinutes(Time time0, int min);


int main(){
    /*
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
    */
    Time t3 = {8,10};
    Time t4 = addMinutes(t3,75); 
    Time t5 = {24,10};
    Time t6 = addMinutes(t5,50);
    cout << t4.h << " " << t4.m << endl;
    cout << t6.h << " " << t6.m << endl;
    return 0;
}

int minutesSinceMidnight(Time time){
    return (time.h * 60) + time.m;
}
int minutesUntil(Time earlier, Time later){
    return (abs(earlier.h - later.h) * 60) + abs(earlier.m - later.m);
}

Time addMinutes(Time time0, int min){
    int minutes = min%60; // 
    int hours = min/60;
    time0.h +=hours;
    time0.m +=minutes;
    if(time0.m == 60){
        time0.m = 0;
        time0.h++;
    }
    if(time0.h == 25){
        time0.h = 0;
    }
    return {time0.h,time0.m};
}