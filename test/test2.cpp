#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

string encryptCaesar(string plaintext, int rshift);

char shiftChar(char c, int rshift){
    char ret = c;
    if(!isalpha(c)){
        return c;
    }
    for(int i = 0;i < rshift;i++){
        if(ret == 'z'){
            ret = 'a';
        }else if(ret == 'Z'){
            ret = 'A';
        }else{
            ret+=1;
        }
    }
    return ret;
}

string encryptCaesar(string plaintext, int rshift){
    string ret = "";
    for(char x : plaintext){
        ret+=shiftChar(x,rshift);
    }
    return ret;
}

//returns the position of a letter in the alphabet, from 0-25
int getLocation(char a){
    char alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int i = 0;
    for(char x : alpha){
        if(x == a){
            return i;
        }
        i++;
    }
}

//distance formula is  sqrt(  (PhraseFreqA - EngFreqA)^2 + (Phrase FreqB - EngFreB)^2... etc)
double dist(vector<int> count){
    vector<double> freq ={8.2,1.5,2.8,4.3,13,2.2,2,6.1,7,0.15,0.77,4,2.4,6.7,7.5,1.9,0.095,6,6.3,9.1,2.8,0.98,2.4,0.15,2,0.074};
    double sum = 0;
    int i = 0;
    for(double x : count){
        sum+=pow(count[i]-freq[i],2);
        i++;
    }
    return sqrt(sum);
}

//returns a vector with the frequency of each of the 26 letters of the alphabet in order
vector<int> letterFreq(string a){
    vector<int> count(26,0);
    for(char x : a){
        if(isalpha(x)){
            count[getLocation(x)] +=1;
        }
    }
    return count;
}

std::string solve(std::string encrypted_string){
    string ret = "";
    int sDistance = 100;
    for(int i =0;i < 25;i++){
        string r = encryptCaesar(encrypted_string,i);
        vector<int> letterCount = letterFreq(r);
        double distance = dist(letterCount);
        if(distance < sDistance){
            sDistance = distance;
            ret = encryptCaesar(encrypted_string,i);
        }
    }
    return ret;
}

int main(){
    string s = "Hello, World!";
    string e = encryptCaesar(s,1);
    cout << e << endl;
    cout << solve("i love eating cookies"); // doesnt deal with caps and non-letters yet, fix
    return 0;
}
