#include <iostream>
#include "skill.hpp"
#include "profemon.hpp"
#include "trainer.hpp"
using namespace std;

int main(){
    //Maryash Skills
    Skill oop("OOP", "a programming paradigm based on the concept of objects, which can contain data and code", SOFTWARE, 30);
    Skill dynamic_array("Vector", "a c++ dynamic array library", SOFTWARE, 30);
    Skill pointer("Pointer", "a pointer stores a memory address", SOFTWARE, 10);
    Skill slap("slap","a slap",ML,25);
    Skill clap("clap","a clap",ML,15);
    Skill dance("dance","dancing!",ML,20);
    Skill splash("splash", "using splash!",HARDWARE,30);
    Skill twirl("twirl", "TRIWL!",HARDWARE,20);
    Skill stare("stare","Menacing!",HARDWARE,15);

    Profemon maryash("Maryash", 13500, SOFTWARE);
    Profemon noob("noob",120,ML);
    Profemon noob2("noob2",130,HARDWARE);
    Profemon bulb("bulb",200,ML);
    Profemon charz("charz",150,SOFTWARE);
    Profemon flip("flip",150,ML);
    Profemon eve("eve",170,SOFTWARE);

    cout << maryash.learnSkill(0, oop) << endl;
    cout << maryash.learnSkill(1, dynamic_array) << endl;
    cout << maryash.learnSkill(2, pointer) << endl;
    noob.learnSkill(0,slap);
    noob.learnSkill(1,clap);
    noob.learnSkill(2,dance);
    noob2.learnSkill(0,splash);
    noob2.learnSkill(1,twirl);
    noob2.learnSkill(2,stare);
    //maryash.printProfemon(true);

    cout << "LEVEL soft: " << maryash.getLevel() << endl;
    cout << "LEVEL ML: " << noob.getLevel() << endl;
    cout << "LEVEL hard: " << noob2.getLevel() << endl;
    maryash.levelUp(115);
    noob.levelUp(115);
    noob2.levelUp(115);

    cout << "------------------------\n";
    std::vector <Profemon> pokemons = {maryash,noob,noob2};

    Trainer t(pokemons); 
    cout << "ADDING POKEMON: " << t.addProfemon(charz) << "\n";
    cout << "REMOVING POKEMON: " << t.removeProfemon("charz") << "\n";
    cout << "removing non-existent: " << t.removeProfemon("charmander") << "\n";
    t.addProfemon(bulb);
    t.addProfemon(flip);
    t.addProfemon(eve);
    cout << "PRINTING POKEDEX: \n";
    t.printProfedex();

    cout << "------------------\n";
    cout << "PRINTING TEAM: \n";
    t.printTeam();

    cout << "------------------\n";
    noob.printProfemon(true);
    return 0;
}