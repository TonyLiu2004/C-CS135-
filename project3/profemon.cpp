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
    int XPincrease;
    if(specialty == ML){
        XPincrease = 10;
    }else if(specialty == SOFTWARE){
        XPincrease = 15;
    }else{
        XPincrease = 20;
    }

    while((currXP + exp) >= levelupXP){
        exp -= levelupXP - currXP;
        currXP = 0;
        levelupXP+=XPincrease;
    }
    currXP = exp;
}

bool Profemon::learnSkill(int slot, Skill skill){
    if((skill.getSpecialty() == specialty) && ((slot==0) || (slot==1) || (slot==2))){ // returns false if the skill does not match the specialty of the pokemon or if the slot is not valid
        skills[slot] = skill;
        return true;
    }
    return false;
}

void Profemon::printProfemon(bool print_skills){
    if(print_skills){
        std::cout << name << " [" << specialty << "] | " << "lvl " << level << " | exp " << currXP << "/" << levelupXP << " | hp " << max_health << "\n";
        std::cout << "    " << skills[0].getName() << "[" << skills[0].getTotalUses() << "] " << skills[0].getDescription() << "\n";
        std::cout << "    " << skills[1].getName() << "[" << skills[1].getTotalUses() << "] " << skills[1].getDescription() << "\n";
        std::cout << "    " << skills[2].getName() << "[" << skills[2].getTotalUses() << "] " << skills[2].getDescription() << "\n";
        std::cout << "\n";
    }
}