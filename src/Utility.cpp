#include "Utility.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

string stringTolower(const string& str) 
{   
    string newstr = str;
    for(int i = 0; str[i]; i++){
        newstr[i] = tolower(str[i]);
    }
    return newstr;
}

void clearFrame(){
    for (int i=0; i<50; i++)
        std::cout << "\n";
    std::cout << "\033[H\033[J" << std::endl;
}


void sortItems(vector<Item *> *liste)
{
}

void sortPokemons(vector<Pokemon *> *liste)
{
}
