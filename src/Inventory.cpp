#include "Inventory.hpp"
#include "Item.hpp"
#include "Pokemon.hpp"
#include "Utility.hpp"

#include <iostream>


Item *Inventory::findItem(const string &name)
{
    return nullptr;
}

void Inventory::addItem(int itemId){
    arrayOfItem.push_back(Item::getInstance(itemId));
    sortItems(&arrayOfItem);
}

vector <int> Inventory::useItem(Item *item, Pokemon* pokemon)
{
    vector <int> endTurnAndisCaptured = item->use(pokemon);
    if (!(item->amount)){
        delete item;
    }
    return endTurnAndisCaptured;
}

void Inventory::sellItem(Item *item)
{
}

string Inventory::stringTolower(const string &str)
{
    return string();
}

void Inventory::displayList(){

    std::cout << "***** Inventory *****\n" << std::endl;

    for (Item* item : arrayOfItem) {
        item->displayItem();
    }
}

Inventory::~Inventory()
{
    for (Item* item : arrayOfItem){
        delete item;
    }
}
