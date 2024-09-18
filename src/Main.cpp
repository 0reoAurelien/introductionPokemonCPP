

#include <iostream>
#include "Pokedex.hpp"
#include "SetOfPokemon.hpp"
#include "Pokeball.hpp"
#include "Game.hpp"

int main(){
    Game* game = new Game();
    game->play();
    return 0;
}