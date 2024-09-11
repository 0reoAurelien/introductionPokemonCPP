
#include "SetOfPokemon.hpp"
#include "Pokedex.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::vector;


Pokedex::Pokedex():SetOfPokemon(){
    std::cout << "Updating your pokedex...\n" << std::endl;
    const string fileName = "../resources/pokedex.csv";
    std::ifstream db(fileName); // Ouvre le fichier
    if (!db.is_open()) { // Vérifie si le fichier est bien ouvert
        std::cerr << "Impossible d'ouvrir le fichier : " << fileName << std::endl;
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
        const auto& name = lineData.at(1);
        const auto& hitpoints = std::stoi(lineData.at(5));
        const auto& attack = std::stoi(lineData.at(6));
        const auto& defense = std::stoi(lineData.at(7));
        const auto& generation = std::stoi(lineData.at(11));

        Pokemon* debugPoke = new Pokemon(id, name, hitpoints, attack, defense, generation);
        arrayOfPokemon.push_back(debugPoke);

        //debugPoke -> displayInfo();
        
    }
    
    std::cout << "\nYour pokedex was successfully updated !\n" << std::endl;
    db.close(); // Ferme le fichier
}

Pokedex* Pokedex::pokedex = nullptr;

Pokedex* Pokedex::getInstance() {
    if (pokedex == nullptr){
        pokedex = new Pokedex();
    }
    return pokedex;
}


Pokemon* Pokedex::getPokemonByName(string name) /*override*/ {
    return nullptr;
}

Pokemon* Pokedex::getPokemonById(int id){
    return nullptr;
};

Pokedex::~Pokedex(){}
