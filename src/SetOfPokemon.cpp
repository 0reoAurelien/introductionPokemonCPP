
#include <iostream>
#include <vector>
#include "SetOfPokemon.hpp"

using std::vector;


void SetOfPokemon::displayList(){

    std::cout << "***\n" << std::endl;

    for (Pokemon* pokemon : arrayOfPokemon) {
        std::cout << "arrayOfPokemon is not empty !\n" << std::endl;
        pokemon -> displayInfo();
        std::cout << "and you just saw one of them little babies\n" << std::endl;
    }

    std::cout << "XXX\n" << std::endl;

}