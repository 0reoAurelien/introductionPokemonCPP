#ifndef POKEBALL_HPP
#define POKEBALL_HPP

#include "SetOfPokemon.hpp"

class Pokeball : public SetOfPokemon{ //HERITAGE

    public:
        Pokeball(){};
        Pokemon* getPokemonByIndex(int index); //Fonction pour obtenir un Pokémon par index et le retirer de la Pokeball
        Pokemon* getPokemonByName(const string& name); //Fonction pour obtenir un Pokémon par nom et le retirer de la Pokeball
};

#endif