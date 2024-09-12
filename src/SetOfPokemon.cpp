
#include <iostream>
#include <vector>
#include "SetOfPokemon.hpp"

#include <string>

using std::string;
using std::vector;

int SetOfPokemon::maxId = 0;

void SetOfPokemon::displayList(){

    std::cout << "***** Pokedex *****\n" << std::endl;

    for (Pokemon* pokemon : arrayOfPokemon) {
        //std::cout << "There are pokemons in the arrayOfPokemon" << std::endl;
        pokemon -> displayName();
        //std::cout << "You just saw one of them.\n" << std::endl;
    }
}


void SetOfPokemon::displayListDetails(){

    std::cout << "***** Pokedex *****\n" << std::endl;

    for (Pokemon* pokemon : arrayOfPokemon) {
        pokemon -> displayInfo();
    }
}


string SetOfPokemon::stringTolower(const string& str) 
{   
    string newstr = str;
    for(int i = 0; str[i]; i++){
        newstr[i] = tolower(str[i]);
    }
    return newstr;
} 