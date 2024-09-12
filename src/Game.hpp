#pragma once

#include <iostream>
#include "Pokedex.hpp"
#include "SetOfPokemon.hpp"
#include "Pokeball.hpp"


#include <string>
#include <iostream>


using std::string;

//typedef enum{ETAT0 = 0, ETAT1, ETAT2, ETAT3}

class Game{
    private:
    int state;
    string username;
    Pokedex* pokedex = nullptr;
    int playerLevel;
    Pokemon * starterPokemon = nullptr;


    public:
    Game();

    string getName() const;
    int getId() const;
    int getATK() const;
    int getDEF() const;
    int getHP() const;

    void displayName();
    void displayInfo();
    ~Game();
};