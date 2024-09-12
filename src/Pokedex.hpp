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
    Pokemon* getPokemonByName(const string& name);
    Pokemon* getPokemonById(const int id);
    Pokemon* randomWildPokemon();
    ~Pokedex();
};