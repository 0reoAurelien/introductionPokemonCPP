

#include <iostream>
#include "Pokedex.hpp"
#include "SetOfPokemon.hpp"
#include "Pokeball.hpp"
#include "PokemonParty.hpp"
#include "Item.hpp"
#include "Inventory.hpp"
#include "Player.hpp"

int main(){

    srand(time(NULL));

    std::cout << "***** POKEMON TEST *****" << std::endl;


    Pokedex* pokedex = Pokedex::getInstance();

    
    // Having fun with pokemon methods :
/*
    Pokemon bulbasaur(1, "Bulbasaur", 45, 49, 49, 20, 1, 0);
    Pokemon charmander(4, "Charmander", 39, 52, 43, 20, 1, 0);
    Pokemon squirtle(1, "Squirtle", 44, 48, 65, 20, 1, 0);

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


    //int RNG = 1+rand()%721;
    //std::cout << "The random number is " << RNG << std::endl;
    //Pokemon* randomPokemon = pokedex->getPokemonById(RNG);
    

    Pokemon* randomPokemon = pokedex->randomWildPokemon();

    randomPokemon->displayInfo();
    randomPokemon->displayName();
*/


/*
    Pokemon* pkmn1 = pokedex->randomWildPokemon();
    Pokemon* pkmn2 = pokedex->randomWildPokemon();

    vector <Pokemon*> pokemonList = {pkmn1, pkmn2};

    PokemonParty* party = new PokemonParty(pokemonList);


    Pokemon* testPKMN = pokedex->getPokemonByName("moltres");
    Pokemon* testPKMN2 = pokedex->getPokemonByName("rayquaza");
    Pokemon* testPKMN3 = pokedex->getPokemonByName("rayquaza");

    party->addPokemon(testPKMN);
    party->addPokemon(testPKMN2);
    party->addPokemon(testPKMN3);

    Pokeball* PC = new Pokeball();

    PC->addPokemon(party->getPokemonByName("moltres"));
    PC->addPokemon(party->getPokemonByName("arceus"));
    PC->addPokemon(party->getPokemonByName("rayquaza"));

    testPKMN->displayInfo();

    party->displayList();

    party->displayListDetails();
*/

    
    Player* Aurelien = new Player("Aurelien");



    //pokedex->displayList();


    //delete pokemonParty;
    //delete pokeball;
    //delete pokedex;

    return 0;
}