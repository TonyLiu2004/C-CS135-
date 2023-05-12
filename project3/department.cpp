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
    for(int i = 0;i < profemons.size();i++){
        if(profemons[i].getSpecialty() == 0){
            team[counter] = profemons[i];
            counter++;
        }
        if(counter > 3){
            break;
        }
    }
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
    for(int i = 0;i < profemons.size();i++){
        if(profemons[i].getSpecialty() == 1){
            team[counter] = profemons[i];
            counter++;
        }
        if(counter > 3){
            break;
        }
    }
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
    for(int i = 0;i < profemons.size();i++){
        if(profemons[i].getSpecialty() == 2){
            team[counter] = profemons[i];
            counter++;
        }
        if(counter > 3){
            break;
        }
    }
}

bool HardwareDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 2){
        Trainer::addProfemon(profemon);
        return true;
    }
    return false;
}