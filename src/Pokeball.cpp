#include "Pokeball.hpp"
#include  <stdexcept>

#include "Pokedex.hpp"
#include "PokemonParty.hpp"

Pokeball::Pokeball()
{
}

Pokemon *Pokeball::getPokemonById(int id){
    if (id>0 && id <= maxId){
        for (int index = 0; index < arrayOfPokemon.size(); ++index){ //On parcourt la liste des Pokémon dans la Pokeball
            Pokemon* pokemon = arrayOfPokemon.at(index);
            if (pokemon->getId() == id){
                arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
                return pokemon;
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
    for (int index = 0; index < arrayOfPokemon.size(); ++index){ //On parcourt la liste des Pokémon dans la Pokeball
        if ((*arrayOfPokemon.at(index)).getName() == namecopy){
            Pokemon* p_out = arrayOfPokemon.at(index);
            arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
            return p_out;
        }
    }
    std::cout << "You don't have such pokemon in your pokeballs !\n" << std::endl;
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

