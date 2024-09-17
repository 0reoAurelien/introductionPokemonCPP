

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

    Pokeball* pokeball = new Pokeball();
    vector <string> names = {"charmander", "squirtle", "mew", "ditto", "pichu", "riolu", "alakazam"};

    for (string &name : names){
        pokeball->addPokemon(pokedex->getPokemonByName(name));
    }

    PokemonParty* party = new PokemonParty(names, pokeball);

    //pokedex->displayList();


    //delete pokemonParty;
    //delete pokeball;
    //delete pokedex;

    Pokemon* testPKMN = pokedex->getPokemonByName("moltres");
    testPKMN->displayInfo();
    return 0;
}