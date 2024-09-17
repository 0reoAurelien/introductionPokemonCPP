#include "Game.hpp"


#define Pokeball 0
#define Superball 1
#define Hyperball 2
#define OranBerry 3
#define Potion 4
#define AttackPlus 5
#define Revive 6


Game::Game():
state(0), pokedex(Pokedex::getInstance()), playerLevel(0){

    Pokemon * starterPokemon = nullptr;

    srand(time(NULL));
    
    //int isShiny = (SHINY_ODDS > rand()%8192); when encountering a wild pokemon
    
}

Game::~Game()
{
}
