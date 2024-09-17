#include "Pokeball.hpp"
#include  <stdexcept>

#include "Pokedex.hpp"
#include "PokemonParty.hpp"
#include "Utility.hpp"

Pokeball::Pokeball()
{
    title = "POKEMON PC";
}

Pokemon *Pokeball::getPokemonById(int id, int removeFromList){
    if (id>0 && id <= maxId){  
        int count = 0;
        Pokemon* matchingPokemon = nullptr;
        vector <Pokemon*> matchingList = {};
        vector <int> indexList = {}; 

        for (int index = 0; index < arrayOfPokemon.size(); ++index){ //On parcourt la liste des Pokémon dans le PC
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
                std::cout << "You don't have such pokemon in your PC !\n" << std::endl;
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


Pokemon *Pokeball::getPokemonByName(const string &name, int removeFromList){
    string namecopy = stringTolower(name);
    int count = 0;
    Pokemon* matchingPokemon = nullptr;
    vector <Pokemon*> matchingList = {};
    vector <int> indexList = {}; 

    for (int index = 0; index < arrayOfPokemon.size(); ++index){ //On parcourt la liste des Pokémon dans le PC
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
            std::cout << "You don't have such pokemon in your PC !\n" << std::endl;
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


void Pokeball::addPokemon(Pokemon* pokemon)
{
    arrayOfPokemon.push_back(pokemon);
}

Pokeball::~Pokeball(){
    std::cout << "Closing the pokemon PC..." << std::endl;
    for (Pokemon* pokemon : arrayOfPokemon){
        delete pokemon;
    }
}

