/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3

Defines the functions for departments
*/
#include <iostream>
#include "department.hpp"
using namespace std;

MLDepartment::MLDepartment(std::vector<Profemon> profemons){
    int counter = 0;
    for(int i =0;i < 3;i++){ //add to team if there are empty slots
        if((team[i].getName() == "Undefined") && (profemons[counter].getSpecialty() == 0)){
            team[i] = profemons[counter];
            counter++;
        }
        if(counter >= profemons.size()){ //exits if we run out of pokemons to add
            return;
        }  
    }

    currProfemon = &team[0]; //selects pokemon 0 of team array to accompany the trainer.
}

bool MLDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 0){
        Trainer::addProfemon(profemon);
        return true;
    }
    return false;
}

SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons){
    int counter = 0;
    for(int i =0;i < 3;i++){ //add to team if there are empty slots
        if((team[i].getName() == "Undefined") && (profemons[counter].getSpecialty() == 1)){
            team[i] = profemons[counter];
            counter++;
        }
        if(counter >= profemons.size()){ //exits if we run out of pokemons to add
            return;
        }  
    }

    currProfemon = &team[0]; //selects pokemon 0 of team array to accompany the trainer.
}

bool SoftwareDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 1){
        Trainer::addProfemon(profemon);
        return true;
    }
    return false;
}

HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons){
    int counter = 0;
    for(int i =0;i < 3;i++){ //add to team if there are empty slots
        if((team[i].getName() == "Undefined") && (profemons[counter].getSpecialty() == 2)){
            team[i] = profemons[counter];
            counter++;
        }
        if(counter >= profemons.size()){ //exits if we run out of pokemons to add
            return;
        }  
    }

    currProfemon = &team[0]; //selects pokemon 0 of team array to accompany the trainer.
}

bool HardwareDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 2){
        Trainer::addProfemon(profemon);
        return true;
    }
    return false;
}