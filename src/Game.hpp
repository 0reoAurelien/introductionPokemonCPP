#pragma once

#include <iostream>
#include "Pokedex.hpp"
#include "SetOfPokemon.hpp"
#include "Pokeball.hpp"


#include <string>
#include <iostream>

#define MultiPlayer 0
#define SinglePlayer 1


using std::string;

//typedef enum{ETAT0 = 0, ETAT1, ETAT2, ETAT3}

class Game{
    private:
    int state;
    Pokedex* pokedex = nullptr;
    int playerLevel;
    


    public:
    Game();
    static int gamemode;
    static Pokemon* activeEnemy;

    void play();

    ~Game();
};