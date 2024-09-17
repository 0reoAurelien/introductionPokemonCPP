#pragma once

#include "Pokemon.hpp"
#include "Inventory.hpp"
#include "Pokeball.hpp"
#include "PokemonParty.hpp"

class Player {
public :
    Pokemon * starterPokemon = nullptr;
    PokemonParty pokemonParty;
    Pokeball pokeball;
    Inventory inventory;    
};