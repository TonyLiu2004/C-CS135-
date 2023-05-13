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
	int count = 0;
    for(int i = 0 ; i<profemons.size();i++){
        if(profemons[i].getSpecialty()==0){
            if(count<3){
                team[count] = profemons[i];
                count++;
            }
            else{
                pokedex.push_back(profemons[i]);
            }
        }
    }
    currProfemon = &team[0];
}

bool MLDepartment::addProfemon(Profemon profemon){
	if((profemon.getSpecialty()!=0) || (contains(profemon.getName()))){
		return false;
	}
	for(int i =0; i< 3;i++){
		if(team[i].getName()=="Undefined"){
			team[i] = profemon;
			return true;
        }
	}
	pokedex.push_back(profemon);
	return true;
}

SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons){
	int count = 0;
    for(int i = 0 ; i<profemons.size();i++){
        if(profemons[i].getSpecialty()==1){
            if(count<3){
                team[count] = profemons[i];
                count++;
            }
            else{
                pokedex.push_back(profemons[i]);
            }
        }
    }
    currProfemon = &team[0];
}

bool SoftwareDepartment::addProfemon(Profemon profemon){
	if((profemon.getSpecialty()!=1) || (contains(profemon.getName()))){
		return false;
	}
	for(int i =0; i< 3;i++){
		if(team[i].getName()=="Undefined"){
			team[i] = profemon;
			return true;
        }
	}
	pokedex.push_back(profemon);
	return true;
}

HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons){
	int count = 0;
    for(int i = 0 ; i<profemons.size();i++){
        if(profemons[i].getSpecialty()==2){
            if(count<3){
                team[count] = profemons[i];
                count++;
            }
            else{
                pokedex.push_back(profemons[i]);
            }
        }
    }
    currProfemon = &team[0];
}

bool HardwareDepartment::addProfemon(Profemon profemon){
	if((profemon.getSpecialty()!=2) || (contains(profemon.getName()))){
		return false;
	}
	for(int i =0; i< 3;i++){
		if(team[i].getName()=="Undefined"){
			team[i] = profemon;
			return true;
        }
	}
	pokedex.push_back(profemon);
	return true;
}