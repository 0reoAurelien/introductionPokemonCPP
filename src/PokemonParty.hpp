
#include "SetOfPokemon.hpp"

class PokemonParty : public SetOfPokemon{

public:
    PokemonParty();
    Pokemon* getPokemonByIndex(int index); //Fonction pour obtenir un Pokémon par index et le retirer de l'équipe
    Pokemon* getPokemonByName(const string& name); //Fonction pour obtenir un Pokémon par nom et le retirer de l'équipe
    void addPokemon(Pokemon* pokemon); //Fonction pour ajouter un pokémon donné
    ~PokemonParty();
};

