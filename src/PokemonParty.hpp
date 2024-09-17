#pragma once
#include "SetOfPokemon.hpp"
#include "Pokeball.hpp"
#include <iostream>
#include <string>
#include <vector>
#include  <stdexcept>

using std::string;
using std::vector;

class PokemonParty : public SetOfPokemon{
private:
    Pokeball linkedPokeball;
public:
    PokemonParty(vector <Pokemon*> pokemonList);
    Pokemon* getPokemonById(int index); //Fonction pour obtenir un Pokémon par index et le retirer de l'équipe
    Pokemon* getPokemonByName(const string& name); //Fonction pour obtenir un Pokémon par nom et le retirer de l'équipe
    void addPokemon(Pokemon* pokemon); //Fonction pour ajouter un pokémon donné
    ~PokemonParty();
};

