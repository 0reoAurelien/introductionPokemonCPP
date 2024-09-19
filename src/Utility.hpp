#pragma once


#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.hpp"
#include "Item.hpp"

using std::string;
using std::vector;


string stringTolower(const string& str);
void clearFrame();
void waitConfirm();
int isValidInteger(string);

void sortItems(vector <Item*> *liste);
void sortPokemons(vector <Pokemon*> *liste);

