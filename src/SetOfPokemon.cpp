
#include <iostream>
#include <vector>
#include "SetOfPokemon.hpp"

using std::vector;


void SetOfPokemon::displayList(){

    std::cout << "***\n" << std::endl;

    for (Pokemon* pokemon : arrayOfPokemon) {
        std::cout << "There are pokemons in the arrayOfPokemon" << std::endl;
        pokemon -> displayInfo();
        std::cout << "You just saw one of them.\n" << std::endl;
    }
}