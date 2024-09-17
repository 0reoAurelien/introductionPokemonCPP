#include "Item.hpp"


#define Pokeball 0
#define Superball 1
#define Hyperball 2
#define OranBerry 3
#define Potion 4
#define AttackPlus 5
#define Revive 6



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
        case Superball:
            std::cout << "You throw a Superball !" <<std::endl;
            return pokemon->capture(50); // attempt catching with the catch rate of a superball
        case Hyperball:
            std::cout << "You throw a Hyperball !" <<std::endl;
            return pokemon->capture(70); // attempt catching with the catch rate of a hyperball
        case Potion:
            std::cout << "You use a Potion !" <<std::endl;
            return pokemon->capture(30); // attempt catching with the catch rate of a pokeball
        default:
            break;
    }
    return 0;
}

string Item::getName() const{
    return name;
}
int Item::getId() const
{
    return itemId;
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
