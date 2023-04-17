/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2 C

Uses class Song to store and retrieve song information from file.
*/
#include <iostream>
#include <fstream>
using namespace std;

class Song { 
public:
    string name;
    string artist;
    int duration;
    string genre;
};

int g_capacity = 2;
int g_size = 0;

Song *g_songs = new Song[g_capacity];

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

void allocateNew(){
    int newCapacity = g_capacity * 2;
    Song *newSongs = new Song[newCapacity];
    
    for(int i = 0;i < g_capacity;i++){
        newSongs[i].name = g_songs[i].name;
        newSongs[i].artist = g_songs[i].artist;
        newSongs[i].duration = g_songs[i].duration;
        newSongs[i].genre = g_songs[i].genre;
    }

    delete[] g_songs;
    g_songs = newSongs;
    g_capacity = newCapacity;
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
        if(g_size >= g_capacity){
            allocateNew();
        }

        string tempLine = line;
        if(line == ""){ //if its an empty line, skip
            continue;
        }

        g_songs[count].name = tempLine.substr(0,line.find(":")); //finds the song name which is from index 0 to the first :
        tempLine = tempLine.substr(tempLine.find(":")+1); // removes the song name and : from tempLine
        
        g_songs[count].artist = tempLine.substr(0,tempLine.find("-")); //finds the artist name from index 0 to the first -
        tempLine = tempLine.substr(tempLine.find("-")+1); //removes the artist name and : 
        
        g_songs[count].genre = tempLine.substr(0,tempLine.find("-")); // finds the genre from index 0 to final -
        tempLine = tempLine.substr(tempLine.find("-")+1); //removes the genre and :

        g_songs[count].duration = numbersFromString(tempLine); //gets only the numbers from the remaining text

        count++; 
        g_size++;
    }
}

// Now returns a dynamic array of 'Song' objects instead of a 'string' objects
Song * getSongsFromDuration(int duration, int &durationsCount, int filter){
    Song *ret = new Song[g_size];
	int count = 0;
	for(int i =0; i<g_size;i++){
		if(filter == 2 && duration == g_songs[i].duration){
            ret[count] = g_songs[i];
			count++;
		}
		if(filter == 1 && duration > g_songs[i].duration){	
            ret[count] = g_songs[i];
			count++;
		}
		if(filter == 0 && duration < g_songs[i].duration){
            ret[count] = g_songs[i];
			count++;
		}
	}
	durationsCount = count;
	return ret;
}

Song * getGenreSongs(string genre, int &genreCount){
    Song *genreSongs = new Song[g_size];
    int songsCount = 0;
    for(int i = 0;i < g_size; i++){
        if(g_songs[i].genre == genre){
            genreSongs[songsCount] = g_songs[i];
            songsCount++;
        }
    }
    genreCount = songsCount;
    return genreSongs;
}

// Change the implementation since we are using 'Song' class
string * getUniqueArtists(int &uniqueCount){
	string *uniqueArtists = new string[g_size];
	int count = 0;
	for(int i = 0; i < g_size;i++){
        bool isUnique = true;
        for(int j = 0;j<=count;j++){ // check if artist name is in uniqueArtists, if it is the artist is not unique and nothing happens
            if(uniqueArtists[j] == g_songs[i].artist){
                isUnique = false;
                break;
            }
        }
        if(isUnique){
            uniqueArtists[count] = g_songs[i].artist; 
            count++;
        }
	}
	uniqueCount = count;
	return uniqueArtists;
}

string getFavoriteArtist(){
    int maxCount = 0;
	string favArt = "NONE";
	for( int i = 0; i <g_size;i++){
		int count = 0;
		for(int j =0;j<g_size;j++){
			if(g_songs[i].artist == g_songs[j].artist){
				count++;
			}
		}
		if(maxCount < count){
			maxCount = count;
			favArt = g_songs[i].artist;
		}
	}
	return favArt;
}

int main(){
    readSongs("songs.txt");

    for(int i = 0;i < g_size;i++){
        cout << g_songs[i].name << "---" << g_songs[i].artist << "---" << g_songs[i].genre << "---" << g_songs[i].duration << endl;
    }
    return 0;
}