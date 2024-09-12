#ifndef POKEBALL_HPP
#define POKEBALL_HPP

#include "SetOfPokemon.hpp"

class Pokeball : public SetOfPokemon{ //HERITAGE

public:
    Pokeball();
    Pokemon* getPokemonByIndex(int index); //Fonction pour obtenir un Pokémon par index et le retirer de la Pokeball
    Pokemon* getPokemonByName(const string& name); //Fonction pour obtenir un Pokémon par nom et le retirer de la Pokeball
    void addPokemonByIndexFromPokedex(int index); //Fonction pour ajouter par index un Pokémon à la pokeball, depuis le pokedex
    void addPokemonByNameFromPokedex(const string& name); //Fonction pour ajouter par nom un Pokémon à la pokeball, depuis le pokedex
    void addPokemonByIndexFromPokeball(int index); //Fonction pour ajouter par index un Pokémon à la pokeball, depuis l'équipe
    void addPokemonByNameFromPokeball(const string& name); //Fonction pour ajouter par nom un Pokémon à la pokeball, depuis l'équipe
    ~Pokeball();
};

#endif