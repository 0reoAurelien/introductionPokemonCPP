#include "PokemonParty.hpp"
#include "Pokeball.hpp"
#include "Pokedex.hpp"
#include "Utility.hpp"

#include <iostream>
#include <string>
#include <vector>
#include  <stdexcept>

using std::vector;
using std::string;


Pokeball* linkedPokeball = nullptr;

PokemonParty::PokemonParty()
{
}

PokemonParty::PokemonParty(vector <Pokemon*> pokemonList)
{
    for (Pokemon* pokemon : pokemonList){
        if(arrayOfPokemon.size() > 6){
            delete pokemon;
        }
        else {
            arrayOfPokemon.push_back(pokemon);

            if (arrayOfPokemon.size() == 6){
                std::cout << "Team is full !" << std::endl;
            }
        }
    }
}

string PokemonParty::getTitle(){
    return "CURRENT TEAM";
}


Pokemon *PokemonParty::getPokemonById(int id, int removeFromList){
    if (id>0 && id <= maxId){  
        int count = 0;
        Pokemon* matchingPokemon = nullptr;
        vector <Pokemon*> matchingList = {};
        vector <int> indexList = {}; 

        for (int index = 0; index < arrayOfPokemon.size(); ++index){ //On parcourt la liste des Pokémon dans la Pokeball
            matchingPokemon = arrayOfPokemon.at(index);
            if (matchingPokemon->getId() == id){
                matchingList.push_back(matchingPokemon);
                indexList.push_back(index);
                count++;
            }
        }

        Pokemon* p_out = nullptr;
        int index = 0;
        switch (count){
            case 0 :{
                std::cout << "You don't have such pokemon in your team !\n" << std::endl;
                break;
            }

            case 1 :{
                
                Pokemon* p_out = matchingList.at(0);
                index = indexList.at(0);
                if (removeFromList){
                    arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
                }
                break;
            }

            default :{

                string shinyPrefix = "";
                std::cout << "You have several " << matchingList.at(0)->getName() << ", please specify your request.\n" << std::endl;
                
                for (int i = 0; i < count; i++){
                    p_out = matchingList.at(i);
                    shinyPrefix = (p_out->isShiny())?"Shiny ":"";
                    std::cout << i+1 << " : " << shinyPrefix << p_out->getName() << " - " << p_out->getHP() << " HP" << std::endl;
                }

                string selectInput = "";
                std::cin >> selectInput;
                int specificSelection = std::stoi(selectInput) - 1;

                while (!((specificSelection>=0)&&(specificSelection<count))){
                    std::cout << "The entered value is incorrect. Please try again with a correct number.\n" << std::endl;
                    std::cin >> selectInput;
                    int specificSelection = std::stoi(selectInput) - 1;
                }

                p_out = matchingList.at(specificSelection);
                index = indexList.at(specificSelection);
                if (removeFromList){
                    arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
                }
            }
        }
        //std::cout << p_out->getName() << " was successfully moved.\n" << std::endl;
        return p_out;
    }
    std::cout << "Are you on drugs ? This pokemon doesn't exist !\n" << std::endl;
    return nullptr;
}

Pokemon *PokemonParty::getPokemonByName(const string &name, int removeFromList){
    string namecopy = stringTolower(name);
    int count = 0;
    Pokemon* matchingPokemon = nullptr;
    vector <Pokemon*> matchingList = {};
    vector <int> indexList = {}; 

    for (int index = 0; index < arrayOfPokemon.size(); ++index){ //On parcourt la liste des Pokémon dans la Pokeball
        matchingPokemon = arrayOfPokemon.at(index);
        if (matchingPokemon->getName() == namecopy){
            matchingList.push_back(matchingPokemon);
            indexList.push_back(index);
            count++;
        }
    }

    Pokemon* p_out = nullptr;
    int index = 0;
    switch (count){
        case 0 :{
            std::cout << "You don't have such pokemon in your team !\n" << std::endl;
            break;
        }

        case 1 :{
            
            Pokemon* p_out = matchingList.at(0);
            index = indexList.at(0);
            if (removeFromList){
                arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
            }
            break;
        }

        default :{

            string shinyPrefix = "";
            std::cout << "You have several " << name << ", please specify your request.\n" << std::endl;
            
            for (int i = 0; i < count; i++){
                p_out = matchingList.at(i);
                shinyPrefix = (p_out->isShiny())?"Shiny ":"";
                std::cout << i+1 << " : " << shinyPrefix << p_out->getName() << " - " << p_out->getHP() << " HP" << std::endl;
            }

            string selectInput = "";
            std::cin >> selectInput;
            int specificSelection = std::stoi(selectInput) - 1;

            while (!((specificSelection>=0)&&(specificSelection<count))){
                std::cout << "The entered value is incorrect. Please try again with a correct number.\n" << std::endl;
                std::cin >> selectInput;
                int specificSelection = std::stoi(selectInput) - 1;
            }

            p_out = matchingList.at(specificSelection);
            index = indexList.at(specificSelection);
            if (removeFromList){
                arrayOfPokemon.erase(arrayOfPokemon.begin()+index);
            }
        }
    }
    //std::cout << p_out->getName() << " was successfully moved.\n" << std::endl;
    return p_out;
}

void PokemonParty::addPokemon(Pokemon* pokemon){
    arrayOfPokemon.push_back(pokemon);
}

PokemonParty::~PokemonParty(){
    std::cout << "Closing your pokemon party..." << std::endl;
    for (Pokemon* pokemon : arrayOfPokemon){
        delete pokemon;
    }
    std::cout << "Pokemon party successfully closed !" << std::endl;
}