#include "PokemonParty.hpp"
#include "Pokeball.hpp"
#include "Pokedex.hpp"
#include <iostream>
#include <string>
#include <vector>
#include  <stdexcept>


Pokeball* linkedPokeball = nullptr;

PokemonParty::PokemonParty(const std::vector <std::string> &names, Pokeball* pokeball):linkedPokeball(pokeball)
{
    for (const std::string &name : names){
        if(arrayOfPokemon.size()>=6){
            std::cout << "Team is full !" << std::endl;
            break;
        }
        Pokemon* pokemon = linkedPokeball->getPokemonByName(name);
        if (pokemon != nullptr){
            arrayOfPokemon.push_back(pokemon);
        }
        else {
            std::cout << "Couldn't find " << name << std::endl;
        }
    }
}

Pokemon *PokemonParty::getPokemonById(int id){
    if (id>0 && id <= maxId){
        Pokemon* pokemon = nullptr;
        for (int index = 0; index < arrayOfPokemon.size(); ++index){ //On parcourt la liste des Pokémon dans la Pokeball
            pokemon = arrayOfPokemon.at(index);
            if (pokemon->getId() == id){
                arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
                return pokemon;
            }
        }
        std::cout << "You don't have such pokemon in your team !\n" << std::endl;
        return nullptr;
    }
    std::cout << "Are you on drugs ? This pokemon doesn't exist !\n" << std::endl;
    return nullptr;
}

Pokemon *PokemonParty::getPokemonByName(const string &name)
{
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
    std::cout << "You don't have such pokemon in your team !\n" << std::endl;
    return nullptr;
}

void PokemonParty::addPokemon(Pokemon* pokemon){
    arrayOfPokemon.push_back(pokemon);
}

PokemonParty::~PokemonParty(){
    std::cout << "Closing your pokemon party..." << std::endl;
    for (Pokemon* pokemon : arrayOfPokemon){
        delete pokemon;
    }
    std::cout << "Pokemon party successfully closed !" << std::endl;
}