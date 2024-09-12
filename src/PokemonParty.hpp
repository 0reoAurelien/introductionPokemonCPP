#ifndef POKEBALL_HPP
#define POKEBALL_HPP

#include "SetOfPokemon.hpp"

class PokemonParty : public SetOfPokemon{ //HERITAGE

public:
    PokemonParty();
    Pokemon* getPokemonByIndex(int index); //Fonction pour obtenir un Pokémon par index et le retirer de l'équipe
    Pokemon* getPokemonByName(const string& name); //Fonction pour obtenir un Pokémon par nom et le retirer de l'équipe
    Pokemon* addPokemonByIndexFromPokedex(int index); //Fonction pour ajouter par index un Pokémon à l'équipe, depuis le pokedex
    Pokemon* addPokemonByNameFromPokedex(const string& name); //Fonction pour ajouter par nom un Pokémon à l'équipe, depuis le pokedex
    Pokemon* addPokemonByIndexFromPokeball(int index); //Fonction pour ajouter par index un Pokémon à l'équipe, depuis la pokeball
    Pokemon* addPokemonByNameFromPokeball(const string& name); //Fonction pour ajouter par nom un Pokémon à l'équipe, depuis la pokeball
    ~PokemonParty();
};

#endif