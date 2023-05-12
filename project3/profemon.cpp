/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3

Defines the public functions for the Profemon class
*/
#include <iostream>
#include "profemon.hpp"
#include "skill.hpp"

Profemon::Profemon(){
    name = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty){
    this->name = name;
    this->max_health = max_health;
    this->specialty = specialty;
    levelupXP = 50;
    currXP = 0;
    level=0;
}

std::string Profemon::getName(){
    return name;
}

Specialty Profemon::getSpecialty(){
    return specialty;
}

int Profemon::getLevel(){
    return level;
}

double Profemon::getMaxHealth(){
    return max_health;
}

void Profemon::setName(std::string name){
    this->name = name;
}

void Profemon::levelUp(int exp){
    int XPincrease = 0;
    currXP+=exp;
    if(specialty == ML){
        XPincrease = 10;
    }else if(specialty == SOFTWARE){
        XPincrease = 15;
    }else{
        XPincrease = 20;
    }

    while(currXP >= levelupXP){
        currXP-= levelupXP;
        level++;
        levelupXP+=XPincrease;
    }
}

bool Profemon::learnSkill(int slot, Skill skill){
    if((skill.getSpecialty() == specialty) && ((slot==0) || (slot==1) || (slot==2))){ // returns false if the skill does not match the specialty of the pokemon or if the slot is not valid
        skills[slot] = skill;
        return true;
    }
    return false;
}

void Profemon::printProfemon(bool print_skills){
    std::string Pspecial = "";
    if(specialty == 0){
        Pspecial = "ML";
    }else if(specialty == 1){
        Pspecial = "SOFTWARE";
    }else{
        Pspecial = "HARDWARE";
    }
    
    std::cout << name << " [" << Pspecial << "] | " << "lvl " << level << " | exp " << currXP << "/" << levelupXP << " | hp " << max_health << "\n";
    if(print_skills){
        for(int i =0;i < 3;i++){
            if(skills[i].getName() != "Undefined"){
                std::cout << "    " << skills[i].getName() << " [" << skills[i].getTotalUses() << "] : " << skills[i].getDescription() << "\n";
            }
        }
    }
}

int Profemon::getCurrXP(){
    return currXP;
}

int Profemon::getLevelupXP(){
    return levelupXP;
}