#pragma once

#include "Pokemon.hpp"
#include <iostream>
#include <vector>

using std::vector;

class SetOfPokemon {

protected:
    string title; 
    vector<Pokemon*> arrayOfPokemon;
public:
    static int maxId;
    Pokemon* findPokemonByName(const string& name);
    Pokemon* findPokemonById(int id);
    virtual Pokemon* getPokemonByName(const string& name) = 0;
    virtual Pokemon* getPokemonById(int id) = 0;
    void displayList();
    void displayListDetails();
};