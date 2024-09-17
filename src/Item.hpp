#pragma once

#include "Pokemon.hpp"
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;


class Item {

protected:
    Item(int Id);
    static vector <Item*> itemInstanceList;
    string name;
    int itemId;

public:
    static int totalWeight;
    int amount;

    int use(Pokemon* Pokemon); //a switch case defines the use of each item
    // and the method returns 1 if it resulted in the capture of the pokemon
    string getName() const;
    void displayItem();
    void showInfo(); //should be defined for each item, but Ill see that later

    static Item* getInstance(int itemId);

    ~Item();
};