#include "Player.hpp"
#include "Pokedex.hpp"
#include "Game.hpp"


Player::Player(const string &name): username(name)
{
    Pokedex* pokedex = Pokedex::getInstance();

    Pokemon* starterPokemon = nullptr;
    vector <Pokemon*> pokemonList = {};
    for (int i; i<3; i++){
        starterPokemon = pokedex->randomWildPokemon(0);
        pokemonList.push_back(starterPokemon);
    }
    pokemonParty = new PokemonParty(pokemonList);
    dyingPokemons = new PokemonParty();
}


vector <int> Player::useItem(Item *item)
{
    Pokemon* pokemon = nullptr;
    string targetName;

    int itemId = item->getId();
    if (itemId > 6){ //  the first 6 items are not self applicable
        //ask for a Pokemon cible
        std::cout << "What pokemon do you want to give a " << item->getName() << " ?\n" << std::endl;
        std::cin >> targetName;
        pokemon = pokemonParty->getPokemonByName(targetName, 0);
    }
    if ((Game::gamemode == SinglePlayer)&&(itemId < 3)){ // the first 3 items are pokeballs to throw at the enemy
        pokemon = Game::activeEnemy;
    }

    if (pokemon != nullptr){
        std::cout << "This action couldn't be performed.\n" << std::endl;
        return {0, 0};
    }
    
    return inventory->useItem(item, pokemon);
}


Player::~Player()
{
    delete pokemonParty;
    delete pokeball;
    delete inventory;
}