#include "Item.hpp"


#define Pokeball 0
#define Superball 1
#define Hyperball 2
#define Pearl 3
#define Stardust 4
#define Nugget 5
#define OranBerry 6
#define Potion 7
#define AttackPlus 8
#define Revive 9



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



vector <int> Item::use(Pokemon* pokemon){
    pokemon->setHP(50 + pokemon->getHP());
    amount--;
    totalWeight--;
    switch (itemId){
        case Pokeball:
            std::cout << "You throw a Pokeball !" <<std::endl;
            return {1, pokemon->capture(30)}; // 1 end of your turn and attempt catching with the catch rate of a pokeball
        case Superball:
            std::cout << "You throw a Superball !" <<std::endl;
            return {1, pokemon->capture(50)}; // 1 end of your turn and attempt catching with the catch rate of a superball
        case Hyperball:
            std::cout << "You throw a Hyperball !" <<std::endl;
            return {1, pokemon->capture(70)}; // 1 end of your turn and attempt catching with the catch rate of a hyperball
        case OranBerry:
            std::cout << "You use an Oran Berry on " << pokemon->getName() << " !" <<std::endl;
            pokemon->setHP(pokemon->getHP()+120);
            return {1, 0}; // 1 end of your turn and no capture
        case Potion:
            std::cout << "You use a Potion on " << pokemon->getName() << " !" <<std::endl;
            pokemon->setHP(pokemon->getHP()+200);
            return {1, 0}; // 1 end of your turn and no capture
        case Revive:
            //bring back 1 pokemon to life (use Game::revive() static method, using a Game::dyingList)
            std::cout << "You use a Revive on " << pokemon->getName() << " !" <<std::endl;
            return {1, 0}; // 1 end of your turn and no capture
        default:
            std::cout << "This item cannot be used";
    }
    return {0, 0};
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
