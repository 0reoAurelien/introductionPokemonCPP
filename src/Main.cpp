

#include <iostream>
#include "Pokedex.hpp"
#include "SetOfPokemon.hpp"
#include "Pokeball.hpp"

int main(){

    std::cout << "***** POKEMON TEST *****" << std::endl;

    /*
    // Having fun with pokemon methods :

    Pokemon bulbasaur(1, "Bulbasaur", 45, 49, 49, 1);
    Pokemon charmander(4, "Charmander", 39, 52, 43, 1);
    Pokemon squirtle(1, "Squirtle", 44, 48, 65, 1);

    std::cout << "\n\n" << std::endl;


    bulbasaur.dealDmg(charmander);

    while (bulbasaur.getHP() > 0){
        charmander.dealDmg(bulbasaur);
    }
    charmander.dealDmg(bulbasaur);
    bulbasaur.dealDmg(charmander);

    bulbasaur.displayInfo();

    std::cout << "\n\n" << std::endl;
    */

    Pokedex* pokedex = Pokedex::getInstance();
    //pokedex->displayList();

    Pokemon* aaa = pokedex->getPokemonById(100);
    aaa->displayInfo();

    delete pokedex;

    return 0;
}