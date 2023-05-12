/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3

Defines the class Trainer
*/
#pragma once
#include <iostream>
#include "skill.hpp"
#include "profemon.hpp"
#include <vector>

class Trainer{
    private:
        std::vector <Profemon> pokedex;
        Profemon team[3];
        Profemon* currProfemon;
    public:
        Trainer();
        Trainer(std::vector <Profemon> profemons);
        bool contains(std::string name);
        bool addProfemon(Profemon profemon);
        bool removeProfemon(std::string name);
        void setTeamMember(int slot, std::string name);
        bool chooseProfemon(int slot);
        Profemon getCurrent();
        void printProfedex();
        void printTeam();
};