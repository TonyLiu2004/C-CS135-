/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2

allocateNew() dynamically creates more space in the global arrays if it needs more space.

readeSongs reads from songs.txt and populates the global arrays accordingly
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int g_curr_size = 2;
int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size 
                          ('g_curr_size' * 2). Update
                          'g_curr_size' accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          'g_song_names', 'g_artist_names', 
                          'g_song_durations', 'g_genres'
*/
void allocateNew();


/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the global-arrays and set the 
                          value of 'g_number_of_songs'
                          to the number of songs read.
                          Call 'allocateNew()' to allocate 
                          an array of larger size if the 
                          dynamic arrays reach full 
                          capacity.
*/
void readSongs(string filename);


//returns only the integers from a string
int numbersFromString(string input){
    string ret = "";
    for(char x : input){
        if((x-'0') < 10){ // x is a char, x minus char '0' will be the the integer value of the character. If this value is greater than 9, then it is not an integer
            ret+= to_string(x - '0'); //appends the integer value as a string to ret
        }
    }
    int n = stoi(ret);
    return n;
}


int main(){
    readSongs("songs.txt");
    for(int i = 0;i < g_number_of_songs;i++){
        cout << g_song_names[i] << "---" << g_artist_names[i] << "---" << g_genres[i] << "---" << g_song_durations[i] << endl;
    }
    return 0;
}

void allocateNew(){
    int newSize = g_curr_size * 2;
    string *new_song_names = new string[newSize];
    string *new_artist_names = new string[newSize];
    int *new_song_durations = new int[newSize];
    string *new_genres = new string[newSize];

    for(int i =0;i < g_curr_size;i++){
        new_song_names[i] = g_song_names[i];
        new_artist_names[i] = g_artist_names[i];
        new_genres[i] = g_genres[i];
        new_song_durations[i] = g_song_durations[i];
    }


    delete[] g_song_names;
    delete[] g_artist_names;
    delete[] g_genres;
    delete[] g_song_durations;

    g_song_names = new_song_names;
    g_artist_names = new_artist_names;
    g_song_durations = new_song_durations;
    g_genres = new_genres;
    g_curr_size = newSize;

}

void readSongs(string filename){
    ifstream fin(filename);
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string songName;
    string artist;
    int duration;
    string genre;

    int count = 0; // counting index to update global arrays
    string line;

    while(getline(fin,line)){
        if(g_number_of_songs >= g_curr_size){
            allocateNew();
        }

        string tempLine = line;
        g_song_names[count] = tempLine.substr(0,line.find(":")); //finds the song name which is from index 0 to the first :
        tempLine = tempLine.substr(tempLine.find(":")+1); // removes the song name and : from tempLine
        
        g_artist_names[count] = tempLine.substr(0,tempLine.find("-")); //finds the artist name from index 0 to the first -
        tempLine = tempLine.substr(tempLine.find("-")+1); //removes the artist name and : 
        
        g_genres[count] = tempLine.substr(0,tempLine.find("-")); // finds the genre from index 0 to final -
        tempLine = tempLine.substr(tempLine.find("-")+1); //removes the genre and :

        g_song_durations[count] = numbersFromString(tempLine); //gets only the numbers from the remaining text

        count++; 
        g_number_of_songs++;
    }
}