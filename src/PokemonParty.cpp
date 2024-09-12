#include "PokemonParty.hpp"

PokemonParty::PokemonParty()
{
}

Pokemon *PokemonParty::getPokemonByIndex(int index){
    if (index>0 && index <= maxId){
        for (Pokemon* pokemon : arrayOfPokemon){ //On parcourt la liste des Pokémon dans la Pokeball
            if ((arrayOfPokemon.at(index))->getId() == index){
                Pokemon* p_out = arrayOfPokemon.at(index);
                arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
                return p_out;
            }
        }
        std::cout << "You don't have such pokemon in your team !\n" << std::endl;
        return nullptr;
    }
    std::cout << "Are you on drugs ? This pokemon doesn't exist !\n" << std::endl;
    return nullptr;
}


Pokemon* PokemonParty::getPokemonByName(const string& name) {
    int index = 0;
    string namecopy = stringTolower(name);
    for (int index = 0; index < arrayOfPokemon.size(); index++){ //On parcourt la liste des Pokémon dans la Pokeball
        if ((*arrayOfPokemon.at(index)).getName() == name){
            Pokemon* p_out = arrayOfPokemon.at(index);
            arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
            return p_out;
        }
    }
    std::cout << "You don't have such pokemon in your team !\n" << std::endl;
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