#include "Pokeball.hpp"
#include  <stdexcept>

Pokeball::Pokeball()
{
}

Pokemon *Pokeball::getPokemonByIndex(int index){
    if (index>0 && index <= maxId){
        for (Pokemon* pokemon : arrayOfPokemon){ //On parcourt la liste des Pokémon dans la Pokeball
            if ((arrayOfPokemon.at(index))->getId() == index){
                Pokemon* p_out = arrayOfPokemon.at(index);
                arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
                return p_out;
            }
        }
        std::cout << "You don't have such pokemon in your pokeballs !\n" << std::endl;
        return nullptr;
    }
    std::cout << "Are you on drugs ? This pokemon doesn't exist !\n" << std::endl;
    return nullptr;
}


Pokemon* Pokeball::getPokemonByName(const string& name) {
    int index = 0;
    string namecopy = stringTolower(name);
    for (int index = 0; index < arrayOfPokemon.size(); index++){ //On parcourt la liste des Pokémon dans la Pokeball
        if ((*arrayOfPokemon.at(index)).getName() == name){
            Pokemon* p_out = arrayOfPokemon.at(index);
            arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
            return p_out;
        }
    }
    std::cout << "You don't have such pokemon in your pokeballs !\n" << std::endl;
}

void Pokeball::addPokemonByIndexFromPokedex(int index)
{
}

void Pokeball::addPokemonByNameFromPokedex(const string &name)
{
}

void Pokeball::addPokemonByIndexFromPokeball(int index)
{
}

void Pokeball::addPokemonByNameFromPokeball(const string &name)
{
}

Pokeball::~Pokeball(){
    std::cout << "Closing the pokemon PC..." << std::endl;
    for (Pokemon* pokemon : arrayOfPokemon){
        delete pokemon;
    }
}

