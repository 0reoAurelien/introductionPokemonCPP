#pragma once

#include <string>
#include <iostream>


using std::string;

class Pokemon{
    private:
    int id;
    string name;
    int hitpoint;
    double attack;
    double defense;
    double speed;
    int gen;
    static int count;
    int legendary;
    int shiny = 0;


    public:
    Pokemon(int id, const string &name, int hitpoint, double attack, double defense, double speed, int gen, int legendary);
    Pokemon(const Pokemon &anotherPokemon);

    string getName() const;
    int getId() const;
    int getATK() const;
    int getDEF() const;
    int getSPEED() const;
    int getHP() const;
    void setHP(int newHP);
    void dealDmg(Pokemon &anotherPokemon);
    void displayName();
    void displayInfo();
    int capture(int catchRate);
    ~Pokemon();
};