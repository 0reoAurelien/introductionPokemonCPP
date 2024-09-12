
#include "SetOfPokemon.hpp"
#include <iostream>

using std::string;
using std::ifstream;

class Pokedex final : public SetOfPokemon{

private:
    Pokedex();
    Pokedex(const Pokedex&) = delete;
    Pokedex& operator=(const Pokedex&) = delete;
    static Pokedex* pokedex;
    
    Pokemon* getPokemonByName(string& name);
    Pokemon* getPokemonById(int id);

public:
    static Pokedex * getInstance();
    ~Pokedex();


    // Initialisation du pointeur statique à nullptr
};