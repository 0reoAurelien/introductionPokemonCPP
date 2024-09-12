
#include "SetOfPokemon.hpp"
#include "Pokedex.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

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
        const auto& generation = std::stoi(lineData.at(11));

        Pokemon* newPokemon = new Pokemon(id, name, hitpoints, attack, defense, generation);
        arrayOfPokemon.push_back(newPokemon);
        maxId = (maxId < newPokemon->getId())? newPokemon->getId() : maxId;


        //debugPoke -> displayInfo();
        
    }
    
    std::cout << "\nYour pokedex was successfully updated !\n" << std::endl;
    //std::cout << "The maximum ID is " << maxId << std::endl;

    db.close(); // Ferme le fichier
}

Pokedex* Pokedex::pokedex = nullptr;

Pokedex* Pokedex::getInstance() {
    if (pokedex == nullptr){
        pokedex = new Pokedex();
    }
    return pokedex;
}


Pokemon* Pokedex::getPokemonById(const int id) {
    if (id>0 && id <= maxId){
        for (Pokemon* pokemon : arrayOfPokemon){ //On parcourt la liste des Pokémon dans la Pokeball
            if (pokemon->getId() == id){
                Pokemon* p = new Pokemon(*pokemon);
                return p;
            }
        }
    }
    std::cout << "Are you on drugs ? This pokemon doesn't exist !\n" << std::endl;
    return nullptr;
}


Pokemon* Pokedex::getPokemonByName(const string& name) {
    string namecopy = stringTolower(name);
    for (Pokemon* pokemon : arrayOfPokemon){ //On parcourt la liste des Pokémon dans la Pokeball
        if (pokemon->getName() == namecopy){
            Pokemon* p = new Pokemon(*pokemon);
            return p;
        }
    }
    std::cout << "Are you on drugs ? This pokemon doesn't exist !" << std::endl;
    return nullptr;
}

Pokedex::~Pokedex(){
    std::cout << "Closing the pokedex..." << std::endl;
    for (Pokemon* pokemon : arrayOfPokemon){
        delete pokemon;
    }
    std::cout << "Pokedex successfully closed !" << std::endl;
}


Pokemon *Pokedex::randomWildPokemon(){
    int id = 1+rand()%maxId;
    for (Pokemon* pokemon : arrayOfPokemon){ //On parcourt la liste des Pokémon dans la Pokeball
        if (pokemon->getId() == id){
            return pokemon;
        }
    }
    return nullptr;
}