#include "Player.hpp"
#include "Pokedex.hpp"


Player::Player(const string &name): username(name)
{
    Pokedex* pokedex = Pokedex::getInstance();

    Pokemon* starterPokemon = pokedex->randomWildPokemon();
    Pokemon* ptrBackup = nullptr;
    vector <Pokemon*> pokemonList = {};
    for (int i; i<3; i++){
        while (starterPokemon->isLegendary()){
            ptrBackup = starterPokemon;
            starterPokemon = pokedex->randomWildPokemon();
            delete ptrBackup;
        }
        pokemonList.push_back(starterPokemon);
    }
    PokemonParty* pokemonParty = new PokemonParty({starterPokemon});
}


int Player::useItem(Item *item)
{
    Pokemon* pokemon = nullptr;
    string targetName;
    if (item->getId() < 2){
        //ask for a Pokemon cible
        while (pokemon == nullptr){
            std::cout << "What pokemon do you want to give a " << item->getName() << " ?\n" << std::endl;
            std::cin >> targetName;
            pokemon = pokemonParty->getPokemonByName(targetName);
        }
    }
    else {
        //pokemon = Game::activeEnemy;
    }
    return 0;
}


Player::~Player()
{
    delete pokemonParty;
    delete pokeball;
    delete inventory;
}