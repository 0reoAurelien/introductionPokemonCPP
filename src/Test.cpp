

#include <iostream>
#include "Pokedex.hpp"
#include "SetOfPokemon.hpp"
#include "Pokeball.hpp"
#include "PokemonParty.hpp"

int main(){

    srand(time(NULL));

    std::cout << "***** POKEMON TEST *****" << std::endl;


    Pokedex* pokedex = Pokedex::getInstance();

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

    Pokemon* ghost = pokedex->getPokemonByName("hAuNTer");


    int RNG = 1+rand()%721;
    std::cout << "The random number is " << RNG << std::endl;
    //Pokemon* randomPokemon = pokedex->getPokemonById(RNG);
    */

    Pokemon* randomPokemon = pokedex->randomWildPokemon();

    randomPokemon->displayInfo();
    randomPokemon->displayName();

    Pokemon* pkmn1 = pokedex->randomWildPokemon();
    Pokemon* pkmn2 = pokedex->randomWildPokemon();
    Pokemon* pkmn3 = pokedex->randomWildPokemon();

    vector <Pokemon*> pokemonList = {pkmn1, pkmn2, pkmn3};

    PokemonParty* party = new PokemonParty(pokemonList);

    //pokedex->displayList();


    //delete pokemonParty;
    //delete pokeball;
    //delete pokedex;

    Pokemon* testPKMN = pokedex->getPokemonByName("moltres");
    testPKMN->displayInfo();
    return 0;
}