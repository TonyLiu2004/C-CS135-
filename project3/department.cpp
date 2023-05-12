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
    for(int i = 0;i < profemons.size();i++){
        if(profemons[i].getSpecialty() == 0){
            addProfemon(profemons[i]);
        }
    }
}

bool MLDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 0){
        addProfemon(profemon);
        return true;
    }
    return false;
}

SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons){
    for(int i = 0;i < profemons.size();i++){
        if(profemons[i].getSpecialty() == 1){
            addProfemon(profemons[i]);
        }
    }
}

bool SoftwareDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 1){
        addProfemon(profemon);
        return true;
    }
    return false;
}

HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons){
    for(int i = 0;i < profemons.size();i++){
        if(profemons[i].getSpecialty() == 2){
            addProfemon(profemons[i]);
        }
    }
}

bool HardwareDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 2){
        addProfemon(profemon);
        return true;
    }
    return false;
}