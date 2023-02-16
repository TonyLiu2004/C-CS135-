/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab5

Includes a lot of prime functions
*/
#include <iostream>
using namespace std;

bool isDivisibleBy(int, int);
bool isPrime(int);
int nextPrime(int);
int countPrimes(int, int);
bool isTwinPrime(int);
int nextTwinPrime(int);
int largestTwinPrime(int, int);

int main(){
    cout << "isDivisibleBy: " << "\n";
    cout << isDivisibleBy(10,5) << "\n";
    cout << isDivisibleBy(20,3) << "\n";

    cout << "\n" << "isPrime: " << "\n";
    cout << isPrime(41) << "\n";
    cout << isPrime(40) << "\n";

    cout << "\n" << "nextPrime: " << "\n";
    cout << nextPrime(7) << "\n";
    cout << nextPrime(14) << "\n";
    
    cout << "\n" << "countPrimes: " << "\n";
    cout << countPrimes(10,20) << "\n";
    cout << countPrimes(20,30) << "\n";

    cout << "\n" << "isTwinPrime: " << "\n";
    cout << isTwinPrime(17) << "\n";
    cout << isTwinPrime(31) << "\n";
    cout << isTwinPrime(21) << "\n";

    cout << "\n" << "nextTwinPrime" << "\n";
    cout << nextTwinPrime(10) << "\n";
    cout << nextTwinPrime(20) << "\n";

    cout << "\n" << "largestTwinPrime" << "\n";
    cout << largestTwinPrime(5,18) << "\n";
    cout << largestTwinPrime(1,31) << "\n";
    cout << largestTwinPrime(14,16) << "\n";

    return 0;
}

//Input integers n and d, returns true if n is divisible by d and false otherwise
bool isDivisibleBy(int n, int d){
    if(n%d == 0 || d%n ==0){
        return true;
    }
    return false;
}

//Input integer n, returns true if n is prime and false otherwise
bool isPrime(int n){
    for(int i =2;i <n-1;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

//Input integer n, returns the next prime number greater than n
int nextPrime(int n){
    int temp = n;
    while(true){
        temp++;
        if(isPrime(temp)){
            return temp;
        }
    }
    return -1;
}

//input integers a and b, returns the number of primes found between a and b
int countPrimes(int a, int b){
    int count = 0;
    for(int i = a;i<b;i++){
        if(isPrime(i)){
            count++;
        }
    }
    return count;
}

//Input integer n, returns true if n is a twin prime and false otherwise
bool isTwinPrime(int n){
    if(isPrime(n) && (isPrime(n-2) || isPrime(n+2))){
        return true;
    }
    return false;
}

//Input integer n, returns the next twin prime greater than n
int nextTwinPrime(int n){
    int temp = n;
    while(true){
        temp++;
        if(isTwinPrime(temp)){
            return temp;
        }
    }
    return -1;
}

//Input integers a and b, returns the largest twin prime between a and b
int largestTwinPrime(int a, int b){
    int largest = -1;
    for(int i = a; i <= b; i++){
        if(isTwinPrime(i)){
            largest = i;
        }
    }
    return largest;
}