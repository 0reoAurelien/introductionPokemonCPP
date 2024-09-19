#pragma once

#include <iostream>
#include "Pokedex.hpp"
#include "SetOfPokemon.hpp"
#include "Pokeball.hpp"
#include "Player.hpp"


#include <string>
#include <iostream>

#define TRUE 1
#define FALSE 0
#define MultiPlayerMode 0
#define SinglePlayerMode 1


using std::string;

//typedef enum{ETAT0 = 0, ETAT1, ETAT2, ETAT3}

class Game{
    private:
    int state;
    Pokedex* pokedex = nullptr;

    vector <int> achievements; //Needs to read the save files to fill it
    
    Player * player0;
    Player * player1;
    Player * player2;

    int bothReady[2] = {0, 0};

    public:
    Game();
    static int gamemode;
    static Pokemon* activeEnemy;

    void play();
    void playSolo();
    void playMulti();

    int editPlayer(int sel);
    void duel();

    ~Game();
};