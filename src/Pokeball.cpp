#include "Pokeball.hpp"
#include  <stdexcept>


Pokemon* Pokeball::getPokemonByIndex(int index) {
    if (index>=0 && index < arrayOfPokemon.size()){
        Pokemon* p_out = arrayOfPokemon.at(index);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
        return p_out;
    }
    std::cout << "You don't own that many pokemons" << std::endl; 
}

Pokemon* Pokeball::getPokemonByName(const std::string& name) {
    int index = 0;
    for (int index = 0; index < arrayOfPokemon.size(); index++){ //On parcourt la liste des Pokémon dans la Pokeball
        if ((*arrayOfPokemon.at(index)).getName() == name){
            Pokemon* p_out = arrayOfPokemon.at(index);
            arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
            return p_out;
        }
    }
    std::cout << "You don't have such pokemon in your pokeballs !" << std::endl;
}