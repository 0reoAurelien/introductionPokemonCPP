
#include <iostream>
#include <vector>
#include "SetOfPokemon.hpp"
#include "Utility.hpp"

#include <string>

using std::string;
using std::vector;

int SetOfPokemon::maxId = 0;

void SetOfPokemon::displayList(){

    std::cout << "***** " << getTitle() << " *****\n" << std::endl;

    for (Pokemon* pokemon : arrayOfPokemon) {
        //std::cout << "There are pokemons in the arrayOfPokemon" << std::endl;
        pokemon -> displayName();
        //std::cout << "You just saw one of them.\n" << std::endl;
    }

    std::cout << "\n" << std::endl;

}


void SetOfPokemon::displayListDetails(){
    string debug = getTitle();
    std::cout << "***** " << debug << " *****\n" << std::endl;

    for (Pokemon* pokemon : arrayOfPokemon) {
        pokemon -> displayInfo();
    }
    std::cout << "\n" << std::endl;

}

