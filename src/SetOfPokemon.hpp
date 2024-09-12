
#pragma once

#include "Pokemon.hpp"
#include <iostream>
#include <vector>

using std::vector;

class SetOfPokemon {

protected:
    vector<Pokemon*> arrayOfPokemon;
public:
    virtual Pokemon* getPokemonByName(string& name) = 0;
    virtual Pokemon* getPokemonById(int id) = 0;
    void displayList();
};