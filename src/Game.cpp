#include "Game.hpp"

Game::Game():
state(0), username(""), pokedex(Pokedex::getInstance()), playerLevel(0){

    Pokemon * starterPokemon = nullptr;

    srand(time(NULL));
    
    //int isShiny = (SHINY_ODDS > rand()%8192); when encountering a wild pokemon
    
}





