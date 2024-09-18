#include "Game.hpp"


#define LoadingGame 0

#define MainMenu 1
#define MultiplayerMenu 2
#define SinglePlayerMenu 3
#define Settings 4

#define TeamConfiguration 5
#define Dueling 6

#define TeamSelection 7
#define Training 8
#define GymAttempt 9


Game::Game():
state(0), pokedex(Pokedex::getInstance()), playerLevel(0){

    Pokemon * starterPokemon = nullptr;

    srand(time(NULL));
    
    //int isShiny = (SHINY_ODDS > rand()%8192); when encountering a wild pokemon
    
}

Game::~Game()
{
}
