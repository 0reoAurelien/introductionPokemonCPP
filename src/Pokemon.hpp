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
    int legendary;
    int shiny;
    int taken;


    public:
    Pokemon(int id, const string &name, int hitpoint, double attack, double defense, double speed, int gen, int legendary);
    Pokemon(const Pokemon &anotherPokemon, int isShiny);

    static int count;

    string getName() const;
    int getId() const;
    int getATK() const;
    int getDEF() const;
    int getSPEED() const;
    int getHP() const;
    int isShiny() const;
    int isLegendary() const;
    void setFree(int freeToCatch);
    int isTaken();
    void setHP(int newHP);
    void setATK(int newATK);
    void setDEF(int newDEF);
    void setSpeed(int newSpeed);
    void dealDmg(Pokemon &anotherPokemon);
    void displayName();
    void displayInfo();
    int capture(int catchRate);
    ~Pokemon();
};