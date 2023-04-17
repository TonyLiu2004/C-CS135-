#include <iostream>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn){
        username = usrn;
        displayname = dspn;
    }

    // Default Profile constructor (username="", displayname="")
    Profile(){
        username = "";
        displayname = "";
    }

    // Return username
    string getUsername(){
        return username;
    }

    // Return name in the format: "displayname (@username)"
    string getFullName(){
        return displayname + " (@" + username + ")";
    }

    // Change display name
    void setDisplayName(string dspn){
        displayname = dspn;
    }

    void setUsername(string usrn){
        username = usrn;
    }
};

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile
  bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
  // following[id1][id2] == true when id1 is following id2

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn){
    for(int i = 0;i < numUsers;i++){
        if(profiles[i].getUsername() == usrn){
            return i;
        }
    }
    return -1;
  }
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network(){
        for(int row = 0;row < MAX_USERS;row++){
            for(int col = 0;col < MAX_USERS;col++){
                following[row][col] = false;
            }
        }
        numUsers = 0;
    }

    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn){
        if(numUsers >= MAX_USERS){
            return false;
        }
        for(int i = 0;i < numUsers;i++){
            if(profiles[i].getUsername() == usrn){
                return false;
            }
        }
        for(char x : usrn){
            if(!iswalnum(x)){ // iswalnum returns true if the character is alphanumeric (number or alphabet)
                return false;
            }
        }
        profiles[numUsers].setDisplayName(dspn);
        profiles[numUsers].setUsername(usrn);
        numUsers++;
        return true;
    }
    bool follow(string usrn1, string usrn2){
        if((Network::findID(usrn1) == -1) || (Network::findID(usrn2) == -1)){
            cout << "cannot add";
            return false;
        }
        for(int row = 0;row < MAX_USERS;row++){
            for(int col = 0;col < MAX_USERS;col++){
                if((Network::findID(usrn1) == row) && (Network::findID(usrn2) == col)){
                    following[row][col] = true;
                }
            }
        }
        return true;
    }
    void printDot(){
        // for(int i = 0;i <=numUsers;i++){
        //     cout << profiles[i].getUsername() << " ";
        // }
        // cout << endl;
        // for(int row = 0;row < MAX_USERS;row++){
        //     for(int col = 0;col < MAX_USERS;col++){
        //         if(following[row][col]){
        //             cout << "t" << " ";
        //         }else{
        //             cout << "f" << " ";
        //         }
        //     }
        //     cout << endl;
        // }

        cout << "  digraph {" << endl;
        for(int i = 0;i < numUsers;i++){
            cout << "   \"" <<  profiles[i].getUsername() << "\"" << endl;
        }
        for(int row = 0;row < MAX_USERS;row++){
            for(int col = 0;col < MAX_USERS;col++){
                if(following[row][col]){
                    cout << "   \"" <<  profiles[row].getUsername() << "\"" << "-> \"" << profiles[col].getUsername() << "\""<< endl;
                }
            }
        }
    }
};

int main() {
    Network nw;
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    nw.addUser("wario", "Wario");
    
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    nw.follow("mario2", "luigi");

    nw.printDot();
}