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
    Pokedex* pokedex = nullptr;
    int playerLevel;
    Pokemon * starterPokemon = nullptr;


    public:
    Game();

    void play();

    ~Game();
};