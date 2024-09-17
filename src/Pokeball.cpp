#include "Pokeball.hpp"
#include  <stdexcept>

#include "Pokedex.hpp"
#include "PokemonParty.hpp"
#include "Utility.hpp"

Pokeball::Pokeball()
{
    title = "POKEMON PC";
}

Pokemon *Pokeball::getPokemonById(int id){
    if (id>0 && id <= maxId){
        Pokemon* p_out = nullptr;
        for (int index = 0; index < arrayOfPokemon.size(); ++index){ //On parcourt la liste des Pokémon dans la Pokeball
            p_out = arrayOfPokemon.at(index);
            if (p_out->getId() == id){
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
    Pokemon* p_out = nullptr;
    for (int index = 0; index < arrayOfPokemon.size(); ++index){ //On parcourt la liste des Pokémon dans la Pokeball
        p_out = arrayOfPokemon.at(index);
        if (p_out->getName() == namecopy){
            arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
            return p_out;
        }
    }
    std::cout << "You don't have such pokemon in your pokeballs !\n" << std::endl;
    return nullptr;
}

void Pokeball::addPokemon(Pokemon* pokemon)
{
    arrayOfPokemon.push_back(pokemon);
}

Pokeball::~Pokeball(){
    std::cout << "Closing the pokemon PC..." << std::endl;
    for (Pokemon* pokemon : arrayOfPokemon){
        delete pokemon;
    }
}

