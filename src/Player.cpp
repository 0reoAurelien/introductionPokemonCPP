#include "Player.hpp"
#include "Pokedex.hpp"


Player::Player(const string &name): username(name)
{
    Pokedex* pokedex = Pokedex::getInstance();

    Pokemon* starterPokemon = nullptr;
    vector <Pokemon*> pokemonList = {};
    for (int i; i<3; i++){
        starterPokemon = pokedex->randomWildPokemon();
        pokemonList.push_back(starterPokemon);
    }
    PokemonParty* pokemonParty = new PokemonParty(pokemonList);
}


int Player::useItem(Item *item)
{
    Pokemon* pokemon = nullptr;
    string targetName;
    if (item->getId() < 2){
        //ask for a Pokemon cible
        std::cout << "What pokemon do you want to give a " << item->getName() << " ?\n" << std::endl;
        std::cin >> targetName;
        pokemon = pokemonParty->getPokemonByName(targetName, 0);
    }
    else {
        //pokemon = Game::activeEnemy;
    }

    if (pokemon != nullptr){
        return 0;
    }
    return 0;
}


Player::~Player()
{
    delete pokemonParty;
    delete pokeball;
    delete inventory;
}