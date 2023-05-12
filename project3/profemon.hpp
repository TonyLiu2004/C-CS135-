/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3

Defines the class Profemon
*/
#pragma once
#include <iostream>
#include "skill.hpp"
enum Specialty {ML,SOFTWARE,HARDWARE};

class Profemon{
    private:
        std::string name;
        int level;
        int levelupXP;
        int currXP;
        int max_health;
        Specialty specialty;
        Skill skills[3];
    public:
        Profemon();
        Profemon(std::string name, double max_health, Specialty specialty);
        std::string getName();
        Specialty getSpecialty();
        int getLevel();
        double getMaxHealth();
        void setName(std::string name);
        void levelUp(int exp);
        bool learnSkill(int slot, Skill skill);
        void printProfemon(bool print_skills);
        int getCurrXP();
        int getLevelupXP();
};