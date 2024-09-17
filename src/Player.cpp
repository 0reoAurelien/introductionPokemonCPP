#include "Player.hpp"
#include "Pokedex.hpp"


Player::Player(const string &name):username(name)
{
    Pokedex* pokedex = Pokedex::getInstance();

    Pokemon* starterPokemon = pokedex->randomWildPokemon();
    Pokemon* ptrBackup = nullptr;
    while (starterPokemon->isLegendary()){
        ptrBackup = starterPokemon;
        starterPokemon = pokedex->randomWildPokemon();
        delete ptrBackup;
    }

}
