#include "Item.hpp"


#define Pokeball 0
#define Superball 0
#define Hyperball 0
#define OranBerry 1
#define Potion 2
#define Revive 3



vector <Item*> Item::itemInstanceList = {};
int Item::totalWeight=0;


Item::Item(int Id):
itemId(Id){
}

Item *Item::getInstance(int Id)
{
    Item* itemInstance = nullptr;

    for (Item* itemInstance : itemInstanceList){
        if (itemInstance->itemId == Id){
            itemInstance->amount++;
            Item::totalWeight++;
            return itemInstance;
        }
    }
    itemInstance = new Item(Id);
    itemInstance->amount++;
    Item::totalWeight++;
    itemInstanceList.push_back(itemInstance);
    return itemInstance;
}



int Item::use(Pokemon* pokemon){
    pokemon->setHP(50 + pokemon->getHP());
    amount--;
    totalWeight--;
    switch (itemId){
        case Pokeball:
            std::cout << "You throw a Pokeball !" <<std::endl;
            return pokemon->capture(30); // attempt catching with the catch rate of a pokeball
    }
}

void Item::displayItem()
{
    std::cout << getName() + " x" << amount << std::endl;
}

void Item::showInfo()
{
}
//should not be defined here, but in the specific item class


Item::~Item()
{
}
