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

void waitConfirm(){
    string wait = "";
    std::cin >> wait;
}

int isValidInteger(string userInput){
    if (userInput.size() == 1){
        char integer = userInput[0];
        if ((integer == '1') || (integer == '2') || (integer == '3') || (integer == '4') || (integer == '5') || (integer == '6') || (integer == '7') || (integer == '8') || (integer == '9')){
            return 1;
        }
    }
    return 0;
}


void sortItems(vector<Item *> *liste)
{
}

void sortPokemons(vector<Pokemon *> *liste)
{
}
