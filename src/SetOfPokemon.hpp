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
    virtual Pokemon* getPokemonByName(const string& name, int removeFromList) = 0;
    virtual Pokemon* getPokemonById(int id, int removeFromList) = 0;
    virtual string getTitle() = 0;
    
    int getArraySize();
    void displayList();
    void displayListDetails();
    Pokemon* firstPokemon();

};