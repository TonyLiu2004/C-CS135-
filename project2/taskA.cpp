#include <iostream>
#include <fstream>
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

int main(){
    readSongs("songs.txt");
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
    int count = 0;
    string line;

    while(getline(fin,line)){
        if(g_number_of_songs >= g_curr_size){
            allocateNew();
        }

        string tempLine = line;
        g_song_names[count] = tempLine.substr(0,line.find(":")); //finds the song name which is from index 0 to the first :
        tempLine = tempLine.substr(line.find(":")+1); // removes the song name and : from tempLine
        
        g_artist_names[count] = tempLine.substr(0,tempLine.find("-"));
        // g_genres[count] = genre;
        // g_song_durations[count] = duration;
        count++;
        g_number_of_songs++;
    }
}