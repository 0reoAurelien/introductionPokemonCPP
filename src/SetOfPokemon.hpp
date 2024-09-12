
#pragma once

#include "Pokemon.hpp"
#include <iostream>
#include <vector>

using std::vector;

class SetOfPokemon {

protected:
    vector<Pokemon*> arrayOfPokemon;
public:
    static int maxId;
    virtual Pokemon* getPokemonByName(string& name) = 0;
    virtual Pokemon* getPokemonById(int id) = 0;
    string stringTolower(const string& str);
    void displayList();
};