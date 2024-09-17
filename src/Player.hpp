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
    PokemonParty* pokemonParty;
    PokemonParty* dyingPokemons;
    Pokeball* pokeball;
    Inventory* inventory;

    int useItem(Item* item);

    ~Player();
};