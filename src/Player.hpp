#pragma once

#include "Pokemon.hpp"
#include "Inventory.hpp"
#include "Pokeball.hpp"
#include "PokemonParty.hpp"
#include <string>

using std::string;

class Player {
public :
    Player(const string &name);
    string username;
    PokemonParty pokemonParty;
    Pokeball pokeball;
    Inventory inventory;

    ~Player();
};