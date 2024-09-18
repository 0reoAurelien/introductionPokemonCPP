#include "Player.hpp"
#include "Pokedex.hpp"
#include "Utility.hpp"
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
    activePokemon = nullptr;
    badges = 0;
    playerLevel=0;
}

string Player::getUsername() const
{
    return username;
}

void Player::addPokeToParty(Pokemon *pokeToAdd, int gamemode)
{
    pokemonParty->addPokemon(pokeToAdd);
    if (pokemonParty->getPartySize() > 6){

        Pokemon* pokeToRemove = nullptr;
        string targetName = "";
        while (pokeToRemove == nullptr){
            std::cout << "Your party cannot contain more than 6 pokemon.\nPlease select a pokemon to remove.\n\n" << std::endl;
            pokemonParty->displayList();
            std::cin >> targetName;
            targetName = stringTolower(targetName);
            pokeToRemove = pokemonParty->getPokemonByName(targetName);
            if (pokeToRemove == nullptr){
                clearFrame();
                std::cout << "You didn't select a valid pokemon, please try again." << std::endl;
            }
        }
        if (gamemode){ 
            removePokeFromParty(pokeToRemove); // send the pokemon back to pokeball
        }
        else{ // If the player is not in singleplayer mode, he doesn't need to send it back to pokeball
            delete pokeToRemove; // to not this instance live forever
        }
    }
}

void Player::removePokeFromParty(Pokemon *pokeToRemove){
    pokeball->addPokemon(pokeToRemove);
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
    if ((Game::gamemode == SinglePlayerMode)&&(itemId < 3)){ // the first 3 items are pokeballs to throw at the enemy
        pokemon = Game::activeEnemy;
    }

    if (pokemon == nullptr){
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