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

void sortItems(vector<Item *> *liste)
{
}

void sortPokemons(vector<Pokemon *> *liste)
{
}
