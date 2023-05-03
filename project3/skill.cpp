#include <iostream>
#include "skill.hpp"
using namespace std;

Skill::Skill(){
    name = "Undefined";
    description = "Undefined";
    uses = -1;
    specialty = -1;
}
Skill::Skill(std::string name, std::string description, int specialty, int uses){
    // this->name refers to the class varaible "name" and sets it to the function parameter "name"
    this->name = name; 
    this->description = description;
    this->specialty = specialty;
    this->uses = uses; 
}

std::string Skill::getName(){
    return name;
}

std::string Skill::getDescription(){
    return description;
}

int Skill::getTotalUses(){
    return uses;
}

int Skill::getSpecialty(){
    return specialty;
}
void Skill::setName(std::string name){
    this->name = name;
}
void Skill::setDescription(std::string description){
    this->description = description;
}
void Skill::setTotalUses(int uses){
    this->uses = uses;
}
bool Skill::setSpecialty(int specialty){
    if((specialty==0) || (specialty==1) || (specialty==2)){ // if specialty is not 0,1 or 2, return false and don't update specialty
        this->specialty = specialty;
        return true;
    }
    return false;
}