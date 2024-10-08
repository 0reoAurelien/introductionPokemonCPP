#pragma once

#include "SetOfPokemon.hpp"

class Pokeball : public SetOfPokemon{ //HERITAGE

public:
    Pokeball();
    string getTitle() override;
    Pokemon* getPokemonById(int id, int removeFromList = 1) override; //Fonction pour obtenir un Pokémon par index et le retirer de la Pokeball
    Pokemon* getPokemonByName(const string& name, int removeFromList = 1) override; //Fonction pour obtenir un Pokémon par nom et le retirer de la Pokeball
    void addPokemon(Pokemon* pokemon); //Fonction pour ajouter un pokémon donné
    ~Pokeball();
};
