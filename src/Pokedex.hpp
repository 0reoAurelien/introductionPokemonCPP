#pragma once
#include "SetOfPokemon.hpp"
#include <iostream>

using std::string;
using std::ifstream;

class Pokedex final : public SetOfPokemon{

private:
    Pokedex();
    Pokedex(const Pokedex&) = delete;
    Pokedex& operator=(const Pokedex&) = delete;
    static Pokedex* pokedex;

public:
    static Pokedex * getInstance();
    Pokemon* getPokemonByName(const string& name, int removeFromList=0);
    Pokemon* getPokemonById(const int id, int removeFromList=0);
    Pokemon* randomWildPokemon(string type1 = "", string type2 = "", string type3 = "", int allowLegendary = 1);
    ~Pokedex();
};