#include <iostream>
#include <vector>
using namespace std;

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

std::string solve(std::string encrypted_string){
    vector<int> count(26,0);
    vector<double> freq ={8.2,1.5,2.8,4.3,13,2.2,2,6.1,7,0.15,0.77,4,2.4,6.7,7.5,1.9,0.095,6,6.3,9.1,2.8,0.98,2.4,0.15,2,0.074};
    //char alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    for(char x : encrypted_string){
        if(isalpha(x)){
            count[getLocation(x)] +=1;
        }
    }
    return "";
}

int main(){
    cout << getLocation('z') << endl <<endl;
    cout << solve("hello world");
    return 0;
}