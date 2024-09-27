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
public:
    int alive;
    PokemonParty(bool areAlive = 1);
    PokemonParty(vector <Pokemon*> pokemonList);
    string getTitle() override;
    Pokemon *getPokemonById(int index, int removeFromList = 1);            // Fonction pour obtenir un Pokémon par index et le retirer de l'équipe
    Pokemon* getPokemonByName(const string& name, int removeFromList = 1); //Fonction pour obtenir un Pokémon par nom et le retirer de l'équipe
    void addPokemon(Pokemon* pokemon); //Fonction pour ajouter un pokémon donné
    void empty();
    ~PokemonParty();
};

