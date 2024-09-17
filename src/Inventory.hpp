#pragma once

#include "Pokemon.hpp"
#include "Item.hpp"
#include <iostream>
#include <vector>

using std::vector;

class Inventory {

protected:
    vector<Item*> arrayOfItem;
public:
    int balance;
    Item* findItem(const string& name);
    void addItem(int itemId);
    int useItem(Item* item, Pokemon* pokemon);
    void sellItem(Item* item);
    string stringTolower(const string& str);

    void displayList();
};