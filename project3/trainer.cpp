/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3

Trainer class
*/
#include <iostream>
#include "trainer.hpp"
#include <vector>
using namespace std;

Trainer::Trainer(){
    currProfemon = nullptr;
}

Trainer::Trainer(vector <Profemon> profemons){
    int counter = 0;
    for(int i =0;i < 3;i++){ //add to team if there are empty slots
        if(team[i].getName() == "Undefined"){
            team[i] = profemons[counter];
            counter++;
        }
        if(counter >= profemons.size()){ //exits if we run out of pokemons to add
            return;
        }  
    }
    for(int i = counter;i < profemons.size();i++){ //adds the extra pokemons to pokedex is team is full
        pokedex.push_back(profemons[i]);
    }

    currProfemon = &team[0]; //selects pokemon 0 of team array to accompany the trainer.
}

bool Trainer::contains(std::string name){
    for(int i = 0;i < 3;i++){ //check if pokemon is in team
        if(team[i].getName() == name){
            return true;
        }
    }

    for(int i = 0;i < pokedex.size();i++){ //check if pokemon is in pokedex
        if(pokedex[i].getName() == name){
            return true;
        }
    }
    return false;
}

bool Trainer::addProfemon(Profemon profemon){
    if(contains(profemon.getName())){ //if a profemon of the same name is in team or pokedex, return false
        return false;
    }

    for(int i =0;i < 3;i++){ //add to team if there are empty slots
        if(team[i].getName() == "Undefined"){
            team[i] = profemon;
            return true;
        }
    }
    pokedex.push_back(profemon); //add to pokedex if team is full and pokemon name is new
    return true;
}

bool Trainer::removeProfemon(std::string name){
    if(!contains(name)){ //cannot remove is profemon already doesn't exist
        return false;
    }

    Profemon empty;
    for(int i = 0;i < 3;i++){ //removes pokemon if it is in team
        if(team[i].getName() == name){
            team[i] = empty;
            return true;
        }
    }
    
    for(int i = 0;i < pokedex.size();i++){ //removes pokemon if it is in pokedex
        if(pokedex[i].getName() == name){
            pokedex.erase(pokedex.begin() + i); //erases pokemon at index i
            return true;
        } 
    }

    return false;
}

void Trainer::setTeamMember(int slot, std::string name){
    int profemonIndex = -1;
    for(int i = 0;i < pokedex.size();i++){ //finds the index of the pokemon 
        if(pokedex[i].getName() == name){
            profemonIndex = i;
            break;
        }
    }

    if(profemonIndex == -1){
        return;
    }
    if(team[slot].getName() != "Undefined"){ //if pokemon in team at slot is not undefined, swap the pokemons at team[slot] and the pokemon in pokedex
        Profemon temp = team[slot];
        team[slot] = pokedex[profemonIndex];
        pokedex[profemonIndex] = temp;
    }else{ //if pokemon in team at slot is undefined, move the pokemon into team and remove it from pokedex
        Profemon temp  = pokedex[profemonIndex];
        removeProfemon(name);
        team[slot] = temp;
    }
}

bool Trainer::chooseProfemon(int slot){
    if(team[slot].getName() != "Undefined"){
        currProfemon = &team[slot];
        return true;
    }
    return false;
}

Profemon Trainer::getCurrent(){
    return *currProfemon;
}

void Trainer::printProfedex(){
    for(int i = 0;i < pokedex.size();i++){
        Profemon p = pokedex[i];
        string s;
        if(p.getSpecialty() == 0){
            s = "ML";
        }else if(p.getSpecialty() == 1){
            s = "SOFTWARE";
        }else{
            s = "HARDWARE";
        }
        cout << p.getName() << " [" << s << "] | lvl " << p.getLevel() << " | exp " << p.getCurrXP() << "/" << p.getLevelupXP() << " | hp " << p.getMaxHealth() << "\n\n";
    }
}

void Trainer::printTeam(){
    for(int i = 0;i < 3;i++){
        if(team[i].getName() != "Undefined"){
            team[i].printProfemon(true);
            cout << "\n";
        }
    }
}