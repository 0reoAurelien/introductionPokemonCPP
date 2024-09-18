#pragma once

#include "Pokemon.hpp"
#include "Inventory.hpp"
#include "Pokeball.hpp"
#include "PokemonParty.hpp"
#include <string>

using std::string;

class Player {
private :
    string username;
public :
    Player(const string &name);
    string getUsername() const;
    PokemonParty* pokemonParty;
    void addPokeToParty(Pokemon* pokeToAdd, int gamemode);
    void removePokeFromParty(Pokemon* pokeToRemove);
    Pokemon* activePokemon;
    PokemonParty* dyingPokemons;
    Pokeball* pokeball;
    Inventory* inventory;
    int badges;
    int playerLevel;

    vector <int> useItem(Item* item);

    ~Player();
};