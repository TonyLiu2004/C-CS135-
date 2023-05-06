#include <iostream>
#include "skill.hpp"
#include "profemon.hpp"
using namespace std;

int main(){
    //Maryash Skills
    Skill oop("OOP", "a programming paradigm based on the concept of objects, which can contain data and code", SOFTWARE, 30);
    Skill dynamic_array("Vector", "a c++ dynamic array library", SOFTWARE, 30);
    Skill pointer("Pointer", "a pointer stores a memory address", SOFTWARE, 10);

    Profemon maryash("Maryash", 13500, SOFTWARE);
    Profemon noob("noob",120,ML);
    Profemon noob2("noob2",130,HARDWARE);
    cout << maryash.learnSkill(0, oop) << endl;
    maryash.printProfemon(true);

    cout << "LEVEL soft: " << maryash.getLevel() << endl;
    cout << "LEVEL ML: " << noob.getLevel() << endl;
    cout << "LEVEL hard: " << noob2.getLevel() << endl;
    maryash.levelUp(115);
    noob.levelUp(115);
    noob2.levelUp(115);

    return 0;
}