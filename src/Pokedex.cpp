
#include "SetOfPokemon.hpp"
#include "Pokedex.hpp"
#include "Utility.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#define SHINY_ODDS 800

using std::string;
using std::vector;



Pokedex::Pokedex():SetOfPokemon(){
    srand(time(NULL));
    std::cout << "Updating your pokedex...\n" << std::endl;
    const string fileName = "../resources/pokedex.csv";
    std::ifstream db(fileName); // Ouvre le fichier
    if (!db.is_open()) { // Vérifie si le fichier est bien ouvert
        std::cerr << "Couldn't open file : " << fileName << std::endl;
        return;
    }
    string line;
    std::getline(db, line);
    while (std::getline(db, line)) { // Lit le fichier ligne par ligne
        std::stringstream ss(line); // Utilise un flux pour diviser la ligne
        string cellule;
        vector<string> lineData;
        // Divise la ligne en cellules séparées par des virgules
        
        while (std::getline(ss, cellule, ',')) {
            lineData.push_back(cellule);
        }
        
        const auto& id = std::stoi(lineData.at(0));
        const auto& name = stringTolower(lineData.at(1));
        const auto& hitpoints = std::stoi(lineData.at(5));
        const auto& attack = std::stoi(lineData.at(6));
        const auto& defense = std::stoi(lineData.at(7));
        const auto& speed = std::stoi(lineData.at(10));
        const auto& generation = std::stoi(lineData.at(11));
        const auto& legendary = ((stringTolower(lineData.at(12)))[0]=='t')? 1:0;

        Pokemon* newPokemon = new Pokemon(id, name, hitpoints, attack, defense, speed, generation, legendary);
        arrayOfPokemon.push_back(newPokemon);
        maxId = (maxId < newPokemon->getId())? newPokemon->getId() : maxId;


        //debugPoke -> displayInfo();
        
    }
    std::cout << "There are now " << Pokemon::count << " pokemons in the universe.\n" << std::endl;
    std::cout << "\nYour pokedex was successfully updated !\n" << std::endl;
    //std::cout << "The maximum ID is " << maxId << std::endl;

    db.close(); // Ferme le fichier
}

Pokedex* Pokedex::pokedex = nullptr;


string Pokedex::getTitle()
{
    return "POKEDEX";
}


Pokedex* Pokedex::getInstance() {
    if (pokedex == nullptr){
        pokedex = new Pokedex();
    }
    return pokedex;
}


Pokemon* Pokedex::getPokemonById(const int id, int removeFromList) {
    int isShiny = (SHINY_ODDS > rand()%8192);
    if (id>0 && id <= maxId){
        for (Pokemon* pokemon : arrayOfPokemon){ //On parcourt la liste des Pokémon dans la Pokeball
            if (pokemon->getId() == id){
                Pokemon* p = new Pokemon(*pokemon, isShiny);
                return p;
            }
        }
    }
    std::cout << "Are you on drugs ? This pokemon doesn't exist !\n" << std::endl;
    return nullptr;
}


Pokemon* Pokedex::getPokemonByName(const string& name, int removeFromList) {
    int isShiny = (SHINY_ODDS > rand()%8192);
    string namecopy = stringTolower(name);
    for (Pokemon* pokemon : arrayOfPokemon){ //On parcourt la liste des Pokémon dans la Pokeball
        if (pokemon->getName() == namecopy){
            Pokemon* p = new Pokemon(*pokemon, isShiny);
            return p;
        }
    }
    std::cout << "Are you on drugs ? This pokemon doesn't exist !" << std::endl;
    return nullptr;
}


Pokemon *Pokedex::randomWildPokemon(int allowLegendary, string type1, string type2, string type3, int forceLegendary){
    int id = 1+rand()%maxId;
    Pokemon* pokemon = getPokemonById(id);
    // I'll write a new method later to manage the possible types
    // and prevent the creation of legendary pokemon when it's not allowed
    return pokemon;
}


Pokedex::~Pokedex(){
    std::cout << "Closing the pokedex..." << std::endl;
    for (Pokemon* pokemon : arrayOfPokemon){
        delete pokemon;
    }
    std::cout << "Pokedex successfully closed !" << std::endl;
}
